#include "Dog.hpp"
#include <iostream>

/*
 * Dog Constructor:
 * Calls the base class constructor first (Animal::Animal())
 * Then initializes Dog-specific members (_breed).
 */
Dog::Dog(void) : Animal(), _breed(0)
{
	std::cout << "Dog constructor called" << std::endl;
}

/*
 * Dog Destructor:
 * Called first when a Dog is destroyed.
 * After this completes, the base class destructor (Animal::~Animal()) is called automatically.
 */
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

/*
 * Dog Copy Constructor:
 * Calls base class copy constructor to copy base class members.
 * Then initializes Dog-specific members.
 */
Dog::Dog(const Dog &src) : Animal(src), _breed(src._breed)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/*
 * Dog Copy Assignment Operator:
 * Calls base class assignment operator to copy base class members.
 * Then assigns Dog-specific members.
 */
Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		_breed = rhs._breed;
	}
	return (*this);
}

/*
 * Implementation of pure virtual function makeSound():
 * This is what makes a Dog a Dog.
 * When makeSound() is called on a Dog through an Animal pointer,
 * this implementation runs, not the base class version (if it existed).
 */
void	Dog::makeSound(void) const
{
	std::cout << _name << " says: Woof! Woof!" << std::endl;
}

/*
 * Override of virtual function eat():
 * Dogs eat differently from generic animals.
 * When eat() is called on a Dog through an Animal pointer,
 * this implementation runs.
 */
void	Dog::eat(void) const
{
	std::cout << _name << " eats dog food." << std::endl;
}
