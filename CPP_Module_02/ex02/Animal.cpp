#include "Animal.hpp"
#include <iostream>

/*
 * Animal constructor:
 * Initializes the base class members.
 * Derived classes will call this through the member initializer list.
 */
Animal::Animal(void) : _name("Unknown"), _age(0)
{
	std::cout << "Animal constructor called" << std::endl;
}

/*
 * Animal destructor:
 * MUST be virtual so derived class destructors are called.
 * This is called after the derived destructor.
 */
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
 * Copy constructor:
 * Creates a copy of another Animal.
 */
Animal::Animal(const Animal &src) : _name(src._name), _age(src._age)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
 * Copy assignment operator:
 * Assigns one Animal to another.
 */
Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_age = rhs._age;
	}
	return (*this);
}

/*
 * Default eat() implementation:
 * Can be overridden by derived classes, but provides a default behavior.
 * Virtual (not pure), so derived classes don't HAVE to override it.
 */
void	Animal::eat(void) const
{
	std::cout << _name << " is eating." << std::endl;
}

const std::string	&Animal::getName(void) const
{
	return (_name);
}

unsigned int	Animal::getAge(void) const
{
	return (_age);
}

void	Animal::setName(const std::string &name)
{
	_name = name;
}

void	Animal::setAge(unsigned int age)
{
	_age = age;
}
