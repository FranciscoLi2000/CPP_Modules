#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*
 * Exercise 02 purifies the hierarchy by preventing generic Animal objects.
 */

#include <string>

class Animal
{
public:
	Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal(void);

	std::string const &getType(void) const;
	virtual void	makeSound(void) const = 0;

protected:
	std::string type;
};

#endif
