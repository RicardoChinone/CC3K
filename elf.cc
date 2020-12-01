#include "elf.h"

using namespace::std;

//constructor
Elf::Elf(){
    this->image = 'E';
    this->dir = rand() % 4 + 1;
}

//destructor
Elf::~Elf(){}

//returns the subscription type of enemy
SubscriptionType Elf::subType() const {
    if(isValid){
        return SubscriptionType::Tile;
    } else {
        return SubscriptionType::Enemy;
    }
}

// get attack from player
void Elf::get_attack(Player *c){
    if(isValid) {
        cout << "Nothing happened..."<< endl;
        return;
    }
    int damage = ceil(100 * (c->ATK) / (100 + this->DEF));
    HP -= damage;
    cout << "You hit the Elf and Elf lose " << damage << " HP!" << endl;
    if(c->race != "Drow") {
        HP -= damage;
        cout << "You have an extra attack because of your race!" << endl;
        cout << "You hit the Elf again and Elf lose " << damage << " HP!" << endl;
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
        cout << "The Elf is dead." << endl;
        this->image = '.';
        isValid = 1;
        isFrozen = 1;
    }
}
