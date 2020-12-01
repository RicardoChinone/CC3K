#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "character.h"
#include "player.h"

class Dragon: public Character {
    int HP = 150;
    int ATK = 20;
    int DEF = 20;
public:
    ~Dragon();
    Dragon(); // constructor
    SubscriptionType subType() const override;
    void get_attack(Player *p) override; // get damage from the player;
};

#endif
