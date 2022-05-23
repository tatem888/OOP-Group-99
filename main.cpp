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
    Monster* ms;

    // UI Varaibles Do not change
    // Main Menu Choice
    int choice;

    string optionChoice = "";

    // In game menu choice
    int abilityChoice;

    // In-game player and monster left
    int tempPlayerHP;
    int monsterLeft;

    // Damage delt this turn
    int damageTurn;

    // Breaks game when option 3 is chosen
    bool gameBreak = false;

    // Delay time for next prompt
    int delayTime = 700000000;

    // Check to make sure input is correct
    int introStatus = 0;

    // Stores number of monsters
    int monsterNum;

    // Keep track of round number
    int round = 0;
    
    bool playerSetup = false;
    bool monsterSetup = false;

    while(true){

        // Startup Screen, allows input
        if(introStatus==0){
            cout << "\nWelcome to Monsterous Dungeon\n" << endl;
            cout << "Please manually setup monster before starting every game.\n" << endl;
        }
        if(introStatus!=0){
            cout << endl;
        }
        cout << "1. Player Setup" << endl;
        cout << "2. Monster Setup" << endl;

        if(monsterSetup == true){
            cout << "3. Start Game" << endl;
        }

        cout << "4. Stop Game\n" << endl;

        /*cout << "(player / monster / start / quit)" << endl;*/
        cin >> choice;

        while(!cin || choice > 4 || choice < 0){
            cout << "Incorrect input please enter one of the menu options.\n" << endl;
            cout << "1. Player Setup" << endl;
            cout << "2. Monster Setup" << endl;
            cout << "3. Start Game" << endl;
            cout << "4. Stop Game\n" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> choice;
        }

        // Checks user input to prevent infinite loop
        /*while(optionChoice!="player" && optionChoice!="monster" && optionChoice!="start" && optionChoice!="quit"){
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
        }*/

        // Runs different function base on user choice
        switch(choice){
            case 1:
                introStatus++;
                // Setup Player stats
                p1.setName();
                p1.setATK();
                p1.setSpATK();
                p1.setHP();
                playerSetup = true;
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

                        ms[i].setHP();
                        ms[i].setATK();

                }
                monsterSetup = true;
                break;

            case 3:
                introStatus++;

                if(monsterSetup == false){
                    // Setup Monster stats
                    cout << "\nNumber of Monsters:" << endl;
                    cin >> monsterNum;

                    ms=new Monster[monsterNum];

                    // initialises and sets the stats for multiple enemies
                    for(int i=0;i<monsterNum;i++){

                            Monster monster;
                            ms[i]=monster;

                            ms[i].setHP();
                            ms[i].setATK();

                    }
                    monsterSetup = true;
                }
                
                // Reset HP to set values
                tempPlayerHP = p1.playerHP;

                // Resets gameBreak
                gameBreak = false;

                monsterLeft = monsterNum;
                int monsterChoice;

                round = 1;

                // Start Game
                while(true){

                    // Player choose ability
                    cout << "\nRound." << round <<endl;
                    cout << "\nChoose a ability to be used\n" << endl;
                    cout << "1. Normal Attack" << endl;
                    cout << "2. Special Attack" << endl;
                    cout << "3. Run Away\n" << endl;
                    cin >> abilityChoice;

                    //Checks input to prevent infinite loop
                    while(!cin || abilityChoice > 3 || abilityChoice < 0){
                        cout << "Incorrect input, please input again" << endl;
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

                            // Ask for input and error checking
                            cout << "\nWhich Monster do you want to attack? (Monster 1 is 0)"<< endl;
                            for(int i=0;i<monsterNum;i++){
                                if(ms[i].HP > 0){
                                    cout << "Monster " << i << " is alive." << endl;
                                }else{
                                    cout << "Monster " << i << " is dead." << endl;
                                }
                            }
                            cin >> monsterChoice;
                            while(!cin || monsterChoice >= monsterNum || monsterChoice < 0){
                                cout << "Please enter an correct input" << endl;
                                cout << "Which Monster do you want to attack?(Monster 1 is 0) ";
                                cin.clear();
                                cin.ignore(256,'\n');
                                cin >> monsterChoice;
                            }
                            
                            // Check is monster is alive
                            if(ms[monsterChoice].HP > 0){
                                // deals damage if it is alive
                                ms[monsterChoice].HP -= p1.playerATK;
                                if(ms[monsterChoice].HP <= 0){
                                    monsterLeft -= 1;
                                }
                            damageTurn = p1.playerATK;
                            }else{
                                cout << "This monster is already dead." << endl;
                            }
                            round++;
                            break;

                        case 2:

                            if(round > 0){
                                for(int i=0;i<monsterNum;i++){
                                    if(ms[i].HP > 0){
                                        cout << "Monster " << i << " is alive." << endl;
                                    }else{
                                        cout << "Monster " << i << " is dead." << endl;
                                }
                                }
                            }

                            // Ask for input and error checking
                            cout << "Which Monster do you want to attack? (Monster 1 is 0)"<< endl;
                            cout << "There is " << monsterLeft << " monsters left." << endl;
                            cin >> monsterChoice;
                            while(!cin || monsterChoice >= monsterNum || monsterChoice < 0){
                                cout << "Please enter an correct input" << endl;
                                cout << "Which Monster do you want to attack? (Monster 1 is 0)";
                                cin.clear();
                                cin.ignore(256,'\n');
                                cin >> monsterChoice;
                            }

                            // Check is monster is alive
                            if(ms[monsterChoice].HP > 0){
                                // deals damage if it is alive
                                ms[monsterChoice].HP -= p1.playerSpATK;
                                if(ms[monsterChoice].HP <= 0){
                                    monsterLeft -= 1;
                                }
                            damageTurn = p1.playerSpATK;
                            }else{
                                cout << "This monster is already dead." << endl;
                            }
                            round++;
                            break;
                            
                        case 3:
                            cout << "You ran away!" << endl;
                            gameBreak = true;
                            break;
                    }

                    // Break game loop if chosen;
                    if (gameBreak == true){
                        monsterSetup = false;
                        break;
                    }

                    string monsterName = "Monster";

                    // Display damage dealt this turn and monster HP left
                    this_thread::sleep_for(chrono::nanoseconds(delayTime));
                    cout << "\n"<< p1.playerName << " dealt " << damageTurn << " dmg to Monster." << endl;

                    this_thread::sleep_for(chrono::nanoseconds(delayTime));
                    cout << "\nMonster " << monsterChoice << " has " << ms[monsterChoice].HP << " HP left." << endl;

                    if(ms[monsterChoice].HP <= 0){
                        this_thread::sleep_for(chrono::nanoseconds(delayTime));
                        cout << "\nMonster " << monsterChoice << " is dead." << endl;
                    }
                    
                    this_thread::sleep_for(chrono::nanoseconds(delayTime));

                    // Win condition
                    if (monsterLeft <= 0){
                        cout << "\n" << p1.playerName <<" has won!" << endl;
                        monsterSetup = false;
                        this_thread::sleep_for(chrono::nanoseconds(delayTime));
                        break;
                    }

                    if(ms[monsterChoice].HP > 0){
                        // Monster Round
                        tempPlayerHP -= ms[monsterChoice].ATK;

                        // Monster Attacked damage
                        cout << "\n" << monsterName << " dealt " << ms[monsterChoice].ATK << " damage to " << p1.playerName <<"." << endl;

                        this_thread::sleep_for(chrono::nanoseconds(delayTime));
                        // Display player HP left
                        cout << "\n" << p1.playerName << " has " << tempPlayerHP << " HP left." << endl;

                        this_thread::sleep_for(chrono::nanoseconds(delayTime));
                        //Lose condition
                        if (tempPlayerHP <= 0){
                            cout << "\n" << p1.playerName <<" have lost." << endl;
                            monsterSetup = false;
                            break;
                        }
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
    delete[] ms;
    delete ms;
    return 0;
}