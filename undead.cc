#include "undead.h"

using namespace::std;

//constructor
Undead::Undead(){
    this->image = 'U';
    dir = rand() % 4 + 1;
}

//destructor
Undead::~Undead(){}


//returns the subscription type of enemy
SubscriptionType Undead::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Enemy;
    }
}

// get attack from player
void Undead::get_attack(Player *c){
    if(isValid) {
        return;
    }
    int damage = ceil((100/(100 + this->DEF))*(c->ATK));

    this->HP -= damage;
    this->ATK = this->ATK + 1;
    if (c->race == "Troll"){
        c->HP += 5;
        c->HP = c->HP > 120 ?  120 : c->HP;
    } else if(c->race == "Vampire") {
        c->HP += 5;
    }
    if (HP <= 0) {
        this->image = '.';
        isValid = 1;
        isFrozen = 1;
    }
}
