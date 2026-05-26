#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

/*
 * WrongDog: Derived from WrongAnimal with no virtual destructor
 * 
 * This demonstrates the problem: when deleted through a WrongAnimal pointer,
 * WrongDog's destructor is NOT called, causing memory leaks for any resources
 * WrongDog might manage.
 */

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog(void);
	~WrongDog(void);
	WrongDog(const WrongDog &src);
	WrongDog	&operator=(const WrongDog &rhs);

	virtual void	makeSound(void) const;
	virtual void	eat(void) const;

private:
	int	_breed;
};

#endif
