#include "poison.h"

//isKnown is the static field for all potions having type poison.
// it is false if player doesn't know about it, true otherwise.
bool Poison::isKnown = false;

// constructor
Poison::Poison() {
     this->image = 'P';
}
// destructor
Poison::~Poison() {}
// subscriptionType for poison
SubscriptionType Poison::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Potion;
    }
}

// use potion on player, reduces the hp of player by value amount.
void Poison::used(Player *player) {
    if(player->race == "Drow") {
        value = ceil(value * 1.5);
    }
    player->HP += value;
    isKnown = true;
    std::cout << "You lost some HP." << std::endl;
    value = 0;
    image = '.';
    isValid = 1;
}



void Poison::obtained(Player *player) {
    return;
}



