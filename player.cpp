#include <iostream>
#include <string>

#include "player.h"

using namespace std;

Player::Player(){}


//function that is called upon for the user to set a name for the player
void Player::setName(){
    cout << "enter the player's name: ";
    cin >> playerName;
}


//function that is called upon to sets the damage a normal ATK will do
void Player::setATK(){
    cout << "enter " << name << "'s attack power: ";
    cin >> playerATK;

    //Add while loop to check for correct input

}

//function that is called upon to sets the damage a normal ATK will do
void Player::setSpATK(){
    cout << "enter " << name << "'s Special Attack power: ";
    cin >> playerSpATK;

    //Add while loop to check for correct input
   
}


Player::~Player(){}