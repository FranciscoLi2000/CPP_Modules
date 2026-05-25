#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

#include <string>

class HumanB
{
public:
    HumanB(const std::string &name);

    /*
     * HumanB may start without a weapon, so we keep a pointer that can be
     * null until setWeapon is called.
     */
    void setWeapon(Weapon &weapon);
    void attack() const;

private:
    std::string name_;
    Weapon *weapon_;
};

#endif
