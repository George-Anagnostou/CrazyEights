#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Game {
private:
    int currentPlayerIndex { 0 };
    std::vector<Player> players {};
    int totalPlayers {};
    std::vector<Card> pile {};

public:
    Game(int numPlayers);
    void setPile(Deck& deck);
    void printPile() const;
    void addPlayer(const Player& player);
};

#endif // GAME_H