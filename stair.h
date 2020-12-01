#ifndef __STAIR_H_
#define __STAIR_H_
#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

class Stair: public Stuff {
public:
    Stair();
    ~Stair();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};

#endif
