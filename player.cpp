#include <iostream>
#include <string>

#include "player.h"

using namespace std;

// default values for player object
Player::Player(){
    playerName = "Player";
    playerATK = 30;
    playerSpATK = 60;
    playerHP = 100;
}

//function that is called upon for the user to set a name for the player
void Player::setName(){
    cout << "Enter the player's name: ";
    cin >> playerName;
}


//function that is called upon to sets the damage a normal ATK will do
void Player::setATK(){
    cout << "Enter " << playerName << "'s attack power: ";
    cin >> playerATK;
    while(!cin){
        cout << "Incorrect input, you must enter an integer\n" << endl;
        cout << "Enter " << playerName << "'s attack power: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> playerATK;
    }

}

//function that is called upon to sets the damage a special ATK will do
void Player::setSpATK(){
    cout << "enter " << playerName << "'s Special Attack power: ";
    cin >> playerSpATK;
    while(!cin){
        cout << "Incorrect input, you must enter an integer\n" << endl;
        cout << "enter " << playerName << "'s Special Attack power: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> playerSpATK;
    }

}

//function that is called upon to sets players health points
void Player::setHP(){
    cout << "enter " << playerName << "'s HP: ";
    cin >> playerHP;
    while(!cin){
        cout << "Incorrect input, you must enter an integer\n" << endl;
        cout << "enter " << playerName << "'s HP: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> playerHP;
    }

}



Player::~Player(){}