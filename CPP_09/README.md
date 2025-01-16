# Key Learnings from the Module

## 1. Core C++ Concepts:
- **STL Containers:** Leveraging containers like `std::vector`, `std::stack`, and others for efficient data management.
- **Algorithms:** Implementing and customizing sorting and searching algorithms for specific needs.
- **Error Handling:** Robustly managing invalid inputs and runtime errors with clear messages.
- **Performance Measurement:** Tracking execution time to compare algorithm efficiency across different containers.

## 2. Practical Applications:

- **Exercise 00 (Bitcoin Exchange):**
  - Creating a program to calculate Bitcoin value using historical exchange rates from a CSV database.
  - Handling edge cases like invalid dates, out-of-range values, and missing data gracefully.
  - Using containers to store and query historical data efficiently.

- **Exercise 01 (Reverse Polish Notation):**
  - Implementing a program to evaluate mathematical expressions in Reverse Polish Notation.
  - Supporting operations like `+`, `-`, `*`, and `/` using a container-based stack.
  - Validating input expressions and providing informative error messages for invalid cases.

- **Exercise 02 (PmergeMe):**
  - Developing a program to sort a sequence of positive integers using the merge-insert sort algorithm (Ford-Johnson algorithm).
  - Using at least two different containers to implement the algorithm independently.
  - Managing and displaying sorting times for both containers to compare performance.
  - Testing with large datasets (e.g., 3000 integers) to ensure efficiency and correctness.

## 3. Best Practices:
- Use STL containers to simplify data management and leverage their built-in functionality.
- Validate all user inputs and edge cases to prevent crashes or undefined behavior.
- Test extensively with various data sizes to ensure performance and robustness.
- Measure and compare algorithm efficiency to identify bottlenecks and optimize code.

## Takeaway:
This module reinforces advanced use of STL containers, algorithms, and error handling. By solving real-world problems like data conversion, mathematical evaluation, and sorting, it builds practical skills for efficient and maintainable C++ programming.
