#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

/*
 * The test focuses on two ideas from earlier modules:
 * - polymorphism through base pointers
 * - deep copy when owning dynamic memory
 */
int	main(void)
{
	std::cout << "=== Building a polymorphic animal array ===" << std::endl;

	Animal	*animals[4];
	int		i;

	for (i = 0; i < 2; ++i)
		animals[i] = new Dog();
	for (; i < 4; ++i)
		animals[i] = new Cat();
	for (i = 0; i < 4; ++i)
		animals[i]->makeSound();
	for (i = 0; i < 4; ++i)
		delete animals[i];

	std::cout << "\n=== Proving deep copy for Dog ===" << std::endl;

	Dog	originalDog;
	originalDog.setIdea(0, "guard the door");
	Dog	copiedDog(originalDog);
	originalDog.setIdea(0, "chase the mailman");

	std::cout << "Original dog idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied dog idea:   " << copiedDog.getIdea(0) << std::endl;

	std::cout << "\n=== Proving deep copy for Cat ===" << std::endl;

	Cat	originalCat;
	originalCat.setIdea(0, "sleep on the keyboard");
	Cat	copiedCat;
	copiedCat = originalCat;
	originalCat.setIdea(0, "ignore humans");

	std::cout << "Original cat idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied cat idea:   " << copiedCat.getIdea(0) << std::endl;

	return (0);
}
