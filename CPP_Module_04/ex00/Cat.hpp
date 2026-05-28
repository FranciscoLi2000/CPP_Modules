#ifndef CAT_HPP
#define CAT_HPP

/*
 * Cat demonstrates the second derived implementation.
 */

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat(void);

	virtual void	makeSound(void) const;
};

#endif
