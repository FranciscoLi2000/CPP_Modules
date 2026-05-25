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
     * The switch statement picks the first level to print.
     * After that, a simple loop prints that level and everything above it.
     */
    Karen karen;
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }

    int start = 4;
    switch (levelIndex(argv[1]))
    {
    case 0:
        start = 0;
        break;
    case 1:
        start = 1;
        break;
    case 2:
        start = 2;
        break;
    case 3:
        start = 3;
        break;
    default:
        break;
    }

    if (start == 4)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }

    for (int i = start; i < 4; ++i)
        karen.complain(levels[i]);
    return 0;
}
