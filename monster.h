#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "stats.h"


class Monster: public Stats{

    public:
        //Initalises variables that will be inherited to child class
        Monster();
        void setName();
        ~Monster();

};

#endif