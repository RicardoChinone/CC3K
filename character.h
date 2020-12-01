#ifndef __CHARACTER_H_
#define __CHARACTER_H_
#include "stuff.h"
class Player;

struct Character: public Stuff {
    int HP,ATK,DEF;
    std::string race;
    Character();
    void used(Player *p);
    void obtained(Player *p);
    ~Character();
    virtual SubscriptionType subType() const = 0;
};

#endif
