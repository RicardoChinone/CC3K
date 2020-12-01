#include "stuff.h"
using namespace std;

//static field of stuff, if isfrozen is true, then all the enemy can't move.
bool Stuff::isFrozen = 0;

//constructor
Stuff::Stuff() {}

//destructor
Stuff::~Stuff() {}

//return the image of each stuff
char Stuff::get_image() {
    return image;
}


// frozen all stuffs, so all stuffs can't move, except for player
void Stuff::freeze() {
    isFrozen = !isFrozen;
}

// is valid is true if it's walkable
bool Stuff::is_valid() {
    return isValid;
}

void Stuff::get_attack(Player *p) {
    cout << "Nothing happened..." << endl;
    return;
}

void Stuff::get_attack(Dragon *d) {
    return;
}

void Stuff::get_attack(Dwarf *d) {
    return;
}

void Stuff::get_attack(Elf *e) {
    return;
}

void Stuff::get_attack(Halfling *h) {
    return;
}

void Stuff::get_attack(Human *h) {
    return;
}

void Stuff::get_attack(Merchant *m) {
    return;
}

void Stuff::get_attack(Orc *o) {
    return;
}

void Stuff::used(Player *p) {
    cout << "Nothing Happened." << endl;
    return;
}
