#include "Gameplay.h"

Gameplay::Gameplay() = default;

char Gameplay::getPlayerChoice() {
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

Gameplay::Result Gameplay::play() {
    int playerTotal = 0;
    int dealerTotal = 0;

    dealerTotal += m_deck.dealCard().getValue();
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    playerTotal += m_deck.dealCard().getValue();
    playerTotal += m_deck.dealCard().getValue();

    while (true) {
        std::cout << "You have: " << playerTotal << '\n';
        if (playerTotal > 21)
            return LOSE;

        if (getPlayerChoice() == 's')
            break;

        playerTotal += m_deck.dealCard().getValue();
    }

    while (dealerTotal < 17) {
        dealerTotal += m_deck.dealCard().getValue();
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    if (dealerTotal > 21)
        return WIN;

    if (playerTotal == dealerTotal)
        return DRAW;

    return playerTotal > dealerTotal ? WIN : LOSE;
}

void Gameplay::start() {
    m_deck.shuffleDeck();

    Result result = play();
    if (result == WIN)
        std::cout << "You win!\n";
    else if (result == LOSE)
        std::cout << "You lose!\n";
    else
        std::cout << "Draw!\n";
}
