# c-mathplus

A custom implementation of common mathematical functions from the C standard `math.h` library.

This project provides source code for mathematical functions written in C, designed for educational purposes, portability, and as a lightweight alternative for environments where the standard math library may not be available or needs to be extended.

## Prerequisites

- GCC or any C99-compatible compiler
- [Make](https://www.gnu.org/software/make/) (for building and testing using the provided Makefile)

## Contents

- [`main_functions/`](src/main_functions/): Source files implementing mathematical functions (`s21_abs.c`, `s21_sin.c`, `s21_cos.c`, etc.)
- [`s21_math.h`](src/s21_math.h): Public header file for all custom math functions
- [`tests/`](src/tests/): Unit tests for the implemented functions
- [`Makefile`](src/Makefile): Build and test automation

## Setup and Usage

1. **Clone this repository to your local machine:**
    ```
    git clone https://github.com/mirotvorecc/c-mathplus.git
    cd c-mathplus/src
    ```

2. **Build the project:**
    ```
    make
    ```

3. **Run the tests to verify the implementation:**
    ```
    make test
    ```

4. **Integrate into your project:**
    - Copy the required source files from `main_functions/` and `s21_math.h` into your project.
    - Include `s21_math.h` in your C source files.

## Features

- Custom implementations of core mathematical functions, including:
    - Trigonometric: `s21_sin`, `s21_cos`, `s21_tan`, `s21_asin`, `s21_acos`, `s21_atan`
    - Exponential and logarithmic: `s21_exp`, `s21_log`, `s21_pow`, `s21_sqrt`
    - Rounding and remainder: `s21_ceil`, `s21_floor`, `s21_fmod`
    - Absolute value: `s21_abs`, `s21_fabs`
- All functions are declared in `s21_math.h` and implemented in separate source files for clarity and modularity
- Unit tests for all functions for correctness and compatibility

## Notes

- The custom implementations aim for compatibility with the C standard library but may not cover all edge cases or platform-specific behaviors.
- The project structure is modular and easy to extend.
- Always check buffer sizes and input ranges for mathematical functions to avoid undefined behavior.
