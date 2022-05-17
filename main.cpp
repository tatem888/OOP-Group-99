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

    // Exmaple Varaibles (Need to be turned into class varaible)
    // Below are default values
    int monsterATK = 20;
    int monsterHP = 100;

    // UI Varaibles Do not change
    // Main Menu Choice
    int choice;

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

    // temporary solution to prevent infinite loop
    int count = 0;
    while(count<10){

        // delay timer
        this_thread::sleep_for(chrono::nanoseconds(delayTime));

        // Startup Screen, allows input
        cout << "\nWelcome to <Game Title>\n" << endl;
        cout << "Program will use default stats,\nif Player or Monster are not manually setup.\n" << endl;
        cout << "1. Setup Player" << endl;
        cout << "2. Setup Monster" << endl;
        cout << "3. Start Game" << endl;
        cout << "4. Quit Game\n" << endl;
        cin >> choice;

        // intput error check
        if( choice < 1 || choice > 4){
            cout << "\nYou need to enter a corrent number." << std::endl;
        }

        // Runs different function base on user choice
        switch(choice){
            case 1:

                // Setup Player stats
                p1.setName();
                p1.setATK();
                p1.setSpATK();
                p1.setHP();
                break;

            case 2:
                // Setup Monster stats
                m1.setName();
                cout << "\nMonster ATK:" << endl;
                cin >> monsterATK;
                cout << "\nMonster HP:" << endl;
                cin >> monsterHP;
                break;

            case 3:

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

                    // intput error check
                    if( abilityChoice < 1 || abilityChoice > 3){
                        cout << "\nYou need to enter a corrent number." << std::endl;
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
                        cout << "\n" << p1.playerName <<" have won!" << endl;
                        break;
                    }
                    
                    // Monster Round
                    tempPlayerHP -= monsterATK;
                    
                    // Monster Attacked damage
                    cout << "\n" << m1.monsterName << " dealt " << monsterATK << " damage to " << p1.playerName <<" ." << endl;

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
                return 0;
        }
        count++;
    }
    return 0;
}