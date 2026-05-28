#include "Animal.hpp"
#include <iostream>

/*
 * The base object starts with a generic type so derived classes can replace it.
 */
Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

/*
 * Copying keeps the public state identical to the source object.
 */
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
 * Assignment mirrors the copy constructor: preserve the observable state.
 */
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

/*
 * Virtual destruction keeps the hierarchy safe when deleting through Animal*.
 */
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string const &Animal::getType(void) const
{
	return (type);
}

/*
 * The generic base sound is intentionally bland so the overrides stand out.
 */
void Animal::makeSound(void) const
{
	std::cout << "Some generic animal sound" << std::endl;
}
