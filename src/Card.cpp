#include "Card.h"

Card::Card(Card::Ranks rank, Card::Suits suit, const sf::Texture &texture, const sf::IntRect int_rect,
           const sf::Vector2f scale)
    : rank_(rank), suits_(suit) {
    sprite_.setTexture(texture);
    sprite_.setTextureRect(int_rect);
    sprite_.setScale(scale);
}

int Card::GetValue() const {
    switch (rank_) {
        case kRank2:        return 2;
        case kRank3:        return 3;
        case kRank4:        return 4;
        case kRank5:        return 5;
        case kRank6:        return 6;
        case kRank7:        return 7;
        case kRank8:        return 8;
        case kRank9:        return 9;
        case kRank10:
        case kRankJack:
        case kRankQueen:
        case kRankKing:     return 10;
        case kRankAce:      return 11;
    }

    return 0;
}

void Card::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite_, states);
}

void Card::SetPosition(float x, float y) {
    sprite_.setPosition(x, y);
}
