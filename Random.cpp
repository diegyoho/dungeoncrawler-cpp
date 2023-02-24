#include "Random.h"

std::mt19937 Random::mersenneTwisterRand{ std::random_device{}() };

void Random::SetSeed(const std::mt19937::result_type& seed)
{
    mersenneTwisterRand.seed(seed);
}

int Random::RangeInt(const int& min, const int& max)
{
    const std::uniform_int_distribution distribution{ min, max };
    return distribution(mersenneTwisterRand);
}

double Random::Double()
{
    const std::uniform_real_distribution distribution{ 0.0, 1.0 };
    return distribution(mersenneTwisterRand);
}
