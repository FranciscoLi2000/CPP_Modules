#include "Zombie.hpp"

#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
    /*
     * The subject asks for a single allocation, so we use new[].
     * The caller will later destroy the whole horde with delete[].
     */
    if (N <= 0)
        return 0;

    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
    {
        std::ostringstream label;
        label << name << " " << i;
        horde[i].setName(label.str());
    }
    return horde;
}
