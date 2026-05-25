#include "Zombie.hpp"

void randomChump(const std::string &name)
{
    /*
     * This zombie lives on the stack: it is created inside the function and
     * destroyed automatically when the function ends.
     */
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
