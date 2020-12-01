#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "character.h"

struct Player :public Character {
    std::string race = "Shade";
    int HP = 125;
    int ATK = 25;
    int DEF = 25;
    int gold = 0;
    Player();
    ~Player();
    void changeRace(std::string s);
    SubscriptionType subType() const override;
    void get_attack(Dragon *d) override;
    void get_attack(Dwarf *d) override;
    void get_attack(Elf *e) override;
    void get_attack(Halfling *h) override;
    void get_attack(Human *h) override;
    void get_attack(Merchant *m) override;
    void get_attack(Orc *o) override;
};

#endif
