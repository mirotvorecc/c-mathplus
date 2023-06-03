#include "../s21_math.h"

long double s21_acos(double x) {
  long double result = s21_atan(s21_sqrt(1 - (x * x)) / x);

  if (x < 0) result = S21_PI + result;

  return result;
}

// checked