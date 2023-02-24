#pragma once

#include <random>

class Random
{
public:

    static void SetSeed(const std::mt19937::result_type& seed);

    static int RangeInt(const int& min, const int& max);
    static double Double();

private:
    
    static std::mt19937 mersenneTwisterRand;
};
