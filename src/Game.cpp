#include "Game.h"

Game::Game(int numPlayers) : totalPlayers { numPlayers } {}

void Game::setPile(Deck& deck) {
    while (!deck.isEmpty()) {
        try {
            Card card { deck.dealCard() };
            pile.push_back(card);
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
    }
}

void Game::printPile() const {
    std::cout << "Current pile of cards: ";
    for (const Card& card : pile) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}

void Game::addPlayer(const Player& player) {
    players.push_back(player);
    std::cout << "Player " << player.getID() << " has been added to the game.\n";
}