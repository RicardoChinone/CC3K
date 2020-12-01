#include "wounddef.h"

//isKnown is the static field for all potions having types Wounddef.
// it is false if player doesn't know about it, true otherwise.
bool Wounddef::isKnown = false;

// constructor
Wounddef::Wounddef() {
this->image = 'P';
}
// destructor
Wounddef::~Wounddef() {};

// subscriptionType for wounddef
SubscriptionType Wounddef::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Potion;
    }
}

// use potion on player, reduces the def of player by value amount.
void Wounddef::used(Player *player) {
    if(player->race == "Drow") {
        value = ceil(value * 1.5);
    }
    player->DEF -= value;
    isKnown = true;
    player->DEF = player->DEF < 0 ? 0 : player->DEF;
    std::cout << "Your DEF decreased." << std::endl;
    value = 0;
    image = '.';
    isValid = 1;
}



void Wounddef::obtained(Player *player) {
    return;
}
