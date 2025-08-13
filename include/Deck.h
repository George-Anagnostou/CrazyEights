#ifndef DECK_H
#define DECK_H

#include <array>
#include <algorithm>
#include <cassert>
#include "Card.h"
#include "Random.h"

class Deck {
private:
	std::array<Card, 52> m_cards {};
	std::size_t m_nextCardIndex { 0 };

public:
	Deck();

	Card dealCard();
	void shuffle();
};

#endif // DECK_H