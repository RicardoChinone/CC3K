#include "dwarf.h"

using namespace::std;

//constructor
Dwarf::Dwarf(){
    this->image = 'W';
   // this->dir = rand() % 4 + 1;
}

//destructor
Dwarf::~Dwarf() {}


//returns the subscription type of enemy
SubscriptionType Dwarf::subType() const {
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Enemy;
    }
}

// get attack from player
void Dwarf::get_attack(Player *c){
    if(isValid) {
        cout << "Nothing happened..."<< endl;
        return;
    }
    int damage = ceil(100 * (c->ATK) / (100 + this->DEF));
    cout << "You hit the Dwarf and Dwarf lose " << damage << " HP!" << endl;
    HP -= damage;
    if (c->race == "Troll"){
        cout << "You restore 5 HP from successful attack!" << endl;
        c->HP += 5;
        c->HP = c->HP > 120 ?  120 : c->HP;
    } else if(c->race == "Vampire") {
        c->HP -= 5;
        cout << "You are allergic to Dwarives and lose 5 HP !" << endl;
    }
    if (HP <= 0) {
        cout << "The Dwarf is dead." << endl;
        this->image = '.';
        isValid = 1;
        isFrozen = 1;
    }
}

