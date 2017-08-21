#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <iostream>
#include <array>
#include <random>
#include <cassert>
#include "Card.h"

class Deck {
private:
    std::array<Card, 52> m_deck;
    int m_cardIndex;

    static void swapCard(Card &a, Card &b);
    static int getRandomNumber(int min, int max);

public:
    Deck();
    void printDeck();
    void shuffleDeck();
    const Card &dealCard();
};


#endif //BLACKJACK_DECK_H
