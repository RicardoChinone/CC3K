#ifndef __EMPTY_H_
#define __EMPTY_H_
#include "stuff.h"

class Empty: public Stuff {
public:
    Empty();
    ~Empty();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};


#endif
