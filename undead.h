#ifndef UNDEAD_H
#define UNDEAD_H
#include "character.h"
#include "player.h"

class Undead: public Character{
    int dir;
    int HP = 100;
    int ATK = 35;
    int DEF = 20;
public:
    Undead(); // constructor
    ~Undead();
    SubscriptionType subType() const override;
    void get_attack(Player *c) override; // get damage from the player
};




#endif
