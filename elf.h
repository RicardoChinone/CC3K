#ifndef _ELF_H_
#define _ELF_H_
#include "character.h"
#include "player.h"

class Elf: public Character {
    int dir;
    int HP = 140;
    int ATK = 30;
    int DEF = 10;
public:
    Elf(); // constructor;
    ~Elf(); // destructor
    SubscriptionType subType() const override;
    void get_attack(Player *c) override; // get damage from the player
};

#endif

