// Game Name - Dungeon Quest: Battle for Survival
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Define the Player class
class Player {
public:
    // Constructor for the Player class
    Player(string name, int health, int attack) {
        this->name = name;
        this->health = health;
        this->attack = attack;
    }

    // Getters for Player attributes
    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getAttack() {
        return attack;
    }

    // Setter for Player health
    void setHealth(int health) {
        this->health = health;
    }

private:
    string name;
    int health;
    int attack;
};

// Define the Monster class
class Monster {
public:
    // Constructor for the Monster class
    Monster(string name, int health, int attack) {
        this->name = name;
        this->health = health;
        this->attack = attack;
    }

    // Getters for Monster attributes
    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getAttack() {
        return attack;
    }

    // Setter for Monster health
    void setHealth(int health) {
        this->health = health;
    }

private:
    string name;
    int health;
    int attack;
};

// Generate a random integer between min and max (inclusive)
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Randomize the Player's initial values
    string playerName = "Player";
    int playerHealth = random(50, 100);
    int playerAttack = random(10, 20);
    Player player(playerName, playerHealth, playerAttack);

    // Randomize the Monsters' initial values
    vector<Monster> monsters;
    monsters.push_back(Monster("Goblin", random(20, 50), random(5, 10)));
    monsters.push_back(Monster("Troll", random(50, 100), random(10, 20)));
    monsters.push_back(Monster("Dragon", random(100, 200), random(20, 30)));

    // Display the Player's name, health, and attack
    cout << "Player: " << player.getName() << endl;
    cout << "Health: " << player.getHealth() << endl;
    cout << "Attack: " << player.getAttack() << endl;

    // Loop through the vector of Monster objects
    for (int i = 0; i < monsters.size(); i++) {
        // Display the Monster's name, health, and attack
        cout << endl << "Monster: " << monsters[i].getName() << endl;
        cout << "Health: " << monsters[i].getHealth() << endl;
        cout << "Attack: " << monsters[i].getAttack() << endl;

        // Attack the Monster and display the result
        monsters[i].setHealth(monsters[i].getHealth() - player.getAttack());
        cout << "Player attacks " << monsters[i].getName() << " for " << player.getAttack() << " damage." << endl;
        cout << monsters[i].getName() << " health is now " << monsters[i].getHealth() << endl;

        // Check if the Monster is defeated
        if (monsters[i].getHealth() <= 0) {
        cout << monsters[i].getName() << " is defeated!" << endl;
        } else {
        // Attack the Player and display the result
        player.setHealth(player.getHealth() - monsters[i].getAttack());
        cout << monsters[i].getName() << " attacks " << player.getName() << " for " << monsters[i].getAttack() << " damage." << endl;
        cout << player.getName() << " health is now " << player.getHealth() << endl;
        // Check if the Player is defeated
        if (player.getHealth() <= 0) {
            cout << player.getName() << " is defeated!" << endl;
            break; // Exit the loop if the Player is defeated
        }
    }
}
return 0;
}