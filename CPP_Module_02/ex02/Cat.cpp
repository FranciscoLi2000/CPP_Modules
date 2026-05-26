#include "Cat.hpp"
#include <iostream>

/*
 * Cat Constructor:
 * Calls base class constructor and initializes Cat-specific members.
 * Cats have _lives (9 lives in legends!)
 */
Cat::Cat(void) : Animal(), _lives(9)
{
	std::cout << "Cat constructor called" << std::endl;
}

/*
 * Cat Destructor:
 * Called first when a Cat is destroyed.
 * Base destructor follows automatically.
 */
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

/*
 * Cat Copy Constructor:
 * Copies base class members and Cat-specific members.
 */
Cat::Cat(const Cat &src) : Animal(src), _lives(src._lives)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/*
 * Cat Copy Assignment Operator:
 * Assigns base class members and Cat-specific members.
 */
Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		_lives = rhs._lives;
	}
	return (*this);
}

/*
 * Cat's implementation of makeSound():
 * Each animal makes its own sound.
 */
void	Cat::makeSound(void) const
{
	std::cout << _name << " says: Meow! Meow!" << std::endl;
}

/*
 * Cat's override of eat():
 * Cats eat cat food, not dog food.
 */
void	Cat::eat(void) const
{
	std::cout << _name << " eats cat food." << std::endl;
}
