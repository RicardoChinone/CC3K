#ifndef _RESTORE_H_
#define _RESTORE_H_

#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

class Restore: public Stuff {
    int value = 10;
    static bool isKnown;
public:
    Restore();
    ~Restore();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};

#endif 
