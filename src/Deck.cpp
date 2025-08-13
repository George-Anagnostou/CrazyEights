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
    assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");

    return m_cards[m_nextCardIndex++];
}

void Deck::shuffle() {
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_nextCardIndex = 0;
}