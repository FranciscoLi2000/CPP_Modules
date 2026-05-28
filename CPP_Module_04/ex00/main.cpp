#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

/*
 * The main test is intentionally broad so we can see both correct and
 * incorrect polymorphism side by side.
 */
int	main(void)
{
	std::cout << "=== Correct polymorphism ===" << std::endl;

	/*
	 * We use base pointers exactly like the subject asks.
	 * The virtual destructor keeps deletion safe.
	 */
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Wrong polymorphism ===" << std::endl;

	/*
	 * WrongAnimal keeps makeSound() non-virtual, so the base version wins.
	 */
	const WrongAnimal	*wrong = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	delete wrong;

	return (0);
}
