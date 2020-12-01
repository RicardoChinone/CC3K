#include "empty.h"

//constructor
Empty::Empty() {
    this->image = ' ';
}

//destructor
Empty::~Empty() {}

//return the subscription type of empty
SubscriptionType Empty::subType() const{
    return SubscriptionType::Wall;
}

void Empty::used(Player *player) {
    return;
}

void Empty::obtained(Player *player){
    return;
}
