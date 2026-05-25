#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    /*
     * The horde exercise creates many zombies first, then gives each one a
     * name afterwards.
     */
    void setName(const std::string &name);
    void announce() const;

private:
    std::string name_;
};

Zombie *zombieHorde(int N, std::string name);

#endif
