#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string &name)
    : name_(name), weapon_(0)
{
    /*
     * The weapon pointer starts empty because HumanB is allowed to be unarmed.
     */
}

void HumanB::setWeapon(Weapon &weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack() const
{
    if (weapon_ == 0)
    {
        std::cout << name_ << " has no weapon" << std::endl;
        return;
    }
    std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}
