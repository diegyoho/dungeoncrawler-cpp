#pragma once

#include "Character.h"

#include <vector>

class Dungeon
{
public:

    Dungeon(const int& numberOfEnemies);

    bool ReachedEnd();
    Character& GetNextEnemy();

    int CountEnemiesOfSize(const Character::Size& size, const bool& onlyDead = false) const;

    static bool Battle(Character& player, Character& enemy);

private:

    static int nameId;
    static int currentEnemyId;
    
    std::vector<Character> enemies;
};
