#include "Weapon.hpp"

Weapon::Weapon()
    : type_()
{
    /*
     * Start with an empty weapon type so the object is always valid.
     */
}

Weapon::Weapon(const std::string &type)
    : type_(type)
{
    /*
     * A constructor lets us create and initialize the weapon in one step.
     */
}

const std::string &Weapon::getType() const
{
    return type_;
}

void Weapon::setType(const std::string &type)
{
    type_ = type;
}
