#include "Deck.h"

Deck::Deck()  {
    m_cardIndex = 0;
    int card = 0;
    for (int rank = 0; rank < Card::MAX_RANKS; rank++) {
        for (int suit = 0; suit < Card::MAX_SUITS; suit++) {
            m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
            card++;
        }
    }
}

void Deck::swapCard(Card &a, Card &b)  {
    Card tmp = a;
    a = b;
    b = tmp;
}

int Deck::getRandomNumber(const int min, const int max)  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

void Deck::printDeck() {
    for (const auto &card: m_deck) {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffleDeck() {
    int swapIndex;
    for (Card &card: m_deck) {
        swapIndex = getRandomNumber(0, 51);
        swapCard(card, m_deck[swapIndex]);
    }

    m_cardIndex = 0;
}

const Card &Deck::dealCard() {
    assert (m_cardIndex < 52);
    return m_deck[m_cardIndex++];
}
