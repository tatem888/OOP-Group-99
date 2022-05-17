#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "stats.h"

using namespace std;

class Monster: public Stats{

    public:
    
        string monsterName;

        //Initalises variables that will be inherited to child class
        Monster();
        void setName();
        ~Monster();
};

#endif