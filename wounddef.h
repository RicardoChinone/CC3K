#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_
#include "subscriptionType.h"
#include "stuff.h"
#include "player.h"

class Wounddef: public Stuff {
    static bool isKnown;
    int value = 5;
public:
    Wounddef();
    ~Wounddef();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};



#endif
