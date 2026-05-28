#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

/*
 * WrongAnimal deliberately omits virtual dispatch for makeSound().
 */

#include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal(void);

	std::string const &getType(void) const;
	void	makeSound(void) const;

protected:
	std::string type;
};

#endif
