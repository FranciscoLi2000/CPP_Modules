#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*
 * Exercise 01 reuses the polymorphic base class from exercise 00.
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
	virtual void	makeSound(void) const;

protected:
	std::string type;
};

#endif
