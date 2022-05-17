#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "stats.h"

using namespace std;

class Player: public Stats{
    
    public:

        //initialises variables to be used in player class
        string playerName;
        int playerATK;
        int playerHP;
        int playerSpATK;

        //initialies functions that will be used in the player class
        Player();
        void setName();
        void setATK();
        void setSpATK();
        void setHP();
        ~Player();

};

#endif