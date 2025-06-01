# Key Learnings from the Module

## 1. Core C++ Concepts:
- **Subtype Polymorphism:** Leveraging inheritance and virtual functions for flexible and reusable class hierarchies.
- **Abstract Classes and Interfaces:** Using pure virtual functions to define behavior that must be implemented by derived classes.
- **Dynamic Memory Management:** Properly managing memory in complex hierarchies to avoid leaks.
- **Deep Copies:** Ensuring proper duplication of dynamically allocated resources to maintain data integrity.

## 2. Practical Applications:

- **Exercise 00 (Polymorphism):**
  - Implementing an `Animal` base class and derived classes (`Dog`, `Cat`, `WrongAnimal`, `WrongCat`).
  - Demonstrating polymorphism through virtual functions like `makeSound()`.
  - Testing subtype behavior with base class pointers to derived objects.

- **Exercise 01 (I don’t want to set the world on fire):**
  - Adding a `Brain` class to model internal state with a private dynamic array.
  - Using deep copies to duplicate objects without shared memory.
  - Managing polymorphic arrays of `Animal` objects with proper destruction.

- **Exercise 02 (Abstract class):**
  - Converting `Animal` into an abstract class by making it non-instantiable with pure virtual functions.
  - Preventing misuse of base classes while maintaining polymorphic behavior.

- **Exercise 03 (Interface & recap):**
  - Implementing interfaces using pure abstract classes (`AMateria`, `ICharacter`, `IMateriaSource`).
  - Designing concrete classes (`Ice`, `Cure`, `Character`, `MateriaSource`) to fulfill interface contracts.
  - Managing inventories and dynamic Materia creation with the `MateriaSource` class.

## 3. Best Practices:
- Test extensively to ensure correct polymorphic behavior and memory safety.
- Avoid shallow copies in dynamically allocated resources.
- Use abstract classes and interfaces to enforce design consistency.
- Implement robust destructors to prevent memory leaks.

## Takeaway:
This module solidifies understanding of subtype polymorphism, abstract classes, and interfaces in C++. It emphasizes memory management, deep copies, and reusable design patterns, preparing for scalable and maintainable software development.
