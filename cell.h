#ifndef __CELL_H_
#define __CELL_H_
#include <string>
#include "stuff.h"
#include "observer.h"
#include "subject.h"
#include "subscriptionType.h"
#include "player.h"
#include "character.h"
#include "orc.h"

class Cell :public Subject, public Observer{
    int X,Y;
    Stuff* s;
public:
    Cell(int x, int y, Stuff* s);
    ~Cell();
//   Stuff *get_stuff();
    void attack(Cell &c);
    char get_image();
    void used(Cell &c);
    void obtained(Cell &c);
    void freeze();
    bool is_valid();
    void changeRace(std::string s);
    Player* getPlayer();
    SubscriptionType subType() override;;
    void notify(Subject &whoNotified) override;
    friend void swap(Cell &c1, Cell &c2);
    friend class Gameplay;
};


#endif
