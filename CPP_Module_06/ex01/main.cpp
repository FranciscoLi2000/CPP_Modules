/*
** TEACHING FILE - main.cpp for ex01: Serialization Testing
** 
** PURPOSE: Demonstrate serialization and deserialization in action
**
** TEST FLOW:
** 1. Create a Data object
** 2. Get its pointer
** 3. Serialize the pointer to integer
** 4. Deserialize the integer back to pointer
** 5. Verify they match
**
** LEARNING POINTS:
** - How to use static methods (Serializer::serialize, Serializer::deserialize)
** - Round-trip property verification
** - Pointer arithmetic and comparison
** - Memory layout of objects
**
** EXPECTED OUTPUT:
** Data object created with address: 0x...
** Serialized as integer: ...
** Deserialized back to pointer: 0x...
** Pointers match: true/false
** Data value in object: 42
*/

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	/*
	** CREATE DATA OBJECT:
	** 
	** new Data() allocates memory on the heap for a Data object
	** Returns a pointer to that memory location
	**
	** LEARNING FROM CPP01:
	** - Pointers store memory addresses
	** - new allocates memory and returns its address
	** - Must use delete to free memory (we don't here for simplicity)
	**
	** OBJECT LAYOUT IN MEMORY:
	** The Data object contains:
	** - int value (4 bytes)
	** - char* name (8 or 4 bytes depending on architecture)
	** - Occupies specific address in heap memory
	**
	** EXAMPLE MEMORY ADDRESS:
	** dataPtr might be something like 0x7fff5fbff8c0
	** This is what we'll serialize
	*/
	Data *dataPtr = new Data();

	/*
	** INITIALIZE DATA MEMBERS:
	** 
	** WHY INITIALIZE?
	** - Demonstrates that this is a "real" object with data
	** - Shows that object's internal state persists
	** - Even after serialization/deserialization
	*/
	dataPtr->value = 42;
	dataPtr->name = new char[6];
	dataPtr->name[0] = 'H';
	dataPtr->name[1] = 'e';
	dataPtr->name[2] = 'l';
	dataPtr->name[3] = 'l';
	dataPtr->name[4] = 'o';
	dataPtr->name[5] = '\0';

	/*
	** DISPLAY ORIGINAL POINTER:
	** 
	** std::hex: hexadecimal output (like 0x7fff...)
	** std::showbase: displays 0x prefix
	** (void*): cast to void pointer for display
	**
	** WHY DISPLAY?
	** - Show the memory address we're working with
	** - Verify it doesn't change through serialization
	*/
	std::cout << "Original pointer address: " << std::hex << std::showbase << (void*)dataPtr << std::dec << std::endl;
	std::cout << "Data value: " << dataPtr->value << std::endl;
	std::cout << "Data name: " << dataPtr->name << std::endl;
	std::cout << std::endl;

	/*
	** SERIALIZE THE POINTER:
	** 
	** Serializer::serialize(dataPtr)
	**
	** WHAT IT DOES:
	** - Takes the pointer (memory address)
	** - Converts it to an unsigned integer using reinterpret_cast
	** - Returns the same address, but as a number
	**
	** EXAMPLE:
	** - Input pointer: (Data*)0x12345678
	** - Serialized: 0x12345678 as uintptr_t
	** - Binary representation: unchanged
	** - Just a different way of viewing the same value
	**
	** WHY SERIALIZE?
	** - Send object address over network (address becomes data)
	** - Store in database (pointers aren't persistent)
	** - Pass through systems that only handle integers
	** - Then recover the pointer later with deserialize
	**
	** LEARNING FROM CPP05:
	** - Exception handling (not used here in C++98)
	** - Static methods (like ex00's ScalarConverter)
	** - Class design patterns (utility class with private constructor)
	*/
	uintptr_t serialized = Serializer::serialize(dataPtr);

	/*
	** DISPLAY SERIALIZED VALUE:
	** 
	** Show the integer representation of the pointer
	** This is what would be stored or transmitted
	*/
	std::cout << "Serialized value (as integer): " << std::hex << std::showbase << serialized << std::dec << std::endl;
	std::cout << std::endl;

	/*
	** DESERIALIZE BACK TO POINTER:
	** 
	** Serializer::deserialize(serialized)
	**
	** WHAT IT DOES:
	** - Takes the unsigned integer
	** - Converts it back to Data* pointer using reinterpret_cast
	** - Returns a pointer to the same memory address
	**
	** ROUND-TRIP PROPERTY:
	** - This should equal the original dataPtr
	** - Same memory address, same object
	** - Object's data is unchanged
	**
	** HOW DOES IT WORK?
	** - reinterpret_cast just changes the type label
	** - Binary bits remain identical
	** - Like relabeling a container: "integer" -> "pointer"
	**
	** SAFETY CONSIDERATION:
	** - Only safe if serialized value came from serialize()
	** - If random integer is deserialized, could crash program
	** - This is why reinterpret_cast is dangerous but needed here
	*/
	Data *deserialized = Serializer::deserialize(serialized);

	/*
	** DISPLAY DESERIALIZED POINTER:
	** 
	** Should match original pointer address
	*/
	std::cout << "Deserialized pointer address: " << std::hex << std::showbase << (void*)deserialized << std::dec << std::endl;
	std::cout << "Data value: " << deserialized->value << std::endl;
	std::cout << "Data name: " << deserialized->name << std::endl;
	std::cout << std::endl;

	/*
	** VERIFICATION: ROUND-TRIP TEST
	** 
	** TEST: Do the pointers match?
	** 
	** EXPECTED:
	** - deserialized == dataPtr (should be true)
	** - They point to the same memory location
	** - The exact same Data object
	**
	** IF THEY MATCH:
	** - Serialization worked perfectly
	** - Proof that pointer was correctly stored as integer and restored
	** - Binary representation preserved throughout process
	**
	** LEARNING POINT - WHY THIS MATTERS:
	** - Demonstrates that pointers ARE integers at hardware level
	** - Shows practical application of reinterpret_cast
	** - Proves serialization round-trip property
	**
	** IF THEY DON'T MATCH:
	** - Something went wrong in serialization/deserialization
	** - Could indicate issue with reinterpret_cast implementation
	** - Could indicate platform-specific problem
	*/
	if (deserialized == dataPtr)
	{
		std::cout << "SUCCESS: Pointers match! Round-trip serialization successful." << std::endl;
		std::cout << "This proves that pointer value was preserved through serialization." << std::endl;
		std::cout << "Binary representation of address: unchanged" << std::endl;
	}
	else
	{
		std::cout << "ERROR: Pointers don't match!" << std::endl;
		std::cout << "Serialization/deserialization failed." << std::endl;
	}

	/*
	** CLEANUP:
	** 
	** Delete allocated memory to prevent memory leak
	**
	** LEARNING FROM CPP02:
	** - Orthodox Canonical Form (OCF)
	** - Destructor responsibility to clean up
	** - Explicit memory management with new/delete
	**
	** OUR CLEANUP:
	** - dataPtr's destructor will be called when we delete
	** - It will clean up the name string
	** - Then dataPtr itself is freed
	**
	** NOTE:
	** - dataPtr and deserialized point to same object
	** - Only delete once, otherwise double-free error
	*/
	delete dataPtr;
	// Don't delete deserialized - it points to same object!

	return 0;
}
