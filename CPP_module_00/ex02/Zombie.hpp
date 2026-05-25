#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    /*
     * The zombie starts unnamed, then receives a name later.
     * This helps show how an object can be created first and initialized next.
     */
    void setName(const std::string &name);
    void announce() const;

private:
    std::string name_;
};

Zombie *newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif
