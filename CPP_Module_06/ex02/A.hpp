/*
** TEACHING FILE - CPP06 ex02: Derived Class A
** 
** PURPOSE: Simple derived class inheriting from Base
**
** LEARNING POINTS:
** 1. Inheritance syntax: class A : public Base
** 2. "public" keyword in inheritance
** 3. Derived classes and polymorphism
** 4. Empty classes (can still have functionality through inheritance)
**
** PUBLIC INHERITANCE:
** - Means A "IS-A" Base
** - All public members of Base are public in A
** - Can safely treat A* as Base*
**
** EMPTY CLASSES:
** - In C++, even empty classes have size (usually 1 byte)
** - This ensures each object has unique address in memory
** - Useful for templates and object tracking
**
** WHY EMPTY?
** - These are marker classes
** - Used to identify type at runtime (ex02's purpose)
** - Dynamic_cast will tell us which derived type it is
**
** FOR IDENTIFICATION:
** When we have a Base* pointing to A object:
** - dynamic_cast<A*>(base_ptr) will succeed
** - dynamic_cast<B*>(base_ptr) will return NULL
** - dynamic_cast<C*>(base_ptr) will return NULL
** This is how we identify the real type without typeinfo header
*/

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

/*
** CLASS A: Derived from Base
** 
** INHERITANCE SYNTAX: class A : public Base
** 
** WHAT THIS MEANS:
** - A is derived from Base
** - "public" specifies inheritance type (could be private or protected)
** - A inherits all members and methods from Base
** - A "IS-A" Base (can be used wherever Base* is expected)
**
** VIRTUAL DESTRUCTOR:
** - Inherited from Base
** - A doesn't override it (doesn't need to)
** - Base's virtual destructor is sufficient
** - If A had member pointers/allocations, we'd need custom destructor
**
** POLYMORPHIC BEHAVIOR:
** - A objects can be handled as Base pointers
** - Virtual destructor ensures proper cleanup
** - Dynamic_cast can identify A at runtime
*/
class A : public Base
{
	/*
	** EMPTY CLASS BODY:
	** - No additional methods
	** - No additional member variables
	** - Just a marker to differentiate from B and C
	**
	** LEGAL IN C++:
	** - Classes can be completely empty
	** - Still usable for inheritance and polymorphism
	** - Still have vtable (because derived from Base with virtual destructor)
	*/
};

#endif
