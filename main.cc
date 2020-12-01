#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cell.h"
#include "gameplay.h"
using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));
    ifstream f;                 // readin file if has one
    if( argc == 2) {
        f.open(argv[1]);
    } else {
        f.open("map.txt");
    }
    Gameplay *g = new Gameplay(f);
    string s;
    int count = 0;
    if (count == 0) {             // initializing the game
        cout << "Please choose your race." << endl;
        cout << "Please Enter:" << endl;
        cout << "s: Shade, d: Drow, v: Vampire, g: Goblin, t: Troll, i: Pirate" << endl;
        while(cin >> s) {
            if(s == "s") {
                g->changeRace("Shade");
                break;
            } else if(s == "d") {
                g->changeRace("Drow");
                break;
            } else if(s == "v") {
                g->changeRace("Vampire");
                break;
            } else if(s == "g") {
                g->changeRace("Goblin");
                break;
            } else if(s == "t") {
                g->changeRace("Troll");
                break;
            } else if(s == "i") {
                g->changeRace("Pirate");
                break;
            } else {
                cout << "Illegal Race Name. Please enter race again." << endl;
            }
        }
        count++;
        cout << "Player character has spawned." << endl;
        g->print_map();
            while(cin >> s){          // start the game
                std::cout << std::endl << std::endl;
                if(s == "u") { //use the potion
                    cin >> s;
                    g->use(s);
                } else if(s == "q"){ // quit game
                    delete g;
                    break;
                } else if(s == "a") { // attack
                    cin >> s;
                    g->attack(s);
                } else if(s == "ea" || s == "no" || s == "so" || s == "we" ||
                          s == "ne" || s == "nw" || s == "se" || s == "sw") {
                    g->move(s);
                } else if(s == "f") {
                    g->freeze();
                } else if(s == "r") {
                    count = 0;
                } else {
                    cout << "Bad Order!" << endl;
                }
                if(g->getPlayer()->HP <= 0) {
                    break;
                } else {
                    g->print_map();
                }
        }
        cout<<"        GGGGGGGGGGGGGG                  AAAAAAA                     MMMMMMM           MMMMMM              EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
        cout<<"       GGGGGGGGGGGGGGGG                AAAAAAAAA                   MMMMMMMMMM       MMMMMMMMMM            EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
        cout<<"      GGGGGGGGGGGGGGGGGG              AAAAA AAAAA                 MMMMM  MMMMM     MMMMM  MMMMM           EEEEEEE                     " << endl;
        cout<<"     GGGGGG                           AAAAA AAAAA                 MMMMM  MMMMM     MMMMM  MMMMM           EEEEEEE                     " << endl;
        cout<<"     GGGGGG                          AAAAA   AAAAA               MMMMM    MMMMM   MMMMM    MMMMM          EEEEEEE                     " << endl;
        cout<<"    GGGGGG                           AAAAA   AAAAA               MMMMM    MMMMM   MMMMM    MMMMM          EEEEEEE                     " << endl;
        cout<<"    GGGGGG                          AAAAA     AAAAA             MMMMM      MMMMMMMMMMM      MMMMM         EEEEEEEEEEEEEEEEEEEE        " << endl;
        cout<<"   GGGGGG         GGGGGGGGGG        AAAAAAAAAAAAAAA             MMMMM      MMMMMMMMMMM      MMMMM         EEEEEEEEEEEEEEEEEEEE        " << endl;
        cout<<"   GGGGGG         GGGGGGGGGG       AAAAAAAAAAAAAAAAA           MMMMM        MMMMMMMMM        MMMMM        EEEEEEE                     " << endl;
        cout<<"    GGGGGG         GGGGGGGG        AAAAAAAAAAAAAAAAA           MMMMM         MMMMMMM         MMMMM        EEEEEEE                     " << endl;
        cout<<"    GGGGGG           GGGGGG       AAAAA         AAAAA         MMMMM          MMMMMMM          MMMMM       EEEEEEE                     " << endl;
        cout<<"     GGGGGG          GGGGG        AAAAA         AAAAA         MMMMM                           MMMMM       EEEEEEE                     " << endl;
        cout<<"     GGGGGG         GGGGG        AAAAA           AAAAA       MMMMM                             MMMMM      EEEEEEE                     " << endl;
        cout<<"      GGGGGGGGGGGGGGGGGG         AAAAA           AAAAA       MMMMM                             MMMMM      EEEEEEE                     " << endl;
        cout<<"       GGGGGGGGGGGGGGGG         AAAAA             AAAAA     MMMMM                               MMMMM     EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
        cout<<"        GGGGGGGGGGGGGG          AAAAA             AAAAA     MMMMM                                MMMMM    EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl << endl;
        cout<<"        OOOOOOOOOOOOO          vvvvvv                vvvvvv        EEEEEEEEEEEEEEEEEEEEEEEEE       RRRRRRRRRRRRRRRRRRRRRRRR           " << endl;
        cout<<"       OOOOOOOOOOOOOOO         vvvvvv                vvvvvv        EEEEEEEEEEEEEEEEEEEEEEEEE       RRRRRRRRRRRRRRRRRRRRRRRRR          " << endl;
        cout<<"      OOOOOOOOOOOOOOOOO         vvvvvv              vvvvvv         EEEEEEE                         RRRRR                RRRRR         " << endl;
        cout<<"     OOOOOO       OOOOOO        vvvvvv              vvvvvv         EEEEEEE                         RRRRR                RRRRR         " << endl;
        cout<<"    OOOOOO         OOOOOO        vvvvvv            vvvvvv          EEEEEEE                         RRRRR               RRRRR          " << endl;
        cout<<"   OOOOOO           OOOOOO       vvvvvv            vvvvvv          EEEEEEE                         RRRRR              RRRRR           " << endl;
        cout<<"  OOOOOO             OOOOOO       vvvvvv          vvvvvv           EEEEEEEEEEEEEEEEEEEE            RRRRRRRRRRRRRRRRRRRRRRR            " << endl;
        cout<<"  OOOOOO             OOOOOO       vvvvvv          vvvvvv           EEEEEEEEEEEEEEEEEEEE            RRRRRRRRRRRRRRRRRRRRRR             " << endl;
        cout<<"  OOOOOO             OOOOOO        vvvvvv        vvvvvv            EEEEEEE                         RRRRR           RRRRRR             " << endl;
        cout<<"  OOOOOO             OOOOOO        vvvvvv        vvvvvv            EEEEEEE                         RRRRR            RRRRRR            " << endl;
        cout<<"   OOOOOO           OOOOOO          vvvvvv      vvvvvv             EEEEEEE                         RRRRR            RRRRRR            " << endl;
        cout<<"    OOOOOO         OOOOOO           vvvvvv      vvvvvv             EEEEEEE                         RRRRR             RRRRRR           " << endl;
        cout<<"     OOOOOO       OOOOOO             vvvvvv    vvvvvv              EEEEEEE                         RRRRR              RRRRRR          " << endl;
        cout<<"      OOOOOOOOOOOOOOOOO              vvvvvv    vvvvvv              EEEEEEEEEEEEEEEEEEEEEEEEE       RRRRR               RRRRRR         " << endl;
        cout<<"       OOOOOOOOOOOOOOO                vvvvvvvvvvvvvv               EEEEEEEEEEEEEEEEEEEEEEEEE       RRRRR                RRRRRR        " << endl;
        cout<<"        OOOOOOOOOOOOO                  vvvvvvvvvvvv                EEEEEEEEEEEEEEEEEEEEEEEEE       RRRRR                 RRRRRR       " << endl;

        cout << "Exit Game" << endl;
    }
}

/*
cout<<"        GGGGGGGGGGGGGG                  AAAAAAA                     MMMMMMM           MMMMMM              EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
cout<<"       GGGGGGGGGGGGGGGG                AAAAAAAAA                   MMMMMMMMMM       MMMMMMMMMM            EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
cout<<"      GGGGGGGGGGGGGGGGGG              AAAAA AAAAA                 MMMMM  MMMMM     MMMMM  MMMMM           EEEEEEE                     " << endl;
cout<<"     GGGGGG                           AAAAA AAAAA                 MMMMM  MMMMM     MMMMM  MMMMM           EEEEEEE                     " << endl;
cout<<"     GGGGGG                          AAAAA   AAAAA               MMMMM    MMMMM   MMMMM    MMMMM          EEEEEEE                     " << endl;
cout<<"    GGGGGG                           AAAAA   AAAAA               MMMMM    MMMMM   MMMMM    MMMMM          EEEEEEE                     " << endl;
cout<<"    GGGGGG                          AAAAA     AAAAA             MMMMM      MMMMMMMMMMM      MMMMM         EEEEEEEEEEEEEEEEEEEE        " << endl;
cout<<"   GGGGGG         GGGGGGGGGG        AAAAAAAAAAAAAAA             MMMMM      MMMMMMMMMMM      MMMMM         EEEEEEEEEEEEEEEEEEEE        " << endl;
cout<<"   GGGGGG         GGGGGGGGGG       AAAAAAAAAAAAAAAAA           MMMMM        MMMMMMMMM        MMMMM        EEEEEEE                     " << endl;
cout<<"    GGGGGG         GGGGGGGG        AAAAAAAAAAAAAAAAA           MMMMM         MMMMMMM         MMMMM        EEEEEEE                     " << endl;
cout<<"    GGGGGG           GGGGGG       AAAAA         AAAAA         MMMMM          MMMMMMM          MMMMM       EEEEEEE                     " << endl;
cout<<"     GGGGGG          GGGGG        AAAAA         AAAAA         MMMMM                           MMMMM       EEEEEEE                     " << endl;
cout<<"     GGGGGG         GGGGG        AAAAA           AAAAA       MMMMM                             MMMMM      EEEEEEE                     " << endl;
cout<<"      GGGGGGGGGGGGGGGGGG         AAAAA           AAAAA       MMMMM                             MMMMM      EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
cout<<"       GGGGGGGGGGGGGGGG         AAAAA             AAAAA     MMMMM                               MMMMM     EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
cout<<"        GGGGGGGGGGGGGG          AAAAA             AAAAA     MMMMM                                MMMMM    EEEEEEEEEEEEEEEEEEEEEEEEE   " << endl;
*/

/*
cout<<"        OOOOOOOOOOOOO          vvvvvv                vvvvvv    EEEEEEEEEEEEEEEEEEEEEEEEE   RRRRRRRRRRRRRRRRRRRRRRRR                   " << endl;
cout<<"       OOOOOOOOOOOOOOO         vvvvvv                vvvvvv    EEEEEEEEEEEEEEEEEEEEEEEEE   RRRRRRRRRRRRRRRRRRRRRRRRR                  " << endl;
cout<<"      OOOOOOOOOOOOOOOOO         vvvvvv              vvvvvv     EEEEEEE                     RRRRR                RRRRR                 " << endl;
cout<<"     OOOOOO       OOOOOO        vvvvvv              vvvvvv     EEEEEEE                     RRRRR                RRRRR                 " << endl;
cout<<"    OOOOOO         OOOOOO        vvvvvv            vvvvvv      EEEEEEE                     RRRRR               RRRRR                  " << endl;
cout<<"   OOOOOO           OOOOOO       vvvvvv            vvvvvv      EEEEEEE                     RRRRR              RRRRR                   " << endl;
cout<<"  OOOOOO             OOOOOO       vvvvvv          vvvvvv       EEEEEEEEEEEEEEEEEEEE        RRRRRRRRRRRRRRRRRRRRRRR                    " << endl;
cout<<"  OOOOOO             OOOOOO       vvvvvv          vvvvvv       EEEEEEEEEEEEEEEEEEEE        RRRRRRRRRRRRRRRRRRRRRR                     " << endl;
cout<<"  OOOOOO             OOOOOO        vvvvvv        vvvvvv        EEEEEEE                     RRRRR           RRRRRR                     " << endl;
cout<<"  OOOOOO             OOOOOO        vvvvvv        vvvvvv        EEEEEEE                     RRRRR            RRRRRR                    " << endl;
cout<<"   OOOOOO           OOOOOO          vvvvvv      vvvvvv         EEEEEEE                     RRRRR            RRRRRR                    " << endl;
cout<<"    OOOOOO         OOOOOO           vvvvvv      vvvvvv         EEEEEEE                     RRRRR             RRRRRR                   " << endl;
cout<<"     OOOOOO       OOOOOO             vvvvvv    vvvvvv          EEEEEEE                     RRRRR              RRRRRR                  " << endl;
cout<<"      OOOOOOOOOOOOOOOOO              vvvvvv    vvvvvv          EEEEEEEEEEEEEEEEEEEEEEEEE   RRRRR               RRRRRR                 " << endl;
cout<<"       OOOOOOOOOOOOOOO                vvvvvvvvvvvvvv           EEEEEEEEEEEEEEEEEEEEEEEEE   RRRRR                RRRRRR                " << endl;
cout<<"        OOOOOOOOOOOOO                  vvvvvvvvvvvv            EEEEEEEEEEEEEEEEEEEEEEEEE   RRRRR                 RRRRRR               " << endl;
*/
























































        
