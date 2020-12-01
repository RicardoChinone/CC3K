#ifndef _HOARD_H_
#define _HOARD_H_

#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

class Hoard: public Stuff {
    int value = 6;
public:
    Hoard();
    ~Hoard();
    SubscriptionType subType() const override;
    //void get_attack(Character *c) override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};


#endif
