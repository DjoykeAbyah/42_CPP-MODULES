# Key Learnings from the Module

## 1. Core C++ Concepts:
- **Templates with Containers:** Leveraging templates to work with STL containers and custom classes.
- **Iterators:** Extending iterability to non-iterable containers and working with range-based operations.
- **Algorithmic Efficiency:** Using STL algorithms and custom implementations for container manipulation.
- **Error Handling:** Implementing safe and robust error handling in container operations.

## 2. Practical Applications:

- **Exercise 00 (Easy find):**
  - Creating a function template `easyfind` to locate an integer in a container.
  - Handling cases where the value is not found with exceptions or error values.
  - Testing functionality with standard sequential containers like `std::vector` and `std::deque`.

- **Exercise 01 (Span):**
  - Developing a `Span` class to store a fixed number of integers.
  - Adding functions `shortestSpan` and `longestSpan` to calculate minimum and maximum distances between elements.
  - Supporting efficient addition of numbers through iterator ranges.
  - Testing with large datasets to ensure performance and correctness.

- **Exercise 02 (Mutated abomination):**
  - Extending `std::stack` to create an iterable `MutantStack` class.
  - Adding iterator support while preserving all member functions of `std::stack`.
  - Ensuring compatibility with STL algorithms by enabling iterator-based access.
  - Testing MutantStack against other containers like `std::list` for output equivalency.

## 3. Best Practices:
- Use templates to write flexible, type-agnostic code for container manipulation.
- Test for edge cases, such as empty containers or large datasets, to ensure robustness.
- Implement iterators for non-iterable containers to extend their usability with STL algorithms.
- Optimize performance when working with large data through bulk operations and efficient data structures.

## Takeaway:
This module builds expertise in working with templates, STL containers, and iterators. By implementing generic functions and enhancing container capabilities, it provides hands-on experience in creating efficient, scalable, and reusable C++ solutions.
