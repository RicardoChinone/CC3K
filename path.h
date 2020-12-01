#ifndef __PATH_H_
#define __PATH_H_

#include "stuff.h"

class Path: public Stuff {
public:
    Path();
    ~Path();
    SubscriptionType subType() const override;
    void used(Player *player) override;
    void obtained(Player *player) override;
};


#endif



