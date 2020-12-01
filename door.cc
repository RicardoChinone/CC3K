#include "door.h"

//constructor
Door::Door() {
    isValid = 1;
    this->image = '+';
}

//destructor
Door::~Door() {}

// return subscription type of door
SubscriptionType Door::subType() const{
    return SubscriptionType::Tile;
}


void Door::used(Player *player) {
    return;
}

void Door::obtained(Player *player){
    return;
}

