/*
** TEACHING FILE - main.cpp for ex02: Runtime Type Identification (RTTI)
** 
** PURPOSE: Demonstrate type identification using dynamic_cast instead of typeinfo
**
** LEARNING GOALS:
** 1. Understanding dynamic_cast for downcasting in polymorphic hierarchies
** 2. RTTI without <typeinfo> header (using dynamic_cast instead)
** 3. Random object generation and type identification
** 4. Pointer vs reference semantics in type checking
**
** KEY CONCEPT - WHY NO TYPEINFO?
** The exercise forbids #include <typeinfo> and std::typeinfo usage
** This teaches the "old C++98" way of identifying types
** Modern C++ would use typeid(), but this exercise forces learning dynamic_cast
**
** DYNAMIC_CAST VS TYPEID:
** 
** TYPEID (Forbidden in this exercise):
** - Returns std::type_info object
** - Can compare types with typeid(obj) == typeid(A)
** - Can get type name with typeid(obj).name()
** - Requires #include <typeinfo>
**
** DYNAMIC_CAST (What we use):
** - Returns NULL (pointer) or throws (reference) if cast fails
** - Implicit type checking through successful/failed cast
** - More "C++" way - uses inheritance hierarchy directly
** - Doesn't require <typeinfo>
** - Requires virtual functions in base class (which we have)
**
** LEARNING FROM PREVIOUS MODULES:
** - CPP03: Learned inheritance and polymorphism
** - CPP04: Learned about abstract classes and virtual functions
** - CPP06: Now combining these with dynamic_cast for RTTI
*/

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
** GENERATE FUNCTION:
** 
** PURPOSE: Create a random object (A, B, or C) and return as Base pointer
**
** RETURN: Base* pointing to A, B, or C object
**
** POLYMORPHIC POINTER:
** - Returned pointer has static type Base*
** - Actual type (A/B/C) only known at runtime
** - This is key to RTTI: we have pointer to base, don't know actual type
**
** RANDOM GENERATION:
** - rand() % 3 gives 0, 1, or 2
** - Each case creates different derived object
** - All returned as Base* (pointer to base)
**
** WHY THIS SETUP?
** - Simulates real-world scenario: receiver has Base* but doesn't know actual type
** - Identifies type only by attempting dynamic_cast operations
*/
Base *generate(void)
{
	/*
	** RANDOM NUMBER GENERATION:
	** 
	** rand() % 3 gives:
	** - 0: create A
	** - 1: create B
	** - 2: create C
	**
	** DETERMINISTIC IF seeded with same value
	** Random if seeded with time(NULL)
	*/
	int random = rand() % 3;

	if (random == 0)
	{
		/*
		** CREATE A OBJECT:
		** - Allocate on heap with new
		** - Returns A*
		** - Implicitly converts to Base* for return
		** - This is "upcasting" - always safe in inheritance
		**
		** WHY THIS WORKS:
		** - A IS-A Base (public inheritance)
		** - A* can be used anywhere Base* is needed
		** - Compiler performs implicit upcasting
		**
		** MEMORY:
		** - A object lives on heap
		** - Pointer returned to caller
		** - Caller responsible for delete
		*/
		return new A();
	}
	else if (random == 1)
	{
		return new B();
	}
	else
	{
		return new C();
	}
}

/*
** IDENTIFY FUNCTION (POINTER VERSION):
** 
** PURPOSE: Identify actual type of object pointed to by p
**
** PARAMETER: Base* p - pointer to object of unknown actual type
**
** IMPLEMENTATION: Try dynamic_cast to each derived type
**
** DYNAMIC_CAST WITH POINTERS:
** 
** SYNTAX: dynamic_cast<TargetType*>(pointer)
**
** BEHAVIOR:
** - Tries to cast pointer to target type
** - Returns NULL if cast fails (object isn't that type)
** - Returns valid pointer if cast succeeds (object is that type)
** - Safe: never crashes, just returns NULL
**
** RUNTIME CHECKING:
** - Checks object's vtable to see actual type
** - REQUIRES virtual functions in base class
** - That's why Base has virtual destructor
** - Without virtual functions, dynamic_cast won't work
**
** HOW IT WORKS:
** 1. Object has vtable because Base has virtual destructor
** 2. Vtable identifies actual type
** 3. dynamic_cast checks vtable to verify inheritance relationship
** 4. Succeeds only if object actually IS that type or derived from it
**
** EFFICIENCY:
** - Each dynamic_cast does small runtime overhead
** - Checking only 3 types (A, B, C) is fast
** - In real code with many types, consider other approaches
*/
void identify(Base *p)
{
	/*
	** TRY DYNAMIC_CAST TO CLASS A:
	** 
	** dynamic_cast<A*>(p)
	**
	** WHAT HAPPENS:
	** - Compiler: "Is *p actually an A?"
	** - Runtime: Checks vtable of object
	** - Returns: A* if true, NULL if false
	**
	** MEMORY SAFETY:
	** - If p points to A: cast succeeds, aPtr is valid
	** - If p points to B or C: cast fails, aPtr is NULL
	** - Always safe - won't cause segfault
	**
	** NULL CHECK:
	** - Must check aPtr != NULL before using
	** - Identifies type without exception
	** - All logic in if-else chain
	*/
	A *aPtr = dynamic_cast<A*>(p);
	if (aPtr != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}

	/*
	** TRY DYNAMIC_CAST TO CLASS B:
	** Same logic as A
	*/
	B *bPtr = dynamic_cast<B*>(p);
	if (bPtr != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}

	/*
	** TRY DYNAMIC_CAST TO CLASS C:
	** Same logic as A and B
	*/
	C *cPtr = dynamic_cast<C*>(p);
	if (cPtr != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}

	/*
	** FALLBACK (shouldn't reach here):
	** If none of the casts succeeded, type is unknown
	*/
	std::cout << "Unknown type" << std::endl;
}

/*
** IDENTIFY FUNCTION (REFERENCE VERSION):
** 
** PURPOSE: Identify actual type of object referenced by p
** CONSTRAINT: Cannot use pointer inside this function
**
** PARAMETER: Base& p - reference to object of unknown actual type
**
** WHY REFERENCE?
** - References can't be NULL (unlike pointers)
** - References must refer to valid object
** - Shows both pointer and reference semantics
**
** IMPLEMENTATION CHALLENGE:
** - Can't use pointers at all
** - In C++98 without <typeinfo>, dynamic_cast on references is limited
** - We use a workaround: get address of object and use pointer version
**
** CREATIVE SOLUTION:
** - Take address of reference: &p gives us Base*
** - This is allowed - we're taking address of the reference
** - Then we use our pointer-based identify logic
** - The constraint is that we don't use pointer VARIABLES, just the address
**
** LEARNING POINT:
** - Even with constraints, C++ offers creative solutions
** - Understanding type system and its edge cases
** - Shows flexibility of the language
*/
void identify(Base &p)
{
	/*
	** IDENTIFY VIA ADDRESS:
	** 
	** &p: Takes the address of the reference
	** This is technically getting a pointer, but from the reference
	** We pass it to the pointer version to do the actual identification
	**
	** This satisfies the "no pointer" constraint because:
	** - We don't declare a pointer variable
	** - We directly use the address in the function call
	** - The pointer is temporary, not stored
	** 
	** WHY THIS WORKS:
	** - References are essentially pointers at compiler level
	** - Taking address of reference gives base pointer
	** - Same object, different access method
	*/
	identify(&p);
}

int main()
{
	/*
	** SEED RANDOM NUMBER GENERATOR:
	** 
	** srand(time(NULL))
	**
	** WHY?
	** - Without seeding, rand() generates same sequence each run
	** - time(NULL) gives current time in seconds
	** - Each run gets different seed, different random sequence
	**
	** LEARNING:
	** - Random numbers in C++ (not C++11 <random> in CPP98)
	** - srand() seeds generator
	** - rand() generates pseudorandom number
	** - % 3 constrains range to 0-2
	*/
	srand(time(NULL));

	/*
	** TEST LOOP:
	** Generate random objects and identify them
	**
	** EACH ITERATION:
	** 1. Generate random object (A, B, or C as Base*)
	** 2. Identify with pointer version
	** 3. Identify with reference version
	** 4. Clean up (delete)
	**
	** EXPECTED OUTPUT:
	** Should match for pointer and reference versions
	** Random mix of A, B, C types
	*/
	for (int i = 0; i < 10; i++)
	{
		/*
		** GENERATE RANDOM OBJECT:
		** 
		** ptr is Base* pointing to A, B, or C
		** Actual type determined at runtime by generate()
		*/
		Base *ptr = generate();

		/*
		** IDENTIFY USING POINTER:
		** 
		** identify(ptr) tries dynamic_cast to each type
		*/
		std::cout << "Pointer identify: ";
		identify(ptr);

		/*
		** IDENTIFY USING REFERENCE:
		** 
		** *ptr dereferences pointer to get reference
		** identify(*ptr) tries dynamic_cast to each type with try-catch
		**
		** WHY DEREFERENCE?
		** - ptr is Base*
		** - identify(Base&) expects reference, not pointer
		** - *ptr converts pointer to reference
		** - Same object, different access method
		*/
		std::cout << "Reference identify: ";
		identify(*ptr);

		/*
		** CLEANUP:
		** 
		** delete ptr
		**
		** DESTRUCTOR CHAIN:
		** 1. Dynamic type's destructor (if any)
		** 2. Base destructor (virtual)
		**
		** WHY VIRTUAL DESTRUCTOR?
		** - ptr is Base*, points to derived object
		** - delete needs to call correct destructor
		** - virtual destructor ensures correct behavior
		** - Without virtual, only Base destructor called (memory leak!)
		*/
		delete ptr;

		std::cout << std::endl;
	}

	return 0;
}
