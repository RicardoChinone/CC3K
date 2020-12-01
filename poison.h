#ifndef _POISON_H_
#define _POISON_H_
#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

class Poison: public Stuff {
    static bool isKnown;
    int value = -10;
public:
    Poison();
    ~Poison();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};
#endif
