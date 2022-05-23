#include <iostream>
#include <string>

#include "stats.h"
#include "player.h"
#include "monster.h"

using namespace std;

Stats::Stats(){

}

void Stats::setName(){
    cout << "Enter name: ";
    cin >> name;
}


// allows player and monster to setup HP
void Stats::setHP(){
    cout << "Enter HP: ";
    cin >> HP;
    //Ensures the user enters an integer
    while(!cin){
        cout << "Please enter an integer" << endl;
        cout << "Enter HP: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> HP;
    }
}
// allows player and monster to setup ATK
void Stats::setATK(){
    cout << "Enter power: ";
    cin >> ATK;
    //Ensures the user enters an integer
    while(!cin){
        cout << "Please enter an integer" << endl;
        cout << "Enter power: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> ATK;
    }
}

void Stats::autoSetupM(){
    HP = 80;
    ATK = 20;
}

Stats::~Stats(){

}