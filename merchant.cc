#include "merchant.h"
using namespace std;

//static field for Merchant, if isNeutral is false, it means merchant becomes enemy
bool Merchant::isNeutral = 1;

//constructor
Merchant::Merchant(){
    this->image = 'M';
}

//destructor
Merchant::~Merchant(){}


//returns the subscription type of enemy
SubscriptionType Merchant::subType() const {
    if(isNeutral) {
        return SubscriptionType::Netural;
    } else {
        return SubscriptionType::Enemy;
    }
}

// get attack from player
void Merchant::get_attack(Player *c){
    if(isValid) {
        cout << "Nothing happened..."<< endl;
        return;
    }
    int damage = ceil((100/(100 + this->DEF))*(c->ATK));
    HP -= damage;
     cout << "You hit the Merchant and Merchant lose " << damage << " HP!" << endl;
    if(isNeutral == 1) {
        isNeutral = 0;
        cout << "All Merchant become your enemy now!" << endl;
    }
    if (c->race == "Troll"){
        c->HP += 5;
        cout << "You restore 5 HP from successful attack!" << endl;
        c->HP = c->HP > 120 ?  120 : c->HP;
    } else if(c->race == "Vampire") {
        c->HP += 5;
        cout << "You restore 5 HP from successful attack!" << endl;
    }
    if (HP <= 0) {
        cout << "The Merchant is dead!" << endl;
        this->image = '.';
        isValid = 1;
        isFrozen = 1;
    }
}
