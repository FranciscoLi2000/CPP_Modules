# CPP_Module_07: C++ Templates

## Overview

This module introduces **C++ Templates**, the most powerful feature of modern C++ for generic programming. Templates allow you to write code once and have the compiler automatically generate versions for different types at compile time.

### Key Learning Progression

**From CPP00-06 to CPP07:**
- **CPP00-01**: Basic C++ syntax, pointers, memory management
- **CPP02-04**: Object-oriented programming, inheritance, polymorphism (runtime)
- **CPP05-06**: Exception handling, type casting
- **CPP07**: Generic programming with templates (compile-time polymorphism)

## What are Templates?

### Function Templates vs Class Templates

**Function Templates** (ex00, ex01):
- Generic functions that work with any type
- Compiler generates code for each type used
- Zero runtime overhead

**Class Templates** (ex02):
- Generic classes that work with any type
- More complex: manage state and resources
- Combine OCF (Orthodox Canonical Form) with templates

### Why Use Templates?

1. **Type Safety**: Caught at compile time, not runtime
2. **Performance**: Zero overhead - compiler inlines optimized code for each type
3. **Code Reuse**: Write once, use with infinite types
4. **Contrast with Inheritance**: Templates are compile-time; inheritance is runtime

## Exercise Breakdown

### Exercise 00: Function Templates (swap, min, max)

**Concepts:**
- Basic function template syntax
- Template parameter deduction
- Generic programming with operators (<, >)
- Instantiation: compiler generates code for each type

**What You Learn:**
- Templates can replace function overloading
- Works with built-in types (int, float) seamlessly
- Works with library types (std::string)
- Works with custom classes (if they support required operators)

**Key Files:**
- `template.hpp`: Three function templates with extensive teaching comments
- `main.cpp`: Tests with int and std::string types

**Teaching Comments Explain:**
- Why swap needs references (to modify originals)
- Why min/max return by value (not reference)
- How template instantiation works
- Trade-offs: benefits vs code bloat vs compilation time

### Exercise 01: Function Templates with Callbacks (iter)

**Concepts:**
- Function pointers as template parameters
- Generic algorithms (foundation of STL)
- Higher-order functions
- Template deduction with function signatures

**What You Learn:**
- Templates work with function pointers
- Type safety: function signature must match template parameter
- Generic algorithms pattern (used throughout STL)
- Separation of data (array) from operations (callback)

**Key Files:**
- `iter.hpp`: Template function taking array, size, and callback function pointer
- `main.cpp`: Tests with int, float, std::string arrays and different callbacks

**Teaching Comments Explain:**
- Function pointer syntax and what each part means
- Why dereference (*func) is needed
- How template deduction works with function pointers
- Connection to std::for_each and STL algorithms

### Exercise 02: Class Templates (Array)

**Concepts:**
- Class templates vs function templates
- Combining OCF with templates
- Dynamic memory management with new[]
- Exception handling in templates
- Bounds checking and type safety

**What You Learn:**
- Class templates manage state (element array, size)
- OCF (Orthodox Canonical Form) is critical:
  - Default constructor: create empty array
  - Sized constructor: allocate for n elements
  - Copy constructor: deep copy (prevent memory sharing)
  - Assignment operator: deep copy with self-assignment check
  - Destructor: cleanup with delete[]
- Deep copy prevents dangling pointers and memory corruption
- Exception handling: bounds checking throws std::exception
- Works with any type (int, float, std::string, custom classes)

**Key Files:**
- `Array.hpp`: Class template declaration with comprehensive comments
- `Array.tpp`: Class template implementation (included by header)
- `main.cpp`: Complete test suite demonstrating all features

**Teaching Comments Explain:**
- Why every pointer member needs a corresponding delete[]
- Why copy constructor must allocate new memory (not share)
- Why assignment operator needs self-assignment check
- How member initializer lists work
- How template instantiation differs between types
- Connection to std::vector and Standard Template Library

## Building and Running

```bash
# Build and run each exercise
cd ex00 && make && ./template_test
cd ../ex01 && make && ./iter_test
cd ../ex02 && make && ./array_test
```

## Compilation Requirements

- **Compiler**: c++ (g++, clang++, etc.)
- **Flags**: `-Wall -Wextra -Werror -std=c++98`
- **C++ Standard**: C++98 (no C++11 features)

## Concepts Review

### Template Instantiation

When you use a template:

```cpp
swap(5, 10);              // Compiler generates swap<int>
swap("hello", "world");   // Compiler generates swap<const char*>
```

Each type gets its own copy of the template code!

### Compile-Time vs Runtime Polymorphism

**Templates (Compile-Time):**
```cpp
template <typename T> void func(T x) { ... }
func(5);      // Compiler generates func<int>
func(5.5);    // Compiler generates func<double>
```
- Type errors caught at compile time
- Zero runtime overhead
- Code is instantiated for each type (code bloat)

**Inheritance (Runtime):**
```cpp
class Base { virtual void func() { ... } };
class Derived : public Base { void func() { ... } };
Base* obj = new Derived();
obj->func();  // Virtual function call at runtime
```
- Type errors caught at runtime (polymorphism)
- Virtual call overhead
- Shared code (no duplication)

## Memory Management in Templates

### RAII Principle: Resource Acquisition Is Initialization

Template classes must follow RAII to prevent leaks:

1. **Constructor acquires resources** (allocates memory)
2. **Destructor releases resources** (frees memory)
3. **Copy constructor/operator** create independent copies
4. **Exception safe**: even if exception thrown, destructor runs

This is why OCF is critical - it's not optional!

## Common Pitfalls

### Shallow Copy (WRONG):
```cpp
template <typename T>
Array<T>::Array(const Array<T>& other) : _data(other._data) { }
// BUG: Both arrays point to same memory!
```

### Correct Deep Copy:
```cpp
template <typename T>
Array<T>::Array(const Array<T>& other) : _data(new T[other._size]) {
    // Allocate new memory, copy elements
}
```

### Missing Self-Assignment Check (BAD):
```cpp
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    delete[] _data;  // If other is this, deletes our memory!
    // ...
}
```

### Correct Self-Assignment Check:
```cpp
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _data;
        // ...
    }
    return *this;
}
```

## Teaching Comments Throughout

Every file includes extensive comments explaining:

1. **What** the code does
2. **Why** it's written this way
3. **How** it relates to previous CPP modules
4. **Alternatives** and trade-offs
5. **Common mistakes** to avoid
6. **Generic programming** concepts

This module is designed as a complete learning resource, not just working code.

## Connection to C++ Standard Library

The techniques in this module are the foundation for:

- **std::vector<T>**: Dynamic array template
- **std::list<T>**: Linked list template
- **std::map<K,V>**: Hash map template
- **std::algorithm**: Generic algorithms
- **std::iterator**: Iterator pattern

Understanding these templates prepares you for CPP08-09 where you'll use STL extensively.

## Summary

**CPP07 teaches you that:**

1. Templates enable generic programming
2. Compile-time polymorphism (templates) vs runtime (inheritance)
3. OCF is essential for resource management
4. Deep copy prevents memory corruption
5. Exception handling works with templates
6. Templates are the foundation of modern C++

You now understand the core mechanism that makes C++ both powerful and complex!

---

**Module Status**: ✓ Complete with comprehensive teaching comments

**Next Step**: CPP08 - Introduction to the Standard Template Library (STL)
