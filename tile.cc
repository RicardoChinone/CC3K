#include "tile.h"

//constructor
Tile::Tile() {
    isValid = 1;
    this->image = '.';
}
//destructor
Tile::~Tile() {}


//returns subscription type of tile
SubscriptionType Tile::subType() const{
    return SubscriptionType::Tile;
}

void Tile::obtained(Player *player){
    return;
}
