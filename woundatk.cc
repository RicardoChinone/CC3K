#include "woundatk.h"

//isKnown is the static field for all potions having type Woundatk.
// it is false if player doesn't know about it, true otherwise.
bool Woundatk::isKnown = 0;


// constructor
Woundatk::Woundatk() {
this->image = 'P';
}

// destructor
Woundatk::~Woundatk() { };

// subscriptionType for woundatk
SubscriptionType Woundatk::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Potion;
    }
}


// use potion on player, reduces the atk of player by value amount.
void Woundatk::used(Player *player) {
    if(player->race == "Drow") {
        value = ceil(value * 1.5);
    }
    player->ATK -= value;
    isKnown = true;
    player->ATK = player->ATK < 0 ? 0 : player->ATK;
    std::cout << "Your ATK decreased." << std::endl;
    value = 0;
    image = '.';
    isValid = 1;
}

void Woundatk::obtained(Player *player) {
    return;
}
