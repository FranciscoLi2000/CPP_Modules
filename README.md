# 42 Barcelona C++ Modules — Learning Journey (CPP_Module_00 to CPP_Module_09)

This repository contains my solutions and learning notes for the 42 Barcelona C++ Modules.
I built it as a structured path to move from a C mindset toward solid C++ programming, step by step.

The goal here is not only to pass exercises, but to understand core language fundamentals, object-oriented design, memory and resource management, and practical C++ problem solving.
Some parts were completed with AI-assisted vibecoding support, but the focus has always been on understanding the concepts behind the code.

---

## What I Needed to Know Before Starting

Before these modules, it helped a lot to already be comfortable with:

- Variables, loops, conditions, and functions
- Pointers and references
- Arrays, strings, and dynamic memory in C
- `struct` usage and modular programming in C
- Basic compilation with `g++`
- A debugging mindset: reading compiler errors carefully and iterating patiently

At the same time, these modules introduced (or deepened) key C++ topics:

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

If you come from C, this path is demanding but very doable with consistent practice.

---

## What This C++ “Piscina” Teaches

Completing these modules builds both technical skills and programming maturity:

- Thinking in objects instead of only procedures
- Understanding value semantics vs reference and pointer semantics
- Managing resources more safely and predictably
- Writing cleaner, more maintainable, and more modular code
- Improving debugging habits and problem decomposition
- Choosing better abstractions for real problems

In short, it bridges the gap between “I can write C code” and “I can design C++ code.”

---

## Module-by-Module Learning Value (High Level)

Without spoiling exercise solutions, the modules roughly progress like this:

- **Early modules (00–02):**
  C++ syntax foundations, classes, constructors and destructors, canonical form, basic object behavior, operator overloading, and early resource management patterns.

- **Middle modules (03–06):**
  Inheritance, polymorphism, abstract interfaces, exceptions, deeper OOP modeling, and cleaner class architecture under stricter constraints.

- **Later modules (07–09):**
  Templates, generic programming mindset, STL containers, iterators and algorithms, and writing reusable components with stronger type safety and abstraction.

The sequence is progressive on purpose: each module builds on habits learned in previous ones.

---

## What I Can Do After Finishing These Modules

After this track, good next steps are:

- Build small but complete C++ projects
- Use STL confidently in practical code
- Study RAII and smart pointers more deeply
- Learn modern C++ features (C++11/14/17/20)
- Practice algorithmic problem solving in C++
- Build CLI tools, mini-games, simulations, or utility libraries
- Prepare for internships, interviews, and real backend or system programming work

---

## Real-World Applications of This Knowledge

These concepts are directly useful for:

- Writing safer and cleaner application code
- Building software that is easier to maintain long-term
- Designing reusable classes and components
- Handling memory and resources correctly while avoiding common leaks and bugs
- Working on backend services, tools, game logic, or system utilities

Even when you later use higher-level frameworks, these fundamentals continue to matter.

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

Each module folder contains its corresponding exercises and source code.

---

## Build / Compile Information

Most exercises include a `Makefile`, but you can also compile manually in a generic way:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

Or with `g++`:

```bash
g++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

> Adjust source files and output name depending on the exercise directory.

---

## Learning Notes / Personal Reflections

For me, this repository is more than a list of completed tasks.
It reflects the transition from “making code work” to understanding *why* certain C++ patterns are safer, clearer, and more scalable.

The hardest part was often not syntax, but mindset: learning to design classes carefully, reason about ownership and lifetimes, and treat compiler feedback as a tool instead of a blocker. That shift made a big difference in how I approach software engineering overall.

---

## Conclusion

The 42 C++ Modules gave me a strong foundation in core C++ and a more professional way of thinking about code structure, safety, and maintainability.
If you are coming from C, this path is an excellent way to build real confidence in C++ step by step.
