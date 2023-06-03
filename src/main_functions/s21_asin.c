#include "../s21_math.h"

// asin(x) = atan(x / sqrt(1 - x^2))

long double s21_asin(double x) {
  if (x > 1 || x < -1) return S21_NAN;
  if (S21_IS_NAN(x)) return S21_NAN;

  long double result = s21_atan(x / s21_sqrt(1 - x * x));

  return result;
}

// checked