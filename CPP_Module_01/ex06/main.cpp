#include "Karen.hpp"

#include <iostream>
#include <string>

namespace
{
int levelIndex(const std::string &level)
{
    if (level == "DEBUG")
        return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    return 4;
}
}

int main(int argc, char **argv)
{
    /*
     * The switch statement lets us start at the matching level and fall
     * through to all more serious messages above it.
     */
    Karen karen;

    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }

    switch (levelIndex(argv[1]))
    {
    case 0:
        karen.complain("DEBUG");
    case 1:
        karen.complain("INFO");
    case 2:
        karen.complain("WARNING");
    case 3:
        karen.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    return 0;
}
