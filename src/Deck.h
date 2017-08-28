#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <random>
#include <vector>
#include <iostream>
#include "Card.h"

class Deck {
public:
    Deck();
    void Initialize(sf::Texture &card_texture);
    Card *DealCard(sf::Vector2f position);
    sf::Vector2i GetCardSize() const;
    void Shuffle();

private:
    const sf::Vector2i kCardSize{34, 48};
    const int kLeftOffset = 2;
    const std::array<int, 4> kTopOffset{81, 181, 282, 383};
    const sf::Vector2f kScale{2.0f, 2.0f};

    std::vector<Card> cards_;
    int card_index_{0};

    void SwapCards(Card &a, Card &b);
    int GetRandomNumber(int min, int max);
};


#endif //BLACKJACK_DECK_H
