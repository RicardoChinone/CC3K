#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "character.h"
#include "player.h"

class Merchant: public Character{
    int HP = 30;
    int ATK = 70;
    int DEF = 5;
    static bool isNeutral;
public:
    Merchant(); // constructor
    ~Merchant(); //destructor
    SubscriptionType subType() const override;
    void get_attack(Player *c) override;// get attack from the player
};
#endif
