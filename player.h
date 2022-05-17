#include <iostream>
#include <string>
using namespace std;

#include "stats.h"

class Player: public Stats{
    
    public:

        Player();
        //initialies functions that will be used in the player class
        void setName();
        void setATK();
        void setSpATK();
        void setHP();
        
        ~Player();

        //initialises variables to be used in player class
        string playerName;
        int playerATK;
        int playerHP;
        int playerSpATK;

};