# Key Learnings from the Module

## 1. Core C++ Concepts:
- **Templates:** Using function and class templates for generic programming to work with any data type.
- **Operator Overloading:** Ensuring templates work seamlessly with custom and built-in types by relying on overloaded operators.
- **Memory Management:** Allocating memory dynamically and managing it efficiently with safety checks.
- **Error Handling:** Throwing and catching exceptions for robust and safe code execution.

## 2. Practical Applications:

- **Exercise 00 (Start with a few functions):**
  - Implementing template functions `swap`, `min`, and `max` for any comparable type.
  - Testing these templates with multiple data types like integers and strings.
  - Ensuring behavior consistency when comparing equal values.

- **Exercise 01 (Iter):**
  - Designing a template function `iter` to iterate over arrays of any type.
  - Applying a user-defined function to each element of the array.
  - Testing with various data types and callable objects, including function pointers and lambda expressions.

- **Exercise 02 (Array):**
  - Implementing a class template `Array` to manage elements of any type.
  - Adding constructors for default, parameterized, and copy initialization.
  - Ensuring safe memory access with bounds checking in the `[]` operator.
  - Overloading assignment to create deep copies and avoid shared memory issues.
  - Providing a `size()` function for querying the array size.

## 3. Best Practices:
- Use templates to write reusable and type-safe code.
- Test extensively with multiple data types to ensure template robustness.
- Avoid accessing unallocated memory by implementing bounds checks.
- Use dynamic memory allocation carefully and always release it to prevent leaks.
- Provide clear error messages and handle exceptions gracefully.

## Takeaway:
This module emphasizes generic programming with templates and dynamic memory management. By implementing reusable templates and safe array classes, it builds foundational skills for scalable and maintainable C++ applications.
