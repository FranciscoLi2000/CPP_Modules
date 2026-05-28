/*
** TEACHING FILE - CPP06 ex01: Serializer Class
** 
** PURPOSE: Serialize and deserialize Data pointers using reinterpret_cast
**
** LEARNING GOALS:
** 1. Understanding reinterpret_cast - the most dangerous cast
** 2. Understanding pointer-to-integer conversion
** 3. Round-trip conversion verification
** 4. Static utility class pattern (like ex00's ScalarConverter)
**
** REINTERPRET_CAST EXPLANATION:
** 
** What is it?
** - Converts between completely unrelated types
** - Does NOT check type safety
** - Literally reinterprets the binary representation
** - Example: reinterpret_cast<int*>(0x12345678) treats that address as pointer
**
** When to use?
** - Serialization: converting pointer to integer
** - Low-level programming (hardware access)
** - Interfacing with C libraries
**
** Dangers:
** - Can lead to crashes or undefined behavior if misused
** - No type checking by compiler
** - "You're on your own" cast - use with care
**
** WHY NOT static_cast?
** - static_cast is for related types
** - Can't go from pointer to integer with static_cast
** - Must use reinterpret_cast for completely unrelated types
*/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>  /* For uintptr_t - C99 header (widely available in C++98) */

/*
** UINTPTR_T EXPLANATION:
** 
** What is it?
** - unsigned integer type that can hold any pointer value
** - Size matches the system's pointer size
** - 32 bits on 32-bit systems, 64 bits on 64-bit systems
**
** Why use it instead of unsigned long?
** - uintptr_t is guaranteed to hold a pointer's value
** - unsigned long might not be large enough on 64-bit systems
** - Makes code portable across different architectures
**
** Example:
** - 32-bit system: uintptr_t is 32-bit unsigned int
** - 64-bit system: uintptr_t is 64-bit unsigned long long
**
** LEARNING FROM CPP01:
** - Pointers store memory addresses as integers
** - Serialization exploits this: pointer IS an integer in memory
** - We can convert back and forth between representations
*/

class Serializer
{
	private:
		/*
		** PRIVATE CONSTRUCTOR:
		** 
		** Same pattern as ScalarConverter in ex00
		** This is a utility class, not meant to be instantiated
		** Forces static method usage: Serializer::serialize(ptr)
		**
		** WHY THIS PATTERN?
		** - No state to store (instance variables)
		** - Utility functions should be static
		** - Follows C++ best practices for helper classes
		*/
		Serializer();

		/* Copy constructor and assignment operator */
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &);

		/* Destructor */
		~Serializer();

	public:
		/*
		** SERIALIZE FUNCTION:
		**
		** PURPOSE: Convert a Data pointer to an unsigned integer
		**
		** PARAMETER:
		** - const Data* ptr: pointer to Data object to serialize
		**
		** RETURN:
		** - uintptr_t: the pointer value as an unsigned integer
		**
		** CASTING DECISION - WHY REINTERPRET_CAST?
		** 
		** Syntax: reinterpret_cast<uintptr_t>(ptr)
		**
		** Why reinterpret_cast and not static_cast?
		** - Pointer and integer are unrelated types
		** - static_cast: for related types (derived to base, int to double, etc)
		** - reinterpret_cast: for unrelated types
		** - This is the only cast that can convert pointer to integer
		**
		** What happens under the hood?
		** - Memory address is already stored as binary number in the pointer
		** - reinterpret_cast just reinterprets those bytes as uintptr_t
		** - No actual data transformation, just view change
		**
		** Safety:
		** - As long as we deserialize with the same reinterpret_cast, we're safe
		** - This is safe for serialization because we know what we're doing
		** - reinterpret_cast is needed here because type systems differ
		*/
		static uintptr_t serialize(Data *ptr);

		/*
		** DESERIALIZE FUNCTION:
		**
		** PURPOSE: Convert an unsigned integer back to a Data pointer
		**
		** PARAMETER:
		** - uintptr_t raw: the serialized integer value
		**
		** RETURN:
		** - Data*: pointer to the deserialized object
		**
		** ROUND-TRIP PROPERTY:
		** - If you do: ptr -> serialize -> deserialize
		** - You get back the exact same ptr value
		** - This is what we verify in main.cpp
		**
		** CASTING DECISION - WHY REINTERPRET_CAST?
		** 
		** Syntax: reinterpret_cast<Data*>(raw)
		**
		** Inverse of serialize:
		** - Takes integer and converts back to pointer
		** - Again, must use reinterpret_cast
		** - Only cast that can convert integer to pointer
		**
		** Verification Test:
		** - Original pointer = (Data*)0x1234abcd
		** - Serialized value = 0x1234abcd (as uint)
		** - Deserialized pointer = (Data*)0x1234abcd (should match original)
		*/
		static Data *deserialize(uintptr_t raw);
};

#endif
