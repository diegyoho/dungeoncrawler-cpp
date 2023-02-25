#include "Dungeon.h"

#include "Random.h"

#include <algorithm>

int Dungeon::nameId{};
int Dungeon::currentEnemyId{};

Dungeon::Dungeon(const int& numberOfEnemies)
{
    for (int i = 0; i < numberOfEnemies; ++i)
    {
        enemies.emplace_back("Enemy " + std::to_string(nameId++));
    }
}

bool Dungeon::ReachedEnd()
{
    return (std::begin(enemies) + currentEnemyId) == std::end(enemies);
}

Character& Dungeon::GetNextEnemy()
{
    return *(std::begin(enemies) + currentEnemyId++);
}

int Dungeon::CountEnemiesOfSize(const Character::Size& size, const bool& onlyDead) const
{
    return std::count_if(std::begin(enemies), std::end(enemies),
        [&size, &onlyDead](const Character& enemy)
        {
            return enemy.GetSize() == size && (!onlyDead || enemy.IsDead());
        });
}

bool Dungeon::Battle(Character& player, Character& enemy)
{
    while (!(player.IsDead() || enemy.IsDead()))
    {
        if(Random::RangeInt(1, 6) % 2 == 0)
        {
            player.Attack(enemy);
        }
        else
        {
            enemy.Attack(player);
        }
    }

    return !player.IsDead();
}
