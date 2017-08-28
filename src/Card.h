#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <array>
#include <SFML/Graphics.hpp>

class Card: public sf::Drawable {
public:
    enum Ranks {
        kRankAce,
        kRank2,
        kRank3,
        kRank4,
        kRank5,
        kRank6,
        kRank7,
        kRank8,
        kRank9,
        kRank10,
        kRankJack,
        kRankQueen,
        kRankKing,
    };
    enum Suits {
        kSuitClubs,
        kSuitDiamonds,
        kSuitSpades,
        kSuitHearts,
    };

    Card(Ranks rank, Suits suit, const sf::Texture &texture, sf::IntRect int_rect,
         sf::Vector2f scale);
    int GetValue() const;
    void SetPosition(float x, float y);

private:
    sf::Sprite sprite_;
    Ranks rank_;
    Suits suits_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //BLACKJACK_CARD_H
