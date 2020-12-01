#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_
#include "stuff.h"
#include "player.h"

class Boostatk: public Stuff {
    int value = 5;  // by how much being boost for player's attack
    static bool isKnown;
public:
    Boostatk();
    ~Boostatk();
    SubscriptionType subType() const override;
//    void get_attack(Character *c) override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};


#endif
