#pragma once

#include <string>

class Character
{
public:

    enum class Size
    {
        Small,
        Medium,
        Big
    };

    Character();

    Character(const std::string& name);

    std::string GetName() const { return name; }
    int GetHealth() const { return health; }
    int GetDamage() const { return damage; }
    Size GetSize() const { return size; }

    bool IsDead() const { return health <= 0; }

    void Attack(Character& other) const;
    void TakeDamage(const int& damageReceived);

    friend std::ostream& operator<<(std::ostream& os, const Character& dt);

private:
    
    std::string name{};
    int health{};
    int damage{};
    Size size{};

    static std::string EnumSizeToString(const Size& sizeEnum);
};
