#ifndef __WALL_H_
#define __WALL_H_
#include "subscriptionType.h"
#include "stuff.h"

class Wall: public Stuff {
public:
    Wall(char image);
    ~Wall();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};

#endif

