#ifndef BLACKJACK_UIMANAGER_H
#define BLACKJACK_UIMANAGER_H

#include <SFML/Graphics.hpp>

class UIManager: public sf::Drawable {
public:
    UIManager();
    void SetFont(const sf::Font &font);
    void SetBackground(const sf::Texture &texture);
    void SetResultText(const std::string &result);

    void SetDealerScore(const std::string &score);
    void SetDealerTitlePosition(float x, float y);
    void SetDealerScorePosition(float x, float y);

    void SetPlayerScore(const std::string &score);
    void SetPlayerTitlePosition(float x, float y);
    void SetPlayerScorePosition(float x, float y);

private:
    sf::Sprite background_;

    sf::Text player_title_;
    sf::Text player_score_;

    sf::Text dealer_title_;
    sf::Text dealer_score_;

    sf::Text hint_;
    sf::Text controls_;
    sf::Text result_;

    const unsigned int kFontSize_ = 24;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //BLACKJACK_UIMANAGER_H
