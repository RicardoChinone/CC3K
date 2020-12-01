#include "restore.h"

//isKnown is the static field for all potions having type restore.
// it is false if player doesn't know about it, true otherwise.
bool Restore::isKnown = false;

// constructor
Restore::Restore() {
    this->image = 'P';
}
// destructor
Restore::~Restore() {}

// subscriptionType for restore
SubscriptionType Restore::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Potion;
    }
}


// use potion on player, increases the hp of player by value amount.
void Restore::used(Player *player) {
    if(player->race == "Drow") {
        value = ceil(value * 1.5);
    }
    player->HP += value;
    if ((player->race == "Shade") && (player->HP > 125)) {
        player->HP = 125;
    } else if ((player->race == "Drow") && (player->HP > 150)) {
        player->HP = 150;
    } else if ((player->race == "Troll") && (player->HP > 120)) {
        player->HP = 120;
    } else if ((player->race == "Goblin") && (player->HP > 110)) {
        player->HP = 110;
    }
    isKnown = true;
    std::cout << "You restored some HP." << std::endl;
    value = 0;
    image = '.';
    isValid = 1;
}



void Restore::obtained(Player *player) {
    return;
}

