#include "Zombie.hpp"

#include <iostream>

int main()
{
    /*
     * This subject focuses on object lifetime, so the demo shows both ways of
     * creating objects:
     * - heap allocation with new/delete
     * - automatic storage on the stack
     */
    Zombie *heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stacky");
    return 0;
}
