/*
** TEACHING FILE - CPP06 ex02: Derived Class B
** 
** PURPOSE: Second derived class inheriting from Base
** 
** SAME STRUCTURE AS CLASS A:
** - Inherits from Base
** - Empty implementation (just a marker)
** - Uses Base's virtual destructor
** 
** POLYMORPHIC HIERARCHY:
**          Base
**          / | \
**         A  B  C
** 
** All inherit from Base
** All can be handled as Base pointers
** Dynamic_cast identifies which actual type
*/

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
	/* Empty class - just for type identification */
};

#endif
