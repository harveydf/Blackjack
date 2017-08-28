#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Deck.h"
#include "UIManager.h"


class Game: public sf::Drawable {
public:
    Game(int screen_width, int screen_height, std::string title);
    void Run();

private:
    enum Turn {
        kTurnPlayer,
        kTurnDealer,
    };
    Turn turn_;

    enum State {
        kStatePlaying,
        kStateFinished,
    };
    State state_;

    sf::RenderWindow window_;
    int screen_width_;
    int screen_height_;
    bool should_draw_ {true};

    AssetsManager assets_manager_;
    UIManager ui_manager_;

    Deck deck_;

    int dealer_score_ {0};
    int dealer_aces_ {0};
    std::vector<Card *> dealer_cards_;
    const sf::Vector2f kDealerInitialPosition_{310.0, 100.0};
    sf::Vector2f GetDealerPosition() const;
    void DealDealerCard();
    void UpdateDealerScore(int score);

    int player_score_ {0};
    int player_aces_ {0};
    std::vector<Card *> player_cards_;
    const sf::Vector2f kPlayerInitialPosition_{310.0, 428.0};
    sf::Vector2f GetPlayerPosition() const;
    void DealPlayerCard();
    void UpdatePlayerScore(int score);

    void Reset();
    void IsPlaying();
    void Finish();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //BLACKJACK_GAME_H
