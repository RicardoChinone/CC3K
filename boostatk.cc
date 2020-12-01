#include "boostatk.h"

//isKnown is the static field for all potion types boostatk.
// it is false if player doesn't know about it, true otherwise.
bool Boostatk::isKnown = false;

// constructor
Boostatk::Boostatk() {
    this->image = 'P';
}

// destructor
Boostatk::~Boostatk() {}

// subscriptionType for Boostatk
SubscriptionType Boostatk::subType() const{
    if(isValid) {
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Potion;
    }
}

// use potion on player, increases the atk of player by value amount.
void Boostatk::used(Player *player) {
    if (player->race == "Drow") {
        value *= 1.5;
    }
    player->ATK += value;
    std::cout << "Your ATK increased." << std::endl;
    value = 0;
    image = '.';
    isValid = 1;
}



void Boostatk::obtained(Player *player) {
    return;
}

