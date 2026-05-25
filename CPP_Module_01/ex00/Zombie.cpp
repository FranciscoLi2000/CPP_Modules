#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
    : name_()
{
    /*
     * The constructor gives us a valid object immediately.
     * We fill in the name afterwards so the exercise can show initialization
     * in two steps.
     */
}

Zombie::~Zombie()
{
    /*
     * Destructors run automatically when an object dies.
     * Printing here lets us see exactly when each zombie disappears.
     */
    std::cout << name_ << " is destroyed" << std::endl;
}

void Zombie::setName(const std::string &name)
{
    name_ = name;
}

void Zombie::announce() const
{
    std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}
