#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
    : name_()
{
    /*
     * An empty constructor creates the object with a valid state first.
     * The name can then be assigned explicitly with setName().
     */
}

Zombie::~Zombie()
{
    /*
     * Destructors run automatically for stack objects and when delete is
     * used on heap objects, so this is a good place to observe object lifetime.
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
