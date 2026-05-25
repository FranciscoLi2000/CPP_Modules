#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon)
    : name_(name), weapon_(weapon)
{
    /*
     * HumanA receives the weapon at construction time, because this human
     * never exists without one.
     */
}

void HumanA::attack() const
{
    std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}
