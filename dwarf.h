#ifndef __DWARF_H_
#define __DWARF_H_
#include "character.h"
#include "player.h"

class Dwarf: public Character {
    std::string race = "Dwarf";
    int HP  = 100;
    int ATK = 20;
    int DEF = 30;
public:
    Dwarf(); // constructor;
    ~Dwarf(); // destructor
    SubscriptionType subType() const override;
    void get_attack(Player *c) override; // get damage from the player;
};



#endif
