#include <cassert>
#include <iostream>
#include "Deck.h"
#include "Game.h"
#include "Player.h"

namespace Settings {
    constexpr int MinNumPlayers { 2 };
    int CardsPerPlayer { 5 }; // should be 7 in 2 player game
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

char getPlayerInput() {
    std::cout << "What do you want to do? (d)raw, (s)how cards, (q)uit: ";
    char move{};
    std::cin >> move;
    return move;
}

char handlePlayerInput() {
    char move{};
    while (true) {
        move = getPlayerInput();
        switch (move) {
        case 'd':
        case 's':
        case 'q':
            return move;
        default:
            break;
        }
        std::cout << "Invalid input. Please enter 'd', 's', or 'q'.\n";
    }
    return move;
}

void handlePlayerMove(Player& player, Deck& deck) {
    char move = handlePlayerInput();
    switch (move) {
        case 'd':
            std::cout << "You chose to draw a card.\n";
            player.addCard(deck.dealCard());
            break;
        case 's':
            std::cout << "You chose to show your cards.\n";
            player.showCards();
            break;
        case 'q':
            std::cout << "You chose to quit the game.\n";
            std::exit(0);
        default:
            std::cerr << "Unexpected input: " << move << "\n";
    }
}

int main() {
    Deck deck {};
    deck.shuffle();
    
    int numPlayers { getNumPlayers() };
    if (numPlayers == 2) {
        Settings::CardsPerPlayer = 7;
    }
    
    Game game { numPlayers };

    std::cout << numPlayers << " players are playing in this round\n";
    
    for (int i = 0; i < numPlayers; ++i) {
        Player player{};
        for (int x = 0; x < Settings::CardsPerPlayer; ++x) {
            player.addCard(deck.dealCard());
        }
        game.addPlayer(player);
    }
    
    game.setPile(deck);
    
    game.printPile();

    return 0;
}