#include <string>
#include <iostream>

#include "monster.h"
using namespace std;


Monster::Monster(){

};

//Function that is called upon to set the monster name
void Monster::setName(){
    cout << "enter the monster's name: ";
    cin >> monsterName;
};

Monster::~Monster(){

};