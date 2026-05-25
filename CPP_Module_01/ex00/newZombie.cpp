#include "Zombie.hpp"

Zombie *newZombie(const std::string &name)
{
    /*
     * new creates the zombie on the heap, so the caller must later delete it.
     * Returning a pointer makes that ownership transfer explicit.
     */
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}
