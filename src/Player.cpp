#include <vector>
#include "Card.h"
#include "Player.h"

Player::Player() {
    id++;
}

std::vector<Card> Player::getHand() {
    return hand;
}

int Player::getID() const {
    return id;
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}