#ifndef _HUMAN_H
#define _HUMAN_H
#include "character.h"
#include "player.h"

class Human:public Character{
    int HP = 140;
    int ATK = 20;
    int DEF = 20;
public:
    ~Human(); //destructor
    Human(); // constructor
    SubscriptionType subType() const;
    void get_attack(Player *c); // get damage from the player
};

#endif
