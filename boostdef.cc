#include "boostdef.h"

//isKnown is the static field for all potion types boostdef.
// it is false if player doesn't know about it, true otherwise.
bool Boostdef::isKnown = false;

// constructor
Boostdef::Boostdef() {
     this->image = 'P';
}

// destructor
Boostdef::~Boostdef() {}

// subscriptionType for Boostdef
SubscriptionType Boostdef::subType() const{
    if(isValid) {
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Potion;
    }
}


// use potion on player, increases the atk of player by value amount.
void Boostdef::used(Player *player) {
    if (player->race == "Drow") {
        value *= 1.5;
    }
    player->DEF += value;
    std::cout << "Your DEF increased." << std::endl;
    value = 0;
    image = '.';
    isValid = 1;
}



void Boostdef::obtained(Player *player) {
    return;
}
