#include "Zombie.hpp"

Zombie *newZombie(const std::string &name)
{
    /*
     * new allocates an object on the heap. That object stays alive until we
     * explicitly delete it, which is why the caller receives a pointer.
     */
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}
