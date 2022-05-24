#include <string>
#include <iostream>

#include "monster.h"

using namespace std;

// default values for Monster object
Monster::Monster(){
    monsterName = "Monster";
};

//Function that is called upon to set the monster name
void Monster::setName(){
    cout << "Enter the Monsters's name: ";
    cin >> monsterName;
};

//Function that is called upon to return monster name
string Monster::returnName(){
    return monsterName;
}

Monster::~Monster(){

};