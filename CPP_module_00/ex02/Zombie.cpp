#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
    : name_()
{
    /*
     * A constructor prepares the object before it is used.
     * Here we start with an empty name and fill it later with setName().
     */
}

Zombie::~Zombie()
{
    /*
     * Destructors run automatically when an object leaves scope or is deleted.
     * That makes them useful for observing the end of an object's lifetime.
     */
    std::cout << name_ << " is destroyed" << std::endl;
}

void Zombie::setName(const std::string &name)
{
    name_ = name;
}

void Zombie::announce() const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
