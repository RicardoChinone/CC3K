#ifndef __ORC_H_
#define __ORC_H_
#include "character.h"
#include "player.h"

class Orc: public Character {
    int HP =  180;
    int ATK = 30;
    int DEF = 25;
public:
    ~Orc(); // destructor
    Orc(); // constructor
    SubscriptionType subType() const override;
    void get_attack(Player *c) override; // get damage from the player
};


#endif
