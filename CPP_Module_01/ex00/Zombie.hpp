#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    /*
     * A zombie is born without a name, then receives one later.
     * That makes the object easier to reuse in the allocation exercises.
     */
    void setName(const std::string &name);
    void announce() const;

private:
    std::string name_;
};

Zombie *newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif
