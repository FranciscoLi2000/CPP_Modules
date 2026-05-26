#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include <iostream>

/*
 * Main test program for ex02:
 * Demonstrates polymorphism and the importance of virtual destructors.
 */
int	main(void)
{
	/*
	 * Test 1: Using the correct hierarchy (with virtual destructors)
	 */
	std::cout << "=== Correct Hierarchy (Virtual Destructors) ===" << std::endl;

	/*
	 * Create objects directly (stack allocation)
	 */
	Dog		doggy;
	doggy.setName("Buddy");

	Cat		kitty;
	kitty.setName("Whiskers");

	std::cout << "\nCalling methods on actual types:" << std::endl;
	doggy.makeSound();
	doggy.eat();
	kitty.makeSound();
	kitty.eat();

	/*
	 * Polymorphism through pointers:
	 * Even though animal_ptr points to a Dog, the Dog's makeSound() is called.
	 * This is the power of virtual functions!
	 */
	std::cout << "\nPolymorphism through Animal pointers:" << std::endl;
	Animal	*animal_ptr = &doggy;
	animal_ptr->makeSound();
	animal_ptr->eat();

	animal_ptr = &kitty;
	animal_ptr->makeSound();
	animal_ptr->eat();

	/*
	 * Heap allocation with polymorphism
	 * This shows why virtual destructors are critical!
	 */
	std::cout << "\nHeap allocation with polymorphism:" << std::endl;
	Animal	*animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		animals[i]->setName("Animal");
		animals[i]->makeSound();
		animals[i]->eat();
	}

	std::cout << "\nDeleting animals (should see all destructors called):" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}

	/*
	 * Test 2: Wrong hierarchy without virtual destructors
	 * Notice the WrongDog destructor is NOT called when deleting through WrongAnimal pointer!
	 */
	std::cout << "\n=== WRONG Hierarchy (NO Virtual Destructors) ===" << std::endl;
	WrongAnimal	*wrong_animals[2];
	wrong_animals[0] = new WrongDog();
	wrong_animals[1] = new WrongDog();

	std::cout << "\nDeleting WrongDogs through WrongAnimal pointer:" << std::endl;
	std::cout << "Notice: WrongDog destructor is NOT called! This is a memory leak!" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		delete wrong_animals[i];
	}

	std::cout << "\n=== End of Program ===" << std::endl;
	return (0);
}
