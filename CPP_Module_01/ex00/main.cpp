#include "Zombie.hpp"

int main()
{
    /*
     * This tiny test shows both lifetimes:
     * - the heap zombie must be deleted manually
     * - the stack zombie is destroyed automatically
     */
    Zombie *heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stacky");
    return 0;
}
