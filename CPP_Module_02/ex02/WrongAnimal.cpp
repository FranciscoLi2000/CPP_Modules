#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _name("Unknown"), _age(0)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

/*
 * DELIBERATE MISTAKE: Non-virtual destructor
 * This is a common bug that causes memory leaks.
 */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _name(src._name), _age(src._age)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_age = rhs._age;
	}
	return (*this);
}

/*
 * WrongAnimal's implementation of makeSound():
 * This is not pure virtual, so WrongAnimal can be instantiated.
 */
void	WrongAnimal::makeSound(void) const
{
	std::cout << _name << " makes a generic animal sound." << std::endl;
}

void	WrongAnimal::eat(void) const
{
	std::cout << _name << " is eating." << std::endl;
}

const std::string	&WrongAnimal::getName(void) const
{
	return (_name);
}

unsigned int	WrongAnimal::getAge(void) const
{
	return (_age);
}

void	WrongAnimal::setName(const std::string &name)
{
	_name = name;
}

void	WrongAnimal::setAge(unsigned int age)
{
	_age = age;
}
