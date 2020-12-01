#include "dragon.h"
using namespace std;

//constructor
Dragon::~Dragon(){}

//destructor
Dragon::Dragon(){
    this->image = 'D';
}

//returns the subscription type of enemy
SubscriptionType Dragon::subType() const {
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Dragon;
    }
}

// get attack from player
void Dragon::get_attack(Player *c){
    if(isValid) {
        cout << "Nothing happened..."<< endl;
        return;
    }
    int damage = ceil(100 * (c->ATK) / (100 + this->DEF));
    HP -= damage;
    cout << "You hit the Dragon and Dragon lose " << damage << " HP!" << endl;
    if (c->race == "Troll"){
        c->HP += 5;
        c->HP = c->HP > 120 ?  120 : c->HP;
        cout << "You restore 5 HP from successful attack!" << endl;
    } else if(c->race == "Vampire") {
        c->HP += 5;
        cout << "You restore 5 HP from successful attack!" << endl;
    }
    if (HP <= 0) {
        cout << "The Dragon is dead and you can pick the Hoard safely!" << endl;
        this->image = '.';
        isValid = 1;
        isFrozen = 1;
    }
}
