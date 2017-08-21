#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>

class Card {
public:
    enum CardRank {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        MAX_RANKS,
    };
    enum CardSuit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES,
        MAX_SUITS,
    };

private:
    CardRank m_rank;
    CardSuit m_suit;

public:
    explicit Card(CardRank rank=RANK_ACE, CardSuit suit=HEARTS);
    int getValue() const;
    void print() const;
};


#endif //BLACKJACK_CARD_H
