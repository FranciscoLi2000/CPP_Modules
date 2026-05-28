# CPP06 - C++ Casting Operators and Runtime Type Information

## Overview

CPP06 teaches advanced C++ concepts related to type conversion and runtime type identification. This module builds upon the knowledge from CPP00-CPP05, specifically leveraging inheritance, polymorphism, and exception handling learned in previous modules.

## Learning Progression

### From Previous Modules:
- **CPP00**: Basic classes, constructors, destructors
- **CPP01**: Pointers and references, memory allocation
- **CPP02**: Orthodox Canonical Form (OCF), operator overloading
- **CPP03**: Inheritance and polymorphic hierarchies
- **CPP04**: Abstract classes and virtual functions
- **CPP05**: Exception handling and custom exceptions
- **CPP06**: **HERE** - Type conversion (casting) and runtime type identification

### Key Concepts in CPP06

#### 1. **C++ Casting Operators** (vs C-style casts)

C++ provides four distinct casting operators, each with specific use cases:

##### `static_cast`
- **Use**: Convert between related types at compile time
- **Example**: `int x = static_cast<int>(3.14);`
- **Safety**: Checked at compile time; won't allow obviously wrong conversions
- **Speed**: Zero runtime overhead

##### `dynamic_cast`
- **Use**: Safe downcasting in polymorphic hierarchies with runtime checking
- **Example**: `Derived* d = dynamic_cast<Derived*>(base_ptr);`
- **Safety**: Returns NULL (pointers) or throws (references) if cast fails
- **Speed**: Runtime overhead for type checking (uses RTTI)

##### `reinterpret_cast`
- **Use**: Dangerous reinterpretation of binary representation
- **Example**: `uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);`
- **Safety**: No checking; programmer's responsibility
- **Speed**: Often zero overhead (just type reinterpretation)

##### `const_cast`
- **Use**: Add or remove const/volatile qualifiers
- **Example**: `const int* cp = ...; int* p = const_cast<int*>(cp);`
- **Safety**: Only removes qualifiers, doesn't change type
- **Speed**: Zero runtime overhead

#### 2. **RTTI (Runtime Type Information)**

Understanding what type an object really is at runtime:

- **Without RTTI**: Only the static type is known at compile time
  ```cpp
  Base* ptr = new Derived();  // ptr's static type is Base*
  // What's the actual type? Can't tell without RTTI
  ```

- **RTTI Methods**:
  - `typeid()`: Returns type information (requires `<typeinfo>` header)
  - `dynamic_cast`: Identifies type through casting attempts (no header needed)

#### 3. **Virtual Destructors**

Critical in inheritance hierarchies:

```cpp
// WRONG - without virtual destructor
class Base { public: ~Base() {} };
class Derived : public Base { public: ~Derived() {} };
Base* b = new Derived();
delete b;  // Only Base destructor called - memory leak!

// CORRECT - with virtual destructor
class Base { public: virtual ~Base() {} };
class Derived : public Base { public: virtual ~Derived() {} };
Base* b = new Derived();
delete b;  // Both Derived and Base destructors called - proper cleanup
```

**Rule**: If a class has any virtual functions or is meant to be inherited, give it a virtual destructor.

#### 4. **Serialization**

Converting objects or pointers to formats that can be stored/transmitted:

- **Pointer Serialization**: Converting memory addresses to integers
- **Round-trip Property**: Deserializing returns the exact same value
- **Use Case**: Persistence, network transmission, IPC

---

## Exercise Breakdown

### Exercise 00: Scalar Type Conversion

**File**: `ex00/`

**Concepts**:
- Static utility classes (private constructor, static methods)
- String parsing and type detection
- Using `static_cast` for safe type conversions
- Handling edge cases (overflow, special values like NaN/Inf)

**Key Classes**:
- `ScalarConverter`: Static-only class with one method

**Learning**: How to convert between different numeric types safely and handle special cases.

**Test It**:
```bash
cd ex00 && make
./convert 42        # Integer input
./convert 3.14f     # Float input
./convert "'c'"     # Character input
./convert nan       # Special value
```

---

### Exercise 01: Serialization

**File**: `ex01/`

**Concepts**:
- Data structures and member variables
- Using `reinterpret_cast` for pointer-to-integer conversion
- Understanding `uintptr_t` as a portable pointer-sized integer
- Round-trip verification (serialize → deserialize)
- Pointer semantics and memory addresses

**Key Classes**:
- `Data`: Simple struct to hold serializable data
- `Serializer`: Static-only class for pointer serialization

**Learning**: How pointers are just addresses (integers), and how to safely convert between representations.

**How It Works**:
```
Pointer (address): (Data*)0x12345678
    ↓ serialize() - reinterpret_cast to uintptr_t
Integer: 0x12345678
    ↓ deserialize() - reinterpret_cast back to pointer
Pointer (address): (Data*)0x12345678 ✓ Same!
```

**Test It**:
```bash
cd ex01 && make
./serializer    # Demonstrates round-trip serialization
```

---

### Exercise 02: Runtime Type Identification

**File**: `ex02/`

**Concepts**:
- Polymorphic class hierarchies
- Virtual destructors and vtables
- Using `dynamic_cast` for type identification
- Difference between pointer and reference casting
- Exception handling with `try-catch`

**Key Classes**:
- `Base`: Base class with virtual destructor
- `A`, `B`, `C`: Derived classes for type identification

**Key Functions**:
- `generate()`: Creates random derived object, returns as Base*
- `identify(Base*)`: Identifies type using dynamic_cast on pointers
- `identify(Base&)`: Identifies type using dynamic_cast on references

**Learning**: How to identify actual types at runtime without `<typeinfo>` header, using the polymorphic hierarchy.

**How It Works**:
```cpp
Base* ptr = new A();  // ptr is Base*, but points to A

// Identify using dynamic_cast
if (dynamic_cast<A*>(ptr) != NULL) cout << "Type is A\n";
if (dynamic_cast<B*>(ptr) != NULL) cout << "Type is B\n";  // Returns NULL
if (dynamic_cast<C*>(ptr) != NULL) cout << "Type is C\n";  // Returns NULL
```

**Test It**:
```bash
cd ex02 && make
./identify    # Shows random type identification
```

---

## Key Learning Takeaways

### 1. **Type Safety in C++**
C++ provides multiple casting operators for different safety levels:
- `static_cast`: Safe conversions
- `dynamic_cast`: Safe polymorphic conversions
- `reinterpret_cast`: Unsafe but necessary conversions
- `const_cast`: Qualifier changes

### 2. **Virtual Functions Enable RTTI**
Polymorphic behavior requires virtual functions, which create vtables that track the actual type of objects at runtime.

### 3. **Serialization Techniques**
- Pointers can be converted to integers and back (round-trip property)
- Useful for persistence, transmission, and language interop
- Must preserve exact address information

### 4. **Design Patterns**
- **Static Utility Class**: Private constructor prevents instantiation
- **Factory Pattern**: `generate()` creates objects of different types
- **Type Identification**: Using dynamic_cast instead of typeid()

### 5. **Memory Management**
- Virtual destructors ensure proper cleanup through inheritance hierarchies
- Not having them causes memory leaks in polymorphic scenarios

---

## Compilation and Testing

All exercises compile with:
```bash
g++ -Wall -Wextra -Werror -std=c++98
```

Build instructions:
```bash
cd CPP_Module_06/ex00 && make  # Compile ex00
cd CPP_Module_06/ex01 && make  # Compile ex01
cd CPP_Module_06/ex02 && make  # Compile ex02
```

Clean and rebuild:
```bash
make re
```

---

## Summary

CPP06 teaches advanced type manipulation and identification in C++. These concepts are fundamental to:
- Building safe, polymorphic systems
- Implementing serialization and persistence layers
- Creating interoperable C++ code
- Writing efficient, correct type conversions

By understanding casting operators and RTTI, you can write more robust C++ code that handles type information correctly and safely.
