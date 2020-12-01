#ifndef __GAMEPLAY_H_
#define __GAMEPLAY_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "gold.h"
#include "observer.h"
#include "subject.h"
#include "hoard.h"
#include "wall.h"
#include "tile.h"
#include "path.h"
#include "empty.h"
#include "door.h"
#include "dragon.h"
#include "elf.h"
#include "player.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "restore.h"
#include "poison.h"
#include "boostatk.h"
#include "woundatk.h"
#include "wounddef.h"
#include "boostdef.h"
#include "boostatk.h"
#include "dwarf.h"
#include "stuff.h"
#include "cell.h"
#include "stair.h"
#include "player.h"
#include "human.h"

void swap(Cell &c1, Cell &c2);

class Gameplay {
    Cell *p; // where the player is
    std::vector<std::vector<Cell*>> theMap;
    std::vector<Cell*> players;
    int floor;
public:
    Gameplay(std::ifstream &f);
    Player* getPlayer();
    ~Gameplay();
    void changeRace(std::string s);
    void attack(std::string dir);
    void use(std::string dir);
    void move(std::string dir);
    void print_map();
    void freeze();
};


#endif
