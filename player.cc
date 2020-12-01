#include "player.h"


//constructor
Player::Player() {
this->image = '@';
}

//destructor
Player::~Player() {}


//change the race of player
void Player::changeRace(std::string s) {
    race = s;
    if(s == "Shade") {
        return;
    } else if(s == "Drow") {
        HP = 150;
        DEF = 15;
    } else if(s == "Vampire") {
        HP = 50;
    } else if(s == "Troll") {
        HP = 120;
        DEF = 15;
    } else if(s == "Goblin") {
        HP = 110;
        ATK = 15;
        DEF = 20;
    } else if (s == "Pirate"){
        HP = 140;
        DEF = 15;
    } else {
        return;
    }
}

//return the subscription type of player
SubscriptionType Player::subType() const {
    return SubscriptionType::Player;
}

// get attack from enemy

void Player::get_attack(Dragon *d) {
    int i = rand() % 1;
    if(i == 0){
        std::cout << "The Dragon miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(20));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        HP -= damage;
        std::cout << "You take damage from the angry Dragon and lose " << damage << " HP!" << std::endl;
    }
}


void Player::get_attack(Dwarf *d) {
    int i = rand() % 1;
    if(i == 0) {
        std::cout << "The Dwarf miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(20));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        HP -= damage;
        std::cout << "You take damage from the Dwarf and lose " << damage << " HP!" << std::endl;
    }
}
void Player::get_attack(Elf *e) {
    int i = rand() % 1;
    if(i == 0) {
        std::cout << "The Elf miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(30));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        HP -= damage;
        std::cout << "You take damage from the Elf and lose " << damage << " HP!" << std::endl;
    }
}
void Player::get_attack(Halfling *h) {
    int i = rand() % 1;
    if(i == 0) {
        std::cout << "The Halfling miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(15));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        HP -= damage;
        std::cout << "You take damage from the Halfling and lose " << damage << " HP!" << std::endl;
    }
}
void Player::get_attack(Human *h) {
    int i = rand() % 1;
    if(i == 0) {
        std::cout << "The Human miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(20));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        HP -= damage;
        std::cout << "You take damage from the Human and lose " << damage << " HP!" << std::endl;
    }
}


void Player::get_attack(Merchant *m) {
    int i = rand() % 1;
    if(i == 0) {
        std::cout << "The angry Merchant miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(70));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        HP -= damage;
        std::cout << "You take damage from the angry Merchant and lose " << damage << " HP!" << std::endl;
    }
}

void Player::get_attack(Orc *o) {
    int i = rand() % 1;
    if(i == 0) {
        std::cout << "The Orc miss the attack!" << std::endl;
        return;
    } else {
        int damage = ceil((100/(100 + DEF))*(30));
        if (race == "Pirate") {
            this->gold = this->gold + 1;
        }
        if( race == "Goblin") {
            damage = ceil(damage * 1.5);
            std::cout << "It's a critical!" << std::endl;
        }
        HP -= damage;
        std::cout << "You take damage from the Orc and lose " << damage << " HP!" << std::endl;
    }
}
