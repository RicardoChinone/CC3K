#ifndef __DOOR_H_
#define __DOOR_H_

#include "stuff.h"

class Door: public Stuff {
public:
    Door();
    ~Door();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};

#endif
