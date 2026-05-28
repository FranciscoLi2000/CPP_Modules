/*
** TEACHING FILE - Serializer.cpp Implementation
** 
** LEARNING GOALS:
** 1. Implementing reinterpret_cast for pointer-integer conversion
** 2. Understanding how pointers and integers are related at hardware level
** 3. Round-trip serialization verification
*/

#include "Serializer.hpp"

/*
** PRIVATE CONSTRUCTOR:
** Empty - just prevents instantiation
**
** EXECUTION:
** This is never called because class is not instantiable
*/
Serializer::Serializer() {}

/*
** COPY CONSTRUCTOR:
** Empty - never called due to private access
*/
Serializer::Serializer(const Serializer &) {}

/*
** ASSIGNMENT OPERATOR:
** Empty - never called due to private access
*/
Serializer &Serializer::operator=(const Serializer &) { return *this; }

/*
** DESTRUCTOR:
** Empty private destructor for explicit declaration
*/
Serializer::~Serializer() {}

/*
** SERIALIZE IMPLEMENTATION:
**
** PURPOSE: Convert Data pointer to unsigned integer
**
** DETAILED EXPLANATION:
** 
** Pointers in memory:
** - A pointer is just an address (a number)
** - On 32-bit systems: address is 32-bit (0 to 4GB)
** - On 64-bit systems: address is 64-bit (0 to 16EB)
**
** Storage:
** - A pointer like (Data*)0x12345678 stores the address 0x12345678
** - This is stored as binary: 00010010 00110100 01010110 01111000
** - The binary representation is already an integer!
**
** Serialization:
** - Take the Data* pointer (which contains an address)
** - Reinterpret its binary representation as uintptr_t
** - Both contain the same binary value, just viewed differently
**
** uintptr_t:
** - Guaranteed to be able to hold any pointer value
** - On 64-bit: unsigned long long (64 bits)
** - On 32-bit: unsigned int (32 bits)
**
** CASTING WITH reinterpret_cast:
** 
** Syntax: reinterpret_cast<TargetType>(value)
**
** Example: reinterpret_cast<uintptr_t>(ptr)
** - This literally says: "Take ptr's binary representation, interpret it as uintptr_t"
** - No conversion function is called
** - No validation is done
** - Pure binary reinterpretation
**
** WHY NOT static_cast?
** - static_cast is for type-safe conversions
** - Converting unrelated types (pointer to integer) isn't "type-safe"
** - Compiler would reject static_cast<uintptr_t>(ptr)
** - MUST use reinterpret_cast for pointer-integer conversions
**
** IMPLEMENTATION:
*/
uintptr_t Serializer::serialize(Data *ptr)
{
	/*
	** REINTERPRET CAST: Pointer to Integer
	**
	** What it does:
	** - Takes the pointer value (memory address)
	** - Reinterprets its binary form as uintptr_t
	** - Returns the same bits, different type
	**
	** Example execution (hypothetical 32-bit):
	** - Input: ptr = (Data*)0xDEADBEEF
	** - Output: 0xDEADBEEF as uintptr_t
	**
	** Safety in this context:
	** - We're storing an address as a number
	** - We have the complementary deserialize() to convert back
	** - This is the intended use of reinterpret_cast
	**
	** The const_cast is not needed here because ptr is already non-const
	** But we explicitly show the cast for learning
	*/
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
** DESERIALIZE IMPLEMENTATION:
**
** PURPOSE: Convert unsigned integer back to Data pointer
**
** REVERSE OPERATION:
** - serialize: Data* -> uintptr_t
** - deserialize: uintptr_t -> Data*
** - Should be exact inverse (round-trip property)
**
** GUARANTEE (if used correctly):
** Data *original = new Data();
** uintptr_t serialized = Serializer::serialize(original);
** Data *deserialized = Serializer::deserialize(serialized);
** // original == deserialized (always true)
**
** REINTERPRET_CAST BACK:
**
** Syntax: reinterpret_cast<Data*>(raw)
**
** What it does:
** - Takes the uintptr_t value (an integer)
** - Interprets its binary form as a Data* pointer
** - Returns a pointer with the same address value
**
** Example (hypothetical 32-bit):
** - Input: raw = 0xDEADBEEF (as uintptr_t)
** - Output: (Data*)0xDEADBEEF
**
** Round-trip Property:
** - If raw came from serialize(), this will give us back the original pointer
** - Binary representation is preserved exactly
**
** LEARNING POINT - WHY THIS WORKS:
** - Pointers ARE integers at the hardware level
** - They're just memory addresses
** - reinterpret_cast just changes the type label
** - The actual data (the address) never changes
*/
Data *Serializer::deserialize(uintptr_t raw)
{
	/*
	** REINTERPRET CAST: Integer to Pointer
	**
	** Going from integer back to pointer
	** Uses the same binary bits, just changes the type view
	**
	** Safety notes:
	** - If raw didn't come from serialize(), this could be dangerous
	** - The pointer might not point to valid memory
	** - Could lead to segmentation fault if dereferenced
	** - But for serialization/deserialization, it's intended and safe
	*/
	return reinterpret_cast<Data *>(raw);
}
