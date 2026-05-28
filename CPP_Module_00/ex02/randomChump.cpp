#include "Zombie.hpp"

void randomChump(const std::string &name)
{
    /*
     * This zombie lives on the stack, so its lifetime is tied to this
     * function. When the function returns, the object is destroyed
     * automatically.
     */
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
