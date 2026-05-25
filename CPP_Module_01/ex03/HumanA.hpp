#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

#include <string>

class HumanA
{
public:
    HumanA(const std::string &name, Weapon &weapon);

    /*
     * HumanA is always armed, so storing the weapon as a reference is a good
     * fit: the weapon must exist for the whole lifetime of HumanA.
     */
    void attack() const;

private:
    std::string name_;
    Weapon &weapon_;
};

#endif
