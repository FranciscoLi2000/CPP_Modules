#include "Zombie.hpp"

#include <cstdlib>
#include <iostream>

namespace
{
/*
 * We keep the demo simple: one argument is the number of zombies and the
 * other is the base name used for the horde.
 */
bool parseInt(const char *text, int &value)
{
    char *end = 0;
    long number = std::strtol(text, &end, 10);

    if (text[0] == '\0' || *end != '\0')
        return false;
    value = static_cast<int>(number);
    return true;
}
}

int main(int argc, char **argv)
{
    /*
     * The test program demonstrates the whole exercise:
     * create a horde, make each zombie announce itself, then delete them all.
     */
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <count> <name>" << std::endl;
        return 1;
    }

    int count = 0;
    if (!parseInt(argv[1], count))
    {
        std::cerr << "Error: invalid count" << std::endl;
        return 1;
    }

    Zombie *horde = zombieHorde(count, argv[2]);
    if (!horde)
        return 1;

    for (int i = 0; i < count; ++i)
        horde[i].announce();
    delete[] horde;
    return 0;
}
