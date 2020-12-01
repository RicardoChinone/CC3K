#ifndef _GOLD_H_
#define _GOLD_H_

#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

 
class Gold: public Stuff {
    int value;
public:
    Gold(int value);
    ~Gold();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};



#endif
