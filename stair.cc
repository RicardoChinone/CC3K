#include "stair.h"

//constructor
Stair::Stair() {
    this->image = '\\';
    this->isValid = 1;
}

//destructor
Stair::~Stair() {}

//return the subscription type of stair
SubscriptionType Stair::subType() const{
    return SubscriptionType::Stair;
}

void Stair::used(Player *player) {
    std::cout << "Nothing happens." << std::endl;
    return;
}

void Stair::obtained(Player *player){
    return;
}

