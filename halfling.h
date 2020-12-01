#ifndef HALFLING_H
#define HALFLING_H

#include "character.h"
#include "player.h"

class Halfling: public Character{
    int dir;
    int HP = 100;
    int ATK = 15;
    int DEF = 20;
public:
    Halfling(); // constructor
    ~Halfling();
    SubscriptionType subType() const override;
    void get_attack(Player *c) override; // get damage from the player
};


#endif
