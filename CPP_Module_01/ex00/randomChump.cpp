#include "Zombie.hpp"

void randomChump(const std::string &name)
{
    /*
     * This zombie lives on the stack.
     * Its lifetime is tied to this function, so cleanup happens automatically.
     */
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
