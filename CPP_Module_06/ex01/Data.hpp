/*
** TEACHING FILE - CPP06 ex01: Data Structure for Serialization
** 
** PURPOSE: Define a data structure to be serialized/deserialized
**
** LEARNING POINTS:
** 1. Structs in C++ (similar to classes but public by default)
** 2. Member variables and their memory representation
** 3. Why we need this for serialization testing
**
** LEARNING FROM PREVIOUS MODULES:
** - CPP00-CPP02: Classes and their structure
** - CPP06: Now learning about serialization (converting objects to other formats)
*/

#ifndef DATA_HPP
#define DATA_HPP

#include <cstddef>  /* For NULL and size_t */

/*
** DATA STRUCT:
** 
** PURPOSE:
** A simple data structure that will be instantiated and then serialized.
** We serialize its address (pointer) to an integer, then deserialize back.
**
** WHY STRUCT INSTEAD OF CLASS?
** - Struct is simpler, more like a data container
** - In C++, struct and class are almost identical
**   (main difference: struct members are public by default)
**
** MEMBER VARIABLES:
** We include different types to show that this is a "real" object with data
** When we serialize the pointer, these members will still exist in memory
**
** MEMORY LAYOUT:
** Data object in memory looks like:
** [value: 4 bytes for int][name: N bytes for char array]
** The address of this memory block is what we serialize/deserialize
*/
struct Data
{
	/*
	** INT MEMBER:
	** Typically 4 bytes on most systems
	** Demonstrates that Data is a non-empty structure
	*/
	int value;

	/*
	** CHAR POINTER MEMBER:
	** Pointer to dynamically allocated string
	** 8 bytes on 64-bit systems, 4 bytes on 32-bit systems
	** 
	** LEARNING POINT:
	** Even though this is a pointer, the Data structure itself
	** has a defined size and address that we can serialize
	*/
	char *name;

	/*
	** CONSTRUCTOR:
	** Initialize members to reasonable defaults
	**
	** WHY INITIALIZE?
	** - Prevents undefined behavior
	** - We want a "real" object to serialize
	** - Good practice from CPP00/CPP02
	*/
	Data() : value(42), name(NULL) {}

	/*
	** DESTRUCTOR:
	** Cleanup dynamically allocated memory
	**
	** LEARNING FROM CPP02:
	** - This is part of the Orthodox Canonical Form (OCF)
	** - Clean up resources to prevent memory leaks
	** - Important when using new/delete
	*/
	~Data()
	{
		if (name != NULL)
		{
			delete[] name;
			name = NULL;
		}
	}
};

#endif
