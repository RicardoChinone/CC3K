#include "wall.h"

//constructor
Wall::Wall(char image) {
    this->image = image;
}
//destructor
Wall::~Wall() {}

// return the subscription type of wall
SubscriptionType Wall::subType() const{
    return SubscriptionType::Wall;
}

void Wall::used(Player *player) {
    std::cout << "Nothing happens." << std::endl;
    return;
}

void Wall::obtained(Player *player){
    std::cout << "Nothing happens." << std::endl;
    return;
}

