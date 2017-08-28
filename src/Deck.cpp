#include "Deck.h"

Deck::Deck() = default;

void Deck::Initialize(sf::Texture &card_texture) {
    for (int suit_index = 0; suit_index < 4; ++suit_index) {
        for (int rank_index = 0; rank_index < 13; ++rank_index) {
            auto suit = static_cast<Card::Suits>(suit_index);
            auto rank = static_cast<Card::Ranks>(rank_index);

            const sf::Vector2i position{kLeftOffset + rank * (kCardSize.x + 1),
                                        kTopOffset.at(suit)};
            Card card(rank, suit, card_texture, sf::IntRect(position, kCardSize), kScale);
            cards_.push_back(card);
        }
    }
}

Card *Deck::DealCard(const sf::Vector2f position) {
    Card *card = &cards_[card_index_++];
    card->SetPosition(position.x, position.y);
    return card;
}

void Deck::Shuffle() {
    for (int index = 0; index < 52; ++index) {
        int random = GetRandomNumber(0, 51);
        SwapCards(cards_[index], cards_[random]);
    }
    card_index_ = 0;
}

void Deck::SwapCards(Card &a, Card &b) {
    const auto tmp = a;
    a = b;
    b = tmp;
}

int Deck::GetRandomNumber(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

sf::Vector2i Deck::GetCardSize() const {
    return {static_cast<int>(kCardSize.x * kScale.x), static_cast<int>(kCardSize.y * kScale.y)};
}
