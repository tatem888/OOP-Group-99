#include <iostream>
#include <string>

#include "stats.h"
#include "player.h"
#include "monster.h"

using namespace std;

Stats::Stats(){

}

void Stats::setName(){

}


// allows player and monster to setup HP
void Stats::setHP(){
    cout << "enter " << name << "'s hitpoints: ";
    cin >> HP;
    //Ensures the user enters an integer
    while(!cin){
        cout << "Please enter an integer" << endl;
        cout << "Enter " << name << "'s HP: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> HP;
    }
}
// allows player and monster to setup ATK
void Stats::setATK(){
    cout << "enter " << name << "'s power: ";
    cin >> ATK;
    //Ensures the user enters an integer
    while(!cin){
        cout << "Please enter an integer" << endl;
        cout << "Enter " << name << "'s ATK: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> ATK;
    }
}

Stats::~Stats(){

}