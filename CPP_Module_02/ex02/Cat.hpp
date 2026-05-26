#ifndef CAT_HPP
#define CAT_HPP

/*
 * Derived Class: Cat
 * 
 * Similar to Dog, Cat is-a Animal.
 * Different animals have different behaviors.
 */

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &src);
	Cat	&operator=(const Cat &rhs);

	/*
	 * Implementation of pure virtual function from Animal:
	 * Required for every concrete derived class.
	 */
	virtual void	makeSound(void) const;

	/*
	 * Override eat() for Cat-specific behavior.
	 */
	virtual void	eat(void) const;

private:
	int	_lives;
};

#endif
