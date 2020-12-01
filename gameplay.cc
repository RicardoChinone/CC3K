#include "gameplay.h"

//constructor
Gameplay::Gameplay(std::ifstream &f) {
    floor = 1;
    std::string s;
    int j = 0; //col
    theMap = std::vector<std::vector<Cell *>>(79);
    while(getline(f,s)) { // read in map
        for(int i = 0; i < 79; i++) { // row
            if(s[i] == '-' || s[i] == '|') {
                theMap[i].emplace_back(new Cell{i,j,new Wall{s[i]}});
            } else if(s[i] == '.') {
                theMap[i].emplace_back(new Cell{i,j,new Tile});
            } else if(s[i] == '+') {
                theMap[i].emplace_back(new Cell{i,j,new Door});
            } else if(s[i] == '#') {
                theMap[i].emplace_back(new Cell{i,j,new Path});
            } else if(s[i] == ' ') {
                theMap[i].emplace_back(new Cell{i,j,new Empty});
            } else if(s[i] == 'W') {
                theMap[i].emplace_back(new Cell{i,j,new Dwarf});
            } else if(s[i] == 'E') {
                theMap[i].emplace_back(new Cell{i,j,new Elf});
            } else if(s[i] == 'O') {
                theMap[i].emplace_back(new Cell{i,j,new Orc});
            } else if(s[i] == 'M') {
                theMap[i].emplace_back(new Cell{i,j,new Merchant});
            } else if(s[i] == 'D') {
                theMap[i].emplace_back(new Cell{i,j,new Dragon});
            } else if(s[i] == 'H') {
                theMap[i].emplace_back(new Cell{i,j,new Human});
            } else if(s[i] == 'L') {
                theMap[i].emplace_back(new Cell{i,j,new Halfling});
            } else if (s[i] == '0') {
                theMap[i].emplace_back(new Cell{i,j,new Restore});
            } else if(s[i] == '1') {
                theMap[i].emplace_back(new Cell{i,j,new Boostatk});
            } else if(s[i] == '2') {
                theMap[i].emplace_back(new Cell{i,j,new Boostdef});
            } else if(s[i] == '3') {
                theMap[i].emplace_back(new Cell{i,j,new Poison});
            } else if(s[i] == '4') {
                theMap[i].emplace_back(new Cell{i,j,new Woundatk});
            } else if(s[i] == '5') {
                theMap[i].emplace_back(new Cell{i,j,new Wounddef});
            } else if(s[i] == '6') {
                theMap[i].emplace_back(new Cell{i,j,new Gold{2}});
            } else if(s[i] == '7') {
                theMap[i].emplace_back(new Cell{i,j,new Gold{1}});
            } else if(s[i] == '8') {
                theMap[i].emplace_back(new Cell{i,j,new Gold{4}});
            } else if(s[i] == '9') {
                theMap[i].emplace_back(new Cell{i,j,new Hoard});
            } else if(s[i] == '\\') {
                theMap[i].emplace_back(new Cell{i,j,new Stair});
            } else if(s[i] == '@') {
                theMap[i].emplace_back(new Cell{i,j,new Player});
                players.emplace_back(theMap[i][j]);
                if (floor < floor * 25 - j){
                p = theMap[i][j];
                }
            }
        }
        j = j + 1;
    } for(int r = 0; r < 79; r++) { //attach observers
        for(int c = 0; c < 25; c++) {
            Observer* o;
            if(r >= 1) {
                o = theMap[r-1][c];
                theMap[r][c]->attach(o);
                if(c >= 1) {
                     o = theMap[r-1][c-1];
                    theMap[r][c]->attach(o);
                    o = theMap[r][c-1];
                    theMap[r][c]->attach(o);
                }
                if(c <= 23) {
                    o = theMap[r-1][c+1];
                    theMap[r][c]->attach(o);
                    o = theMap[r][c+1];
                    theMap[r][c]->attach(o);
                }
            }
            if(r < 78) {
                o = theMap[r+1][c];
                theMap[r][c]->attach(o);
                if(c >= 1) {
                    o = theMap[r+1][c-1];
                    theMap[r][c]->attach(o);
                }
                if(c < 24) {
                    o = theMap[r+1][c+1];
                    theMap[r][c]->attach(o);
                }
            }
        }
    }
}

//swap the objects two cells points to
void swap(Cell &c1, Cell &c2) {
    if(&c1 == &c2) {
        return;
    } else {
        std::swap(c1.s,c2.s);
    }
}

// player attack if its surroundings has enemy
void Gameplay::attack(std::string s) {
    if(s == "no") {
        p->attack(*theMap[p->X][p->Y+1]);
    } else if ( s == "so") {
        p->attack(*theMap[p->X][p->Y-1]);
    } else if ( s == "ea") {
        p->attack(*theMap[p->X+1][p->Y]);
    } else if ( s == "we") {
        p->attack(*theMap[p->X-1][p->Y]);
    } else if ( s == "ne") {
        p->attack(*theMap[p->X+1][p->Y+1]);
    } else if ( s == "nw") {
        p->attack(*theMap[p->X-1][p->Y+1]);
    } else if ( s == "se") {
        p->attack(*theMap[p->X+1][p->Y-1]);
    } else if ( s == "sw") {
        p->attack(*theMap[p->X-1][p->Y-1]);
    } else {
        std::cout << "Illegal Direction!" <<std::endl;
    }
    //check if player is dead
}

//player use potion if its surrounding has potion
void Gameplay::use(std::string s) {
    if(s == "no") {
        theMap[p->X][p->Y-1]->used(*p);
    } else if ( s == "so") {
        theMap[p->X][p->Y+1]->used(*p);
    } else if ( s == "ea") {
        theMap[p->X+1][p->Y]->used(*p);
    } else if ( s == "we") {
        theMap[p->X-1][p->Y]->used(*p);
    } else if ( s == "ne") {
        theMap[p->X+1][p->Y-1]->used(*p);
    } else if ( s == "nw") {
        theMap[p->X-1][p->Y-1]->used(*p);
    } else if ( s == "se") {
        theMap[p->X+1][p->Y+1]->used(*p);
    } else if ( s == "sw") {
        theMap[p->X-1][p->Y+1]->used(*p);
    } else {
        std::cout << "Illegal Direction!" << std::endl;
    } //check if player is dead
}

//player's move
void Gameplay::move(std::string s) {
    //std::cout << std::endl << std::endl;
    if(s == "no" && theMap[p->X][p->Y-1]->is_valid()) {
        if (theMap[p->X][p->Y-1]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X][p->Y-1],*p);
        std::cout<< "You move to north." << std::endl;
        p = theMap[p->X][p->Y-1];
        p->notify(*p);
    } else if ( s == "so" && theMap[p->X][p->Y+1]->is_valid()) {
        if (theMap[p->X][p->Y+1]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X][p->Y+1],*p);
        std::cout<< "You move to south." << std::endl;
        p = theMap[p->X][p->Y+1];
        p->notify(*p);
    } else if ( s == "ea" && theMap[p->X+1][p->Y]->is_valid()) {
        if (theMap[p->X+1][p->Y]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X+1][p->Y],*p);
        std::cout<< "You move to east." << std::endl;
        p = theMap[p->X+1][p->Y];
        p->notify(*p);
    } else if ( s == "we" && theMap[p->X-1][p->Y]->is_valid()) {
        if (theMap[p->X-1][p->Y]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X-1][p->Y],*p);
        std::cout<< "You move to west." << std::endl;
        p = theMap[p->X-1][p->Y];
        p->notify(*p);
    } else if ( s == "ne" && theMap[p->X+1][p->Y-1]->is_valid()) {
        if (theMap[p->X+1][p->Y-1]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X+1][p->Y-1],*p);
        std::cout<< "You move to northeast." << std::endl;
        p = theMap[p->X+1][p->Y-1];
        p->notify(*p);
    } else if ( s == "nw" && theMap[p->X-1][p->Y-1]->is_valid()) {
        if (theMap[p->X+1][p->Y-1]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X-1][p->Y-1],*p);
        std::cout<< "You move to northwest." << std::endl;
        p = theMap[p->X-1][p->Y-1];
        p->notify(*p);
    } else if ( s == "se" && theMap[p->X+1][p->Y+1]->is_valid()) {
        if (theMap[p->X+1][p->Y+1]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X+1][p->Y+1],*p);
        std::cout<< "You move to southeast." << std::endl;
        p = theMap[p->X+1][p->Y+1];
        p->notify(*p);
    } else if ( s == "sw" && theMap[p->X-1][p->Y+1]->is_valid()) {
        if (theMap[p->X-1][p->Y+1]->get_image() == '\\'){
            floor = floor + 1;
            p = players[floor-1];
            return;
        }
        swap(*theMap[p->X-1][p->Y+1],*p);
        std::cout<< "You move to southwest." << std::endl;
        p = theMap[p->X-1][p->Y+ 1];
        p->notify(*p);
    } else {
        std::cout << "Illegal Direction!" << std::endl;
    } //check if player is dead
}

// print the map to screen
void Gameplay::print_map() {
    int c = (floor - 1) * 25;
    int max = c + 25;
    while(c < max) {
        for (int r = 0; r < 79; r++) {
            std::cout << theMap[r][c]->s->get_image();
        } std::cout << std::endl;
        c = c + 1;
    }
    Player *p = getPlayer();
    std::cout << "Race: " << p->race  << " " << "Gold: " << p->gold;
    std::string str1 = p->race;
    std::string str2 = std::to_string(p->gold);
    int used = str1.length() + str2.length() + 13;
    for(int i = used; i < 69; i++) {
        std::cout << " ";
    }
    std::cout << "Floor " << floor << std::endl;
    std::cout << "HP: " << p->HP << std::endl;
    std::cout << "Atk: " << p->ATK << std::endl;
    std::cout << "Def: " << p->DEF << std::endl;
    std::cout << "Please enter your order:" << std::endl;
}

// change the race of player
void Gameplay::changeRace(std::string s) {
    p->changeRace(s);
}

// returns a player
Player* Gameplay::getPlayer() {
    return p->getPlayer();
}

// freeze all the enemy.
void Gameplay::freeze() {
    for(int r = 0; r < 79; r++) {
        for(int c = 0; c < 25; c++) {
            theMap[r][c]->freeze();
        }
    }
}

Gameplay::~Gameplay() {
    for(int i = 0; i < 79; i++) {
        for(int j = 0; j < 25; j++) {
            delete theMap[i][j];
        }
    }
}
