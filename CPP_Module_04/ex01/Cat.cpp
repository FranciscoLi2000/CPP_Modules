#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal(), _brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		*_brain = *other._brain;
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}
