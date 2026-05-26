#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

/*
 * WrongAnimal: A deliberately flawed animal class
 * 
 * This class demonstrates why virtual destructors are CRITICAL!
 * Notice the destructor is NOT virtual.
 * This will cause memory leaks when derived objects are deleted through base pointers.
 */

#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);

	/*
	 * WRONG: Destructor is NOT virtual!
	 * When a WrongDog is deleted through a WrongAnimal pointer,
	 * only the WrongAnimal destructor runs, WrongDog's destructor is skipped.
	 * This causes memory leaks!
	 */
	~WrongAnimal(void);

	WrongAnimal(const WrongAnimal &src);
	WrongAnimal	&operator=(const WrongAnimal &rhs);

	virtual void	makeSound(void) const = 0;
	virtual void	eat(void) const;

	const std::string	&getName(void) const;
	unsigned int		getAge(void) const;

	void	setName(const std::string &name);
	void	setAge(unsigned int age);

protected:
	std::string		_name;
	unsigned int	_age;
};

#endif
