#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
    Weapon();
    Weapon(const std::string &type);

    /*
     * getType returns a const reference so callers can read the weapon type
     * without copying it.
     */
    const std::string &getType() const;
    void setType(const std::string &type);

private:
    std::string type_;
};

#endif
