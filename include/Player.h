#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
private:
    inline static int id;
    std::vector<Card> hand {};
    
public:
    Player();
    std::vector<Card> getHand();
    int getID() const;
    void addCard(const Card& card);
    void showCards() const;
};

#endif // PLAYER_H