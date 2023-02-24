#include "Character.h"

#include "Random.h"

#include <ostream>

Character::Character() :
    health{ Random::RangeInt(80, 120) },
    damage{ Random::RangeInt(10, 30) },
    size{ static_cast<Size>(Random::RangeInt(0, 2)) }
{
}

Character::Character(const std::string& name) : Character()
{
    this->name = name;
}

void Character::Attack(Character& other) const
{
    other.TakeDamage(damage);
}

void Character::TakeDamage(const int& damageReceived)
{
    if(!IsDead())
    {
        health -= damageReceived;
    }
}

std::string Character::EnumSizeToString(const Size& sizeEnum)
{
    switch (sizeEnum)
    {
    case Size::Small:
        return "Small";
    case Size::Medium:
        return "Medium";
    case Size::Big:
        return "Big";
    }

    return "";
}

std::ostream& operator<<(std::ostream& os, const Character& character)
{
    os << character.GetName() << '\n'
        << "Health: " << character.GetHealth() << '\n'
        << "Damage: " << character.GetDamage() << '\n'
        << "Size: " << Character::EnumSizeToString(character.GetSize());

    return os;
}
