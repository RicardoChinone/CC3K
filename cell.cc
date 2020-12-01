#include "cell.h"

//constructor
Cell::Cell(int X, int Y, Stuff* s): X{X}, Y{Y}, s{s} {}

//destructor
Cell::~Cell() {
    delete s;
}

//accessor
//Stuff* Cell::get_stuff() {
  //  return s;
//}

//get_attack from others
void Cell::attack(Cell &c) {
    c.s->get_attack(dynamic_cast<Player *>(s));
}

//return the image that the cell's Stuff pointer has.
char Cell::get_image() {
    return s->get_image();
}

//used the potion on Player
void Cell::used(Cell &c) {
    s->used(dynamic_cast<Player *> (c.s));
}

//obtain treasures from others for player
void Cell::obtained(Cell &c) {
    s->obtained(dynamic_cast<Player *> (c.s));
}

// change player's race
void Cell::changeRace(std::string s) {
    dynamic_cast<Player*>(this->s)->changeRace(s);
}

//stop enemy from moving
void Cell::freeze() {
    s->freeze();
}

// return true if the cell is walkable
bool Cell::is_valid() {
    return s->is_valid();
}

// returns a player
Player* Cell::getPlayer() {
    return dynamic_cast<Player*>(s);
}

// return the subscription type of the object that the stuff pointer pointed.
SubscriptionType Cell::subType(){
    return s->subType();
}

// been notified, and take action, depending on what type
//   object cell's pointer s point to.
void Cell::notify(Subject &whoNotified) {
    if ((subType() == SubscriptionType::Hoard) &&
        (whoNotified.subType() == SubscriptionType::Player)) {
        notifyObservers(subType());
    }
    else if ((subType() == SubscriptionType::Hoard) &&
        (whoNotified.subType() == SubscriptionType::Dragon)) {
        s->isValid = 1;
    }
    else if ((subType() == SubscriptionType::Enemy) &&
             (whoNotified.subType() == SubscriptionType::Player)) {
        this->attack(dynamic_cast<Cell &>(whoNotified));
        //char image = (dynamic_cast<Cell &>(whoNotified).s)->get_image();
    }
    else {
        return;
    }
}
