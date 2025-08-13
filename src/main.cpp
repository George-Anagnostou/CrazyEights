#include <cassert>
#include <iostream>
#include "Deck.h"

namespace Settings {
    constexpr int MinNumPlayers { 2 };
    constexpr int CardsPerPlayer { 5 }; // should be 7 in 2 player game
};

int getNumPlayersInput() {
    std::cout << "How many players are in this game? ";
    int numPlayers{};
    std::cin >> numPlayers;
    return numPlayers;
}

int getNumPlayers() {
    int numPlayers { getNumPlayersInput() };
    while (numPlayers < Settings::MinNumPlayers) {
        std::cout << "There must be at least " << Settings::MinNumPlayers << " players.\n";
        numPlayers = getNumPlayersInput();
    }
    return numPlayers;
}

int main() {
    Deck deck {};
    deck.shuffle();
    
    int numPlayers { getNumPlayers() };
    std::cout << numPlayers << " players are playing in this round\n";
    
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Player " << i << '\n';
        for (int x = 0; x < Settings::CardsPerPlayer; ++x) {
            Card card { deck.dealCard() };
            std::cout << '\t' << card << '\n';
        }
    }

    return 0;
}