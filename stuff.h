#ifndef __STUFF_H_
#define __STUFF_H_
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include "subscriptionType.h"

class Character;
class Player;
class Dragon;
class Dwarf;
class Elf;
class Halfling;
class Human;
class Merchant;
class Orc;

class Stuff {
protected:
    char image;
    bool isValid = 0;
    static bool isFrozen;
public:
    Stuff();
    char get_image();
    void freeze();
    bool is_valid();
    virtual SubscriptionType subType() const = 0;
    virtual ~Stuff();
    virtual void get_attack(Player *p);
    virtual void get_attack(Dragon *d);
    virtual void get_attack(Dwarf *d);
    virtual void get_attack(Elf *e);
    virtual void get_attack(Halfling *h);
    virtual void get_attack(Human *h);
    virtual void get_attack(Merchant *m);
    virtual void get_attack(Orc *o);
    virtual void used(Player *p);
    virtual void obtained(Player *p) = 0;
    friend class Cell;
};


#endif
