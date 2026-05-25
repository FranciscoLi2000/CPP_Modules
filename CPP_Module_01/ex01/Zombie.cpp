#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
    : name_()
{
    /*
     * Default construction gives each zombie an empty but valid state.
     * The horde function will initialize the names later.
     */
}

Zombie::~Zombie()
{
    /*
     * Printing from the destructor lets us observe when the array is cleaned
     * up with delete[].
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
