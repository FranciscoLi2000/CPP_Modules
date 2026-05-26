#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void) : WrongAnimal(), _breed(0)
{
	std::cout << "WrongDog constructor called" << std::endl;
}

/*
 * This destructor will NOT be called if WrongDog is deleted through WrongAnimal pointer!
 * Because WrongAnimal::~WrongAnimal() is not virtual.
 * This is a memory leak waiting to happen!
 */
WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &src) : WrongAnimal(src), _breed(src._breed)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog	&WrongDog::operator=(const WrongDog &rhs)
{
	std::cout << "WrongDog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
		_breed = rhs._breed;
	}
	return (*this);
}

void	WrongDog::makeSound(void) const
{
	std::cout << _name << " says: Woof! Woof!" << std::endl;
}

void	WrongDog::eat(void) const
{
	std::cout << _name << " eats dog food." << std::endl;
}
