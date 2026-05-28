#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal(), _brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		*_brain = *other._brain;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}
