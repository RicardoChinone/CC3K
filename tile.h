#ifndef __TILE_H_
#define __TILE_H_
#include "player.h"
#include "subscriptionType.h"
#include "stuff.h"

class Tile: public Stuff {
public:
    Tile();
    ~Tile();
    SubscriptionType subType() const override;
    void obtained(Player *player) override;
};


#endif



