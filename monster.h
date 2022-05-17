#ifndef MONSTER_H
#define MONSTER_H
#include "stats.h"
#include <iostream>

class Monster{

    public:
        //Initalises variables that will be inherited to child class
        string monsterName;
        
        Monster();
        void setName();
        ~Monster();

};

#endif