#include "../s21_math.h"

long double s21_factorial(double x) {
  long double result = 1;

  for (int i = 1; i <= x; i++) {
    result *= i;
  }

  return result;
}

// checked