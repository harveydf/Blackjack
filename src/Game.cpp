#include "Game.h"

Game::Game(int screen_width, int screen_height, std::string title)
    : screen_width_(screen_width), screen_height_(screen_height) {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window_.create(sf::VideoMode(static_cast<unsigned int>(screen_width_),
                                 static_cast<unsigned int>(screen_height_),
                                 desktop.bitsPerPixel),
                   title);

    assets_manager_.LoadTexture("background", "../table.jpg");
    assets_manager_.LoadTexture("cards", "../cards.png");
    assets_manager_.LoadFont("press_start", "../PressStart2P.ttf");

    ui_manager_.SetBackground(assets_manager_.GetTexture("background"));
    ui_manager_.SetFont(assets_manager_.GetFont("press_start"));

    const int kLeftOffset {2};
    const int kTopOffset {30};
    const int kBottomOffset {deck_.GetCardSize().y + 9};

    ui_manager_.SetDealerTitlePosition(kDealerInitialPosition_.x + kLeftOffset,
                                       kDealerInitialPosition_.y - kTopOffset);
    ui_manager_.SetDealerScorePosition(kDealerInitialPosition_.x + kLeftOffset,
                                      kDealerInitialPosition_.y + kBottomOffset);

    ui_manager_.SetPlayerTitlePosition(kPlayerInitialPosition_.x + kLeftOffset,
                                       kPlayerInitialPosition_.y - kTopOffset);
    ui_manager_.SetPlayerScorePosition(kPlayerInitialPosition_.x + kLeftOffset,
                                      kPlayerInitialPosition_.y + kBottomOffset);

    deck_.Initialize(assets_manager_.GetTexture("cards"));
    Reset();
}

void Game::Run() {
    sf::Event event{};

    while (window_.isOpen()) {
        while (window_.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window_.close();
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Escape)
                        window_.close();

                    if (event.key.code == sf::Keyboard::R)
                        Reset();

                    if (event.key.code == sf::Keyboard::H && turn_ == kTurnPlayer && state_ == kStatePlaying)
                        DealPlayerCard();

                    if (event.key.code == sf::Keyboard::S && turn_ == kTurnPlayer && state_ == kStatePlaying)
                        turn_ = kTurnDealer;
                    break;
                default:
                    break;
            }
        }

        IsPlaying();

        if (should_draw_) {
            window_.clear();
            window_.draw(*this);
            window_.display();
            should_draw_ = false;
        }
    }
}

sf::Vector2f Game::GetDealerPosition() const {
    return {kDealerInitialPosition_.x + (dealer_cards_.size() * deck_.GetCardSize().x),
            kDealerInitialPosition_.y};
}

void Game::DealDealerCard() {
    Card *card = deck_.DealCard(GetDealerPosition());
    const int value = card->GetValue();

    if (value == 11)
        dealer_aces_++;

    UpdateDealerScore(value);
    dealer_cards_.push_back(card);
}

void Game::UpdateDealerScore(int score) {
    dealer_score_ += score;
    ui_manager_.SetDealerScore(std::to_string(dealer_score_));
    should_draw_ = true;
}

sf::Vector2f Game::GetPlayerPosition() const {
    return {kPlayerInitialPosition_.x + (player_cards_.size() * deck_.GetCardSize().x),
            kPlayerInitialPosition_.y};
}

void Game::DealPlayerCard() {
    Card *card = deck_.DealCard(GetPlayerPosition());
    const int value = card->GetValue();

    if (value == 11)
        player_aces_++;

    UpdatePlayerScore(value);
    player_cards_.push_back(card);
}

void Game::UpdatePlayerScore(const int score) {
    player_score_ += score;
    ui_manager_.SetPlayerScore(std::to_string(player_score_));
    should_draw_ = true;
}

void Game::Reset() {
    deck_.Shuffle();
    dealer_score_ = 0;
    dealer_aces_ = 0;
    dealer_cards_.clear();

    player_score_ = 0;
    player_aces_ = 0;
    player_cards_.clear();

    DealDealerCard();
    DealPlayerCard();
    DealPlayerCard();

    turn_ = kTurnPlayer;
    state_ = kStatePlaying;
    ui_manager_.SetResultText("");
}

void Game::IsPlaying() {
    if (player_score_ > 21 && state_ == kStatePlaying) {
        if (player_aces_ == 0)
            Finish();
        else {
            UpdatePlayerScore(-10);
            player_aces_--;
        }
    }

    if (turn_ == kTurnDealer && state_ == kStatePlaying) {
        if (dealer_score_ < 17 && dealer_score_ < player_score_) {
            DealDealerCard();
        } else {
            if (dealer_aces_ == 0)
                Finish();
            else {
                UpdateDealerScore(-10);
                dealer_aces_--;
            }
        }
    }
}

void Game::Finish() {
    state_ = kStateFinished;
    should_draw_ = true;

    if (state_ == kStateFinished) {
        if (player_score_ > 21) {
            ui_manager_.SetResultText("LOSE!");
        }
        else if (dealer_score_ > 21) {
            ui_manager_.SetResultText("WIN!");
        }
        else {
            player_score_ > dealer_score_ ? ui_manager_.SetResultText("WIN!")
                                          : ui_manager_.SetResultText("LOSE!");
        }
    }
}


void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(ui_manager_, states);

    for(const auto dc: dealer_cards_)
        target.draw(*dc);

    for(const auto pc: player_cards_)
        target.draw(*pc);
}
