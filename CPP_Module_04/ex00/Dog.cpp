#include "Dog.hpp"
#include <iostream>

/*
 * Dog sets the inherited type to its own class name.
 */
Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
