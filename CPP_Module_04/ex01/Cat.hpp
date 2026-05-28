#ifndef CAT_HPP
#define CAT_HPP

/*
 * Cat mirrors Dog, proving the deep-copy logic works for both branches.
 */

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat(void);

	virtual void	makeSound(void) const;
	void	setIdea(int index, const std::string &idea);
	std::string	getIdea(int index) const;

private:
	Brain	*_brain;
};

#endif
