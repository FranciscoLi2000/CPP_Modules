#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    /*
     * A setter is useful here because the exercise wants us to create a
     * zombie first, then give it a name while learning how objects live on
     * the stack or the heap.
     */
    void setName(const std::string &name);
    void announce() const;

private:
    std::string name_;
};

Zombie *newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif
