#include "orc.h"
using namespace std;

//destructor
Orc::~Orc(){}

//constructor
Orc::Orc(){
    this->image = 'O';
}

//returns the subscription type of enemy
SubscriptionType Orc::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Enemy;
    }
}

// get attack from player
void Orc::get_attack(Player *c){
    if(isValid) {
        cout << "Nothing happened..."<< endl;
        return;
    }
    int damage = ceil(100 * (c->ATK) / (100 + this->DEF));
    HP -= damage;
    cout << "You hit the Orc and Orc lose " << damage << " HP!" << endl;
    if (c->race == "Troll"){
        c->HP += 5;
        cout << "You restore 5 HP from successful attack!" << endl;
        c->HP = c->HP > 120 ?  120 : c->HP;
    } else if(c->race == "Vampire") {
        c->HP += 5;
        cout << "You restore 5 HP from successful attack!" << endl;
    }
    if (HP <= 0) {
        cout << "The Orc is dead." << endl;
        this->image = '.';
        isValid = 1;
        isFrozen = 1;
    }
}

