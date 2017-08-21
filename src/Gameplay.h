#ifndef BLACKJACK_GAMEPLAY_H
#define BLACKJACK_GAMEPLAY_H

#include "Deck.h"

class Gameplay {
private:
    Deck m_deck;
    enum Result {
        WIN,
        LOSE,
        DRAW,
    };
    char getPlayerChoice();
    Result play();

public:
    Gameplay();
    void start();
};


#endif //BLACKJACK_GAMEPLAY_H
