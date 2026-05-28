#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

/*
 * The key difference from exercise 00 is that Animal is no longer instantiable.
 */
int	main(void)
{
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	return (0);
}
