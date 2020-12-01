#include "gold.h"

//constructor
Gold::Gold(int value): value{value} {
    this->image = 'G';
    isValid = 1;
}

//destructor
Gold::~Gold() {}

SubscriptionType Gold::subType() const{
    return SubscriptionType::Tile;
}

void Gold::used(Player *player) {
    std::cout << "Nothing happens." << std::endl;
    return;
}

//let player obtained the gold
void Gold::obtained(Player *player)  {
        player->gold += value;
        value = 0;
}

