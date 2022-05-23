#ifndef MONSTER_H
#define MONSTER_H
#include "stats.h"
#include <iostream>

class Monster: public Stats{
    private:
        //Initalises variables that will be inherited to child class
        string monsterName;
    public:
        Monster();
        void setName();
        string returnName();
        ~Monster();

};

#endif