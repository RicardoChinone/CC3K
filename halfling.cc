#include "halfling.h"
using namespace std;

//constructor
Halfling::Halfling(){
    this->image = 'L';
    dir = rand() % 4 + 1;
}

//destructor
Halfling::~Halfling(){}

//returns the subscription type of enemy
SubscriptionType Halfling::subType() const{
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Enemy;
    }
}

// get attack from player
void Halfling::get_attack(Player *c){
    if(isValid) {
        cout << "Nothing happened..."<< endl;
        return;
    }
    int damage = ceil(100 * (c->ATK) / (100 + this->DEF));
    int n = rand() % 2 + 1;
    if (n == 1) {
        this->HP -= damage;
        cout << "You hit the Halfling and Halfling lose " << damage << " HP!" << endl;
        if (c->race == "Troll"){
            c->HP += 5;
            cout << "You restore 5 HP from successful attack!" << endl;
            c->HP = c->HP > 120 ?  120 : c->HP;
        } else if(c->race == "Vampire") {
            c->HP += 5;
            cout << "You restore 5 HP from successful attack!" << endl;
        }
        if (HP <= 0) {
            cout << "The Halfling is dead." << endl;
            this->image = '.';
            isValid = 1;
            isFrozen = 1;
            }
    } else {
        cout << "Halfling's illusion make you miss the attack!" << endl;
    }
}
