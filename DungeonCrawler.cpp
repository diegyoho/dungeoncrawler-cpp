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
        if(!Dungeon::Battle(player, dungeon.GetNextEnemy()))
        {
            std::cout << '\n' << player.GetName() << " is dead." << std::endl;
            break;
        }
    }

    if(!player.IsDead())
    {
        std::cout << '\n' << player.GetName() << " reached the end of the Dungeon!" << std::endl;
        std::cout << "Your reward is you're still alive, enjoy!" << std::endl;
    }

    std::cout << "\nEnemies defeated: " << std::endl;
    std::cout << "Small: " << dungeon.CountEnemiesOfSize(Character::Size::Small, true)
        << "/" << dungeon.CountEnemiesOfSize(Character::Size::Small) << std::endl;
    std::cout << "Medium: " << dungeon.CountEnemiesOfSize(Character::Size::Medium, true)
        << "/" << dungeon.CountEnemiesOfSize(Character::Size::Medium) << std::endl;
    std::cout << "Big: " << dungeon.CountEnemiesOfSize(Character::Size::Big, true)
        << "/" << dungeon.CountEnemiesOfSize(Character::Size::Big) << std::endl;

    return 0;
}
