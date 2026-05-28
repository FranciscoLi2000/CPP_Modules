#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string const &Animal::getType(void) const
{
	return (type);
}
