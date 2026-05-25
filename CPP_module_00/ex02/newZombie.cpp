#include "Zombie.hpp"

Zombie *newZombie(const std::string &name)
{
    /*
     * new allocates on the heap, so the object stays alive until delete is
     * called. Returning a pointer hands ownership to the caller.
     */
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}
