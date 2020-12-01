#ifndef _WOUNDATK_H_
#define _WOUNDATK_H_
#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

class Woundatk: public Stuff {
    static bool isKnown;
    int value = 5;
public:
    Woundatk();
    ~Woundatk();
    SubscriptionType subType() const override ;
    void used(Player *player) override;
    void obtained(Player *player) override;
};

#endif /* woundatk_hpp */
