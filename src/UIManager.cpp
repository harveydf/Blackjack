#include "UIManager.h"

UIManager::UIManager() {
    hint_.setString("(h): to hit\n(s): to stand");
    hint_.setPosition(0, 565);

    controls_.setString("(esc): to exit\n(r): to restart");
    controls_.setPosition(555, 565);

    result_.setString("");
    result_.setPosition(310, 300);
    result_.setFillColor(sf::Color(255, 200, 50));

    dealer_title_.setString("Dealer");
    player_title_.setString("Player");
};

void UIManager::SetFont(const sf::Font &font) {
    hint_.setFont(font);
    hint_.setCharacterSize(static_cast<unsigned int>(kFontSize_ / 1.5));

    controls_.setFont(font);
    controls_.setCharacterSize(static_cast<unsigned int>(kFontSize_ / 1.5));

    result_.setFont(font);
    result_.setCharacterSize(static_cast<unsigned int>(kFontSize_ * 1.5));

    dealer_title_.setFont(font);
    dealer_title_.setCharacterSize(kFontSize_);

    dealer_score_.setFont(font);
    dealer_title_.setCharacterSize(kFontSize_);

    player_title_.setFont(font);
    player_title_.setCharacterSize(kFontSize_);

    player_score_.setFont(font);
    player_score_.setCharacterSize(kFontSize_);
}

void UIManager::SetDealerScore(const std::string &score) {
    dealer_score_.setString(score);
}

void UIManager::SetDealerTitlePosition(float x, float y) {
    dealer_title_.setPosition(x, y);
}

void UIManager::SetDealerScorePosition(float x, float y) {
    dealer_score_.setPosition(x, y);
}

void UIManager::SetPlayerScore(const std::string &score) {
    player_score_.setString(score);
}

void UIManager::SetPlayerTitlePosition(float x, float y) {
    player_title_.setPosition(x, y);
}

void UIManager::SetPlayerScorePosition(float x, float y) {
    player_score_.setPosition(x, y);
}

void UIManager::SetBackground(const sf::Texture &texture) {
    background_.setTexture(texture);
}

void UIManager::SetResultText(const std::string &result) {
    result_.setString(result);
}

void UIManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background_, states);
    target.draw(result_, states);

    target.draw(hint_, states);
    target.draw(controls_, states);

    target.draw(dealer_title_, states);
    target.draw(dealer_score_, states);

    target.draw(player_title_, states);
    target.draw(player_score_, states);
}
