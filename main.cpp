#include <iostream>
#include <string>

#include "player.h"
#include "monster.h"

using namespace std;

int main(){

    Player p1;
    Monster m1;

    // Exmaple Varaibles (Need to be turned into class varaible)
    // Below are default values
    string playerName = "Player";
    int playerATK = 30;
    int playerHP = 100;
    int playerSpATK = 70;
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

    int count = 0;
    while(count<10){

        // Startup Screen, allows input
        cout << "\nWelcome to <Game Title>\n" << endl;
        cout << "Program will use default stats,\nif Player or Monster are not manually setup.\n" << endl;
        cout << "1. Setup Player" << endl;
        cout << "2. Setup Monster" << endl;
        cout << "3. Start Game" << endl;
        cout << "4. Quit Game\n" << endl;
        cin >> choice;

        // intput error check
        /*if( choice < 1 || choice > 4){
            cout << "\nYou need to enter a corrent number." << std::endl;
        }*/

        // Runs different function base on user choice
        switch(choice){
            case 1:

                // Setup Player stats
                cout << "\nPlayer Name:" << endl;
                p1.setName();
                cout << "\nPlayer ATK:" << endl;
                cin >> playerATK;
                cout << "\nPlayer speical ATK:" << endl;
                cin >> playerSpATK;
                cout << "\nPlayer HP:" << endl;
                cin >> playerHP;
                break;

            case 2:
                // Setup Monster stats
                cout << "\nMonster Name:" << endl;
                m1.setName();
                cout << "\nMonster ATK:" << endl;
                cin >> monsterATK;
                cout << "\nMonster HP:" << endl;
                cin >> monsterHP;
                break;

            case 3:

                // Reset HP to set values
                tempPlayerHP = playerHP;
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
                            tempMonsterHP -= playerATK;
                            damageTurn = playerATK;
                            break;
                        case 2:
                            tempMonsterHP -= playerSpATK;
                            damageTurn = playerSpATK;
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
                    cout << "\n"<< playerName << " dealt " << damageTurn << " dmg to Monster." << endl;
                    cout << "\nMonster has " << tempMonsterHP << " HP left." << endl;

                    // Win condition
                    if (tempMonsterHP <= 0){
                        cout << "\n" << playerName <<" have won!" << endl;
                        break;
                    }
                    
                    // Monster Round
                    tempPlayerHP -= monsterATK;
                    
                    // Display player HP left
                    cout << "\nPlayer has " << tempPlayerHP << " HP left." << endl;

                    //Lose condition
                    if (tempPlayerHP <= 0){
                        cout << "\n" << playerName <<" have lost." << endl;
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