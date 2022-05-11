#ifndef STATS_H
#define STATS_H

#include <string>
#include <iostream>
using namespace std;

class Stats{
     public:
        //initialises variables that will be inherited to the child classes
        string name;
        int HP;
        int ATK;

        Stats();
        //initialises these functions as virtual and they are inherited to the player and enemy classes
        virtual void setName();
        virtual void setHP();
        virtual void setATK();

        ~Stats();
};

#endif