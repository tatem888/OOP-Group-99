#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "player.h"
#include "monster.h"

using namespace std;

int main(){

    // Creates a player and monster object
    Player p1;
    Monster m1;
    Monster* ms;

    // Exmaple Varaibles (Need to be turned into class varaible)
    // Below are default values
    int monsterATK = 20;
    int monsterHP = 100;

    // UI Varaibles Do not change
    // Main Menu Choice
    int choice;

    string optionChoice = "";

    // In game menu choice
    int abilityChoice;

    // In-game player and monster HP
    int tempPlayerHP;
    int tempMonsterHP;

    // Damage delt this turn
    int damageTurn;

    // Breaks game when option 3 is chosen
    bool gameBreak = false;

    // Delay time for next prompt
    int delayTime = 700000000;

    int introStatus = 0;

    int monsterNum;

    while(true){

        // delay timer
        this_thread::sleep_for(chrono::nanoseconds(delayTime));

        // Startup Screen, allows input
        if(introStatus==0){
            cout << "\nWelcome to Monsterous Dungeon\n" << endl;
            cout << "Program will use default stats,\nif Player or Monster are not manually setup.\n" << endl;
        }
        if(introStatus!=0){
            cout << endl;
        }
        cout << "1. player (Player Setup)" << endl;
        cout << "2. monster (Monster Setup)" << endl;
        cout << "3. start (Start Game)" << endl;
        cout << "4. quit (Stop Game)\n" << endl;
        cout << "(player / monster / start / quit)" << endl;
        cin >> optionChoice;

        // Checks user input to prevent infinite loop
        while(optionChoice!="player" && optionChoice!="monster" && optionChoice!="start" && optionChoice!="quit"){
            cout << "Incorrect input please enter one of the menu options.\n" << endl;
            cout << "1. player (Player Setup)" << endl;
            cout << "2. monster (Monster Setup)" << endl;
            cout << "3. start (Start Game)" << endl;
            cout << "4. quit (Stop Game)\n" << endl;
            cout << "(player / monster / start / quit)" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> optionChoice;
        }

        if(optionChoice=="player"){
            choice = 1;
        }
        if(optionChoice=="monster"){
            choice = 2;
        }
        if(optionChoice=="start"){
            choice = 3;
        }
        if(optionChoice=="quit"){
            choice = 4;
        }

        // Runs different function base on user choice
        switch(choice){
            case 1:
                introStatus++;
                // Setup Player stats
                p1.setName();
                p1.setATK();
                p1.setSpATK();
                p1.setHP();
                break;

            case 2:
                introStatus++;
                // Setup Monster stats
                cout << "\nNumber of Monsters:" << endl;
                cin >> monsterNum;

                ms=new Monster[monsterNum];

                // initialises and sets the stats for multiple enemies
                for(int i=0;i<monsterNum;i++){

                        Monster monster;
                        ms[i]=monster;

                        ms[i].setName();
                        ms[i].setHP();
                        ms[i].setATK();

                }

                m1.setName();
                cout << "\nMonster ATK:" << endl;
                cin >> monsterATK;
                cout << "\nMonster HP:" << endl;
                cin >> monsterHP;
                break;

            case 3:
                introStatus++;
                // Reset HP to set values
                tempPlayerHP = p1.playerHP;
                tempMonsterHP = monsterHP;

                // Resets gameBreak
                gameBreak = false;

                // Start Game
                while(true){

                    // Player choose ability
                    cout << "\nChoose a ability to be used\n" << endl;
                    cout << "1. Normal Attack" << endl;
                    cout << "2. Special Attack" << endl;
                    cout << "3. Run Away\n" << endl;
                    cin >> abilityChoice;

                    //Checks input to prevent infinite loop
                    while(!cin){
                        cout << "Incorrect input, please input an integer" << endl;
                        cout << "\nChoose a ability to be used\n" << endl;
                        cout << "1. Normal Attack" << endl;
                        cout << "2. Special Attack" << endl;
                        cout << "3. Run Away\n" << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> abilityChoice;
                    }

                    // Deal damage or end game
                    switch(abilityChoice){
                        case 1:
                            tempMonsterHP -= p1.playerATK;
                            damageTurn = p1.playerATK;
                            break;
                        case 2:
                            tempMonsterHP -= p1.playerSpATK;
                            damageTurn = p1.playerSpATK;
                            break;
                        case 3:
                            cout << "You ran away!" << endl;
                            gameBreak = true;
                            break;
                    }

                    // Break game loop if chosen;
                    if (gameBreak == true){
                        break;
                    }


                    // Display damage dealt this turn and monster HP left
                    this_thread::sleep_for(chrono::nanoseconds(delayTime));
                    cout << "\n"<< p1.playerName << " dealt " << damageTurn << " dmg to Monster." << endl;

                    this_thread::sleep_for(chrono::nanoseconds(delayTime));
                    cout << "\n" << m1.monsterName << " has " << tempMonsterHP << " HP left." << endl;

                    this_thread::sleep_for(chrono::nanoseconds(delayTime));

                    // Win condition
                    if (tempMonsterHP <= 0){
                        cout << "\n" << p1.playerName <<" has won!" << endl;
                        break;
                    }

                    // Monster Round
                    tempPlayerHP -= monsterATK;

                    // Monster Attacked damage
                    cout << "\n" << m1.monsterName << " dealt " << monsterATK << " damage to " << p1.playerName <<"." << endl;

                    this_thread::sleep_for(chrono::nanoseconds(delayTime));
                    // Display player HP left
                    cout << "\n" << p1.playerName << " has " << tempPlayerHP << " HP left." << endl;

                    this_thread::sleep_for(chrono::nanoseconds(delayTime));
                    //Lose condition
                    if (tempPlayerHP <= 0){
                        cout << "\n" << p1.playerName <<" have lost." << endl;
                        break;
                    }
                    damageTurn = 0;
                }
                break;

            case 4:
                //Exit Game
                cout << "Thank you for playing." << endl;
                return 0;
        }
    }
    return 0;
}