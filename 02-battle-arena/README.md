# Project 02 - Battle Arena

A command-line battle arena application.

---

## Features

The application allows the user to:

* Create character class
* Display created characters
* Battle
* Display character status

---

## Concepts

This project will practice and combine concepts such as:

* Classes
* Encapsulation
* Constructors
* Polymorphism
* `std::vector`
* `std::string`
* Functions
* References
* `const`
* Control flow
* Range-based `for`
* STL algorithms
* `auto`

---

## Requirements

* C++20
* CMake 3.20 or later
* GCC / MinGW

---

## Constraints

* Use a polymorphic collection.
* Do not create a separate collection for each derived class.
* Implement overrides correctly.
* Use the virtual destructor in the base class.

---

## Build

The project uses CMake.

```bash
cmake -S . -B build -G "MinGW Makefiles"

cmake --build build
```

Git Bash:

```bash
./build/battle-area.exe
```

---

## Status

🚧 In progress
