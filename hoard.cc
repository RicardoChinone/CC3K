#include "hoard.h"

//constructor for hoard
Hoard::Hoard() {
    this->image = 'G';
}

//destructor
Hoard::~Hoard() {}


//return subtype of hoard
SubscriptionType Hoard::subType() const{
    if(isValid) {
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Hoard;
    }
}

void Hoard::used(Player *player) {
    std::cout << "Nothing happened..." << std::endl;
    return;
}

//player obtained the gold
void Hoard::obtained(Player *player) {
    if(this->isValid) {
      player->gold += value;
      value = 0;
    }
}
