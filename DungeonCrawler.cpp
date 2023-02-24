#include "Random.h"

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Let's roll a dice: " << Random::RangeInt(1, 6) << std::endl;
    
    return 0;
}
