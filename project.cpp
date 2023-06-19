#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
char rematchInput = ' ';
bool rematch = false;
string enemyName = " ", className = " ", characterName = " ";
int enemyHealth = 0, enemyAttack = 0, enemySpeed = 0, playerHealth = 0, playerAttack = 0, playerSpeed = 0, playerChoice = 0, enemySlain = 0;

int get_random(){
    srand(time(nullptr));
    int random = 0;
    random = (rand() % 3) + 1;
    return random;
}

int getPlayerDetails(){
    char input = ' ';
    bool permission = false;
    cout << "Hello adventurer, what is your name: ";
    cin >> characterName;
    while (permission == false){
        cout << "\nDo you wish to fight? (y/n)" << endl;
        cin >> input;
        if (input == 'y' || input == 'Y'){
            permission = true;
        } else if (input == 'n' || input == 'N') {
            cout << "Very well..." << endl;
            exit(0);
        } else {
            cout << "You did not enter a valid input, please try again.";
            cin.clear();
            cin.ignore(100, '\n');
    }
    }    

    // permission = false;
    // cout << "Choose a class. (1. Knight, 2. Archer, 3. Footman)";
    // cin >> playerChoice;
    // while(permission == false) {
    //     if(playerChoice == 1 || playerChoice == 2 || playerChoice == 3)
    //         permission = true;
    // } else {
    //     cout << "Error: Invalid input, try again.";
    //     cin.clear();
    //     cin.ignore(100, '\n');
    // }
    return 0;
}


class weakEnemy{
public:
        string name = "Bandit";
        int health =  10;
        int attack = 5;
        int speed = 5;
};
class mediumEnemy{
public:
        string name = "Experienced Bandit";
        int health =  20;
        int attack = 10;
        int speed = 8;
};
class hardEnemy{
public:
        string name = "Bandit Leader";
        int health =  30;
        int attack = 15;
        int speed = 10;
};

//Player classes
class Knight{
public:
        string name = "Knight";
        int health =  100;
        int attack = 10;
        int speed = 6;
};
class Archer{
public:
        string name = "Archer";
        int health =  80;
        int attack = 20;
        int speed = 13;
};
class Footman{
public:
        string name = "Footman";
        int health =  90;
        int attack = 15;
        int speed = 8;
};

void displayStats(){
    cout << "You have chosen: " << className << ". Your stats are: ";
    cout << "Health: " << playerHealth << ", Attack: " << playerAttack << ", Speed: " << playerSpeed << ".\n" << endl;
}

void assignClass() {
    bool permission = false;
    //START OF WHILE LOOP
    while (permission == false){
        switch (playerChoice) {
            case 1: {
            permission = true; //Once given a valid input, breaks out of while loop
            Knight knight; //Creates a knight object
            //Sets the player's stats to the knight's stats
            playerHealth = knight.health;
            playerAttack = knight.attack;
            playerSpeed = knight.speed;
            className = knight.name;
            break;
            }
            case 2: {
            permission = true; //Once given a valid input, breaks out of while loop
            Archer archer; //Creates an archer object
            //Sets the player's stats to the archer's stats
            playerHealth = archer.health; 
            playerAttack = archer.attack;
            playerSpeed = archer.speed;
            className = archer.name;
            break;
            }
            case 3: {
            permission = true; //Once given a valid input, breaks out of while loop
            Footman footman; //Creates a footman object
            //Sets the player's stats to the footman's stats
            playerHealth = footman.health;
            playerAttack = footman.attack;
            playerSpeed = footman.speed;
            className = footman.name;
            break;
            }
            default:
            cout << "\nPlease enter a valid input. (1. Knight, 2. Archer, 3. Footman)" << endl; //Keeps looping until an appropriate input given
            cin.clear(); //Clears the input
            cin.ignore(10000, '\n'); //Ignores the input
            cin >> playerChoice; //Gets input again SO IT DOESNT LOOP FOREVER
            break;
        }
    } //END OF WHILE LOOP

};

void assignEnemy() {

    switch(get_random()){
        case 1: {
            weakEnemy bandit; //Creates a bandit object
            //Sets the enemy's stats to the bandit's stats
            enemyHealth = bandit.health;
            enemyAttack = bandit.attack;
            enemySpeed = bandit.speed;
            enemyName = bandit.name;
            cout << "Prepare for battle " << characterName << "!" << endl;
            cout << "You have encountered a " << enemyName << "!\n" << endl;
            break;
        }
        case 2: {
            mediumEnemy bandit; //Creates a bandit object
            //Sets the enemy's stats to the bandit's stats
            enemyHealth = bandit.health;
            enemyAttack = bandit.attack;
            enemySpeed = bandit.speed;
            enemyName = bandit.name;
            cout << "Prepare for battle " << characterName << "!" << endl;
            cout << "You have encountered a " << enemyName << "!\n" << endl;
            break;
        }
        case 3: {
            hardEnemy bandit; //Creates a bandit object
            //Sets the enemy's stats to the bandit's stats
            enemyHealth = bandit.health;
            enemyAttack = bandit.attack;
            enemySpeed = bandit.speed;
            enemyName = bandit.name;
            cout << "Prepare for battle " << characterName << "!" << endl;
            cout << "You have encountered a " << enemyName << "!\n" << endl;
            break;
        }
        default: {
            cout << "Error: Bandit Switch Code error" << endl;
            break;
        }
    }

}

void battleSequence(){
    if(playerSpeed > enemySpeed) {
        cout << "\nYou are faster than the enemy, you attack first!\n";
        while(playerHealth > 0){

            enemyHealth = enemyHealth - playerAttack;
            cout << "You attack the enemy for " << playerAttack << " damage! The enemy has " << enemyHealth << " health remaining.\n";
            if(enemyHealth <= 0){
                break;
            }
            if(enemyHealth > 0){

                cout << "It is the enemy's turn to strike!\n";
                playerHealth = playerHealth - enemyAttack;
                cout << "The enemy attacks you for " << enemyAttack << " damage! You have " << playerHealth << " health remaining\n";
                if(playerHealth <= 0){
                    // cout << "Oh no, you have perished. What a shame..." << endl;
                    break;
                }
                
            }
        }

    } else if (playerSpeed < enemySpeed){
        cout << "\nThe enemy is faster than you, the enemy attacks first!\n";
        while(enemyHealth > 0){

            playerHealth = playerHealth - enemyAttack;
            cout << "The enemy attacks you for " << enemyAttack << " damage! You have " << playerHealth << " health remaining\n";
                if(playerHealth <= 0){
                    // cout << "Oh no, you have perished. What a shame..." << endl;
                    break;
                }
            if(playerHealth > 0){

                cout << "It is your turn to strike!\n";
                enemyHealth = enemyHealth - playerAttack;
                cout << "You attack the enemy for " << playerAttack << " damage! The enemy has " << enemyHealth << " health remaining.\n";
            if(enemyHealth <= 0){
                break;
            }
            }
        }
    } else {
        cout << "\nYou are as fast as your enemy, you attack first!\n";
        while(playerHealth > 0){

            enemyHealth = enemyHealth - playerAttack;
            cout << "You attack the enemy for " << playerAttack << " damage! The enemy has " << enemyHealth << " health remaining.\n";
            if(enemyHealth <= 0){
                break;
            }
            if(enemyHealth > 0){
                cout << "It is the enemy's turn to strike!\n";
                playerHealth = playerHealth - enemyAttack;
                cout << "The enemy attacks you for " << enemyAttack << " damage! You have " << playerHealth << " health remaining\n";
                if(playerHealth <= 0){
                    // cout << "Oh no, you have perished. What a shame..." << endl;
                    break;
                }
            }
        }
    }
}

void promptForAnotherBattle(){
    enemySlain++;
    cout << "You have slain an enemy! Would you like to fight another?(y/n): ";
    cin >> rematchInput;
    bool permission = false;

    while (permission == false){
        if(rematchInput == 'y' || rematchInput == 'Y') {
            permission = true;
            cout << "Prepare for the next challenger!.\n" << endl;
            assignEnemy();
            battleSequence();
        } else if (rematchInput == 'n' || rematchInput == 'N') {
            permission = true;
            cout << "Leaving already? Anyways, you have slain " << enemySlain << " enemies.\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This works because it discards everything until the newline character is reached
            cin.get();
            exit(0);
        } else {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error: Please enter valid value: ";
        }
    }
}





int main(){

    getPlayerDetails();
    assignClass();
    displayStats();
    assignEnemy();
    battleSequence();

    if (playerHealth <= 0){
    cout << "\nYour character has died, what a shame... You have slain " << enemySlain << " enemies." << endl;
    cout << "GAME OVER. Thanks for playing! (Press Enter to exit.)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This works because it discards everything until the newline character is reached
    cin.get();
    }

    if (playerHealth > 0) {
        while(playerHealth > 0){
            promptForAnotherBattle();
        }
    }

    if (playerHealth <= 0){
    cout << "\nYour character has died, what a shame... You have slain " << enemySlain << " enemies." << endl;
    cout << "GAME OVER. Thanks for playing! (Press Enter to exit.)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This works because it discards everything until the newline character is reached
    cin.get();
    }

    return 0;
}