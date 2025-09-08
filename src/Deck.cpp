#include "Deck.h"
#include "Random.h"

Deck::Deck() {
    std::size_t count { 0 };
    for (auto suit : Card::allSuits) {
        for (auto rank : Card::allRanks) {
            m_cards[count++] = Card { rank, suit };
        }
    }
}

Card Deck::dealCard() {
    if (this->isEmpty()) {
        throw std::out_of_range("No more cards to deal");
    }

    return m_cards[m_nextCardIndex++];
}

void Deck::shuffle() {
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_nextCardIndex = 0;
}

bool Deck::isEmpty() const {
    return m_nextCardIndex >= m_cards.size();
}