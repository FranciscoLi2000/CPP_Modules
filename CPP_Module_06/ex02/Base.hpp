/*
** TEACHING FILE - CPP06 ex02: Base Class for RTTI
** 
** PURPOSE: Abstract base class for polymorphic type identification
**
** LEARNING GOALS:
** 1. Virtual destructors and why they matter
** 2. Polymorphism through inheritance
** 3. Using dynamic_cast for RTTI (Runtime Type Information)
** 4. Understanding the inheritance hierarchy
**
** LEARNING FROM PREVIOUS MODULES:
** - CPP03: Inheritance and polymorphism
** - CPP04: Abstract classes and virtual functions
** - CPP06 (HERE): RTTI with dynamic_cast instead of typeid
**
** KEY TEACHING: Virtual Destructors
** 
** WHY VIRTUAL?
** - When you delete a derived object through base class pointer
** - Compiler needs to know to call derived destructor first
** - Then call base destructor
** - Without virtual, only base destructor is called (memory leak!)
**
** EXAMPLE (WITHOUT virtual destructor - WRONG):
** class Base { public: ~Base() { cout << "Base" << endl; } };
** class Derived : public Base { public: ~Derived() { cout << "Derived" << endl; } };
** int main() {
**     Base* b = new Derived();
**     delete b;  // Prints "Base" only - Derived destructor never called!
**     // Memory allocated in Derived's constructor is leaked
** }
**
** EXAMPLE (WITH virtual destructor - RIGHT):
** class Base { public: virtual ~Base() { cout << "Base" << endl; } };
** class Derived : public Base { public: virtual ~Derived() { cout << "Derived" << endl; } };
** int main() {
**     Base* b = new Derived();
**     delete b;  // Prints "Derived" then "Base" - correct!
**     // All memory properly cleaned up
** }
**
** RULE OF THUMB:
** - If a class has any virtual functions, make destructor virtual
** - If you inherit from a class, assume it might be deleted through base pointer
** - Always use virtual destructors in inheritance hierarchies
*/

#ifndef BASE_HPP
#define BASE_HPP

/*
** FORWARD DECLARATIONS:
** We don't need full definitions here, just declared later
** But since this is header-only, we skip this pattern
*/

class Base
{
	public:
		/*
		** VIRTUAL DESTRUCTOR:
		** 
		** SYNTAX: virtual ~ClassName()
		**
		** WHAT IT DOES:
		** - Marks this destructor as replaceable by derived classes
		** - Ensures proper cleanup order: derived -> base
		** - Enables polymorphic destruction
		**
		** WHEN CALLED:
		** - When delete is called on a Base* pointing to Derived object
		** - Compiler chooses correct destructor at runtime (virtual dispatch)
		** - Derived destructor runs first, then Base destructor
		**
		** VTABLE:
		** - Virtual functions require a Virtual Method Table (vtable)
		** - Each class with virtual functions has a vtable
		** - Vtable contains pointers to virtual function implementations
		** - At runtime, correct version is called through vtable lookup
		**
		** LEARNING FROM CPP03 & CPP04:
		** - Polymorphism: same interface, different behavior
		** - Virtual functions: enable runtime dispatch
		** - Now in CPP06: using virtual for type identification
		**
		** IMPLEMENTATION:
		** Empty body - destructor doesn't need to do anything
		** Presence of 'virtual' keyword is what matters
		** = default or {} are both acceptable
		*/
		virtual ~Base() {}

		/*
		** PROTECTED OR PUBLIC?
		** We keep it public because:
		** 1. Code using Base* needs to delete through base pointer
		** 2. Public destructor is standard practice
		** 3. Makes it clear this is meant to be a base class
		*/
};

#endif
