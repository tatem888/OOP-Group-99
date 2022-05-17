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

    //Add while loop to check for correct input

}

//function that is called upon to sets the damage a normal ATK will do
void Player::setSpATK(){
    cout << "enter " << playerName << "'s Special Attack power: ";
    cin >> playerSpATK;

    //Add while loop to check for correct input
   
}

//function that is called upon to sets the damage a normal ATK will do
void Player::setHP(){
    cout << "enter " << playerName << "'s HP: ";
    cin >> playerHP;

    //Add while loop to check for correct input
   
}



Player::~Player(){}