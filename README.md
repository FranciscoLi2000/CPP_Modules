# 42 Barcelona C++ Modules (CPP_Module_00 → CPP_Module_09)

This repository contains my solutions and learning notes for the 42 Barcelona C++ Modules. I treated the modules as a structured path to move from a C mindset toward solid, modern C++ thinking, step by step. The focus is on understanding language fundamentals, object-oriented programming, memory management, and practical problem solving in C++.

Some parts were completed with AI-assisted vibecoding, but the goal has always been to *understand* the reasoning behind each exercise and build real C++ intuition.

---

## What I Needed to Know Before Starting

These modules assume you already have a basic C foundation. Before starting, it helped a lot to be comfortable with:

- Variables, loops, conditions, and functions
- Pointers and references
- Arrays, strings, and dynamic memory
- `struct` usage and basic modular programming in C
- Compiling with `g++`
- A debugging mindset (reading compiler errors and iterating patiently)

At the same time, the modules introduce or deepen important C++ topics:

- Classes and objects
- Constructors and destructors
- Encapsulation
- Inheritance and polymorphism
- Operator overloading
- Templates
- Exceptions
- STL basics (containers, iterators, algorithms)
- `const` correctness
- Namespaces
- Streams and file I/O

If you’re coming from C, the learning curve is real—but this track is designed to make it manageable.

---

## What This C++ “Piscina” Teaches

Completing the modules builds both technical ability and programming maturity:

- Thinking in objects instead of only procedures
- Understanding value semantics vs reference/pointer semantics
- Managing resources safely and predictably
- Writing cleaner, more maintainable code
- Building stronger debugging and problem-solving habits
- Improving code organization and abstraction

Overall, it bridges the gap between “I can write C” and “I can design C++.”

---

## Module-by-Module Learning Value (High Level)

Without giving away solutions, the modules roughly evolve like this:

- **Early modules (00–02):**
  C++ syntax foundations, classes, constructors/destructors, canonical form, operator overloading, and early resource management.

- **Middle modules (03–06):**
  Inheritance, polymorphism, abstract classes, exceptions, and clearer OOP design under stricter constraints.

- **Later modules (07–09):**
  Templates, generic programming mindset, STL containers/iterators/algorithms, and reusable component design.

Each step builds habits that make the next module more natural.

---

## What I Can Do After Finishing These Modules

After completing this track, good next steps include:

- Writing small, complete C++ projects
- Using the STL confidently in real code
- Learning smart pointers and RAII more deeply
- Exploring modern C++ features (C++11/14/17/20)
- Practicing algorithmic problem solving
- Building CLI tools, mini-games, simulations, or small libraries
- Preparing for internships, interviews, or real backend/system programming

---

## Real-World Applications of the Knowledge

These concepts translate directly to practical work:

- Writing safer and cleaner application code
- Building maintainable software over time
- Designing reusable components
- Handling resources correctly and avoiding leaks
- Working on backend services, tools, game logic, or system utilities

Even when using higher-level frameworks, these fundamentals keep paying off.

---

## Repository Structure

```text
CPP_Module_00/
CPP_Module_01/
CPP_Module_02/
CPP_Module_03/
CPP_Module_04/
CPP_Module_05/
CPP_Module_06/
CPP_Module_07/
CPP_Module_08/
CPP_Module_09/
```

Each folder contains the corresponding exercises and source code for that module.

---

## Build / Compile Information

Most exercises include a `Makefile`, but you can also compile manually with a generic command like:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

Or with `g++`:

```bash
g++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

> Adjust the source files and output name depending on the exercise directory.

---

## Learning Notes / Personal Reflections

This repository is more than a checklist of finished exercises. It reflects the shift from “making code work” to understanding *why* certain C++ patterns are safer, clearer, and more scalable. The hardest part was often mindset: designing classes carefully, reasoning about ownership and lifetimes, and treating compiler feedback as guidance rather than noise. That shift shaped how I approach software engineering overall.

---

## Conclusion

The 42 C++ Modules gave me a strong foundation in core C++ and a more professional way of thinking about design, safety, and maintainability. If you’re coming from C, this is a solid path to build real confidence in C++ step by step.
