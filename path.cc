#include "path.h"

//constructor
Path::Path() {
    this->image = '#';
    isValid = 1;
}

//destructor
Path::~Path() {}

//return the subscription type of path
SubscriptionType Path::subType() const{
    return SubscriptionType::Wall;
}


void Path::used(Player *player) {
    std::cout << "Nothing happens." << std::endl;
    return;
}

void Path::obtained(Player *player){
    return;
}
