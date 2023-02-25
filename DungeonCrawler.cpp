#include "Dungeon.h"
#include "Character.h"
#include "Random.h"

#include <iostream>

int main(int argc, char* argv[])
{
    std::string name;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    Character player{ name };
    
    std::cout << "\nCreated " << player << std::endl;

    int numberOfEnemies;
    
    std::cout << "\nEnter the number of enemies: ";
    std::cin >> numberOfEnemies;
    
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid type data! Try Again: ";
        std::cin >> numberOfEnemies;
    }

    Dungeon dungeon{ numberOfEnemies };

    std::cout << "\nDungeon created with " << numberOfEnemies << " enemies." << std::endl;
    
    while (!dungeon.ReachedEnd())
    {
        std::cout << '\n' << dungeon.GetNextEnemy() << std::endl;
    }
    
    return 0;
}
