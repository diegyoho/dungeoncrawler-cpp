#include "Character.h"
#include "Random.h"

#include <iostream>

int main(int argc, char* argv[])
{
    std::string name;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    Character player{ name };
    
    std::cout << player << std::endl;
    return 0;
}
