#include "Zombie.hpp"

#include <iostream>

int main()
{
    /*
     * The subject is about lifetime and allocation, so this tiny demo creates
     * one zombie on the heap and one on the stack.
     */
    Zombie *heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stacky");
    return 0;
}
