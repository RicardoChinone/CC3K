#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_
#include "player.h"
#include "stuff.h"

class Boostdef: public Stuff {
    int value = 5;
    static bool isKnown;
public:
    Boostdef();
    ~Boostdef();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};

#endif
