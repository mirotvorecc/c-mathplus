#include "../s21_math.h"

long double s21_pow(double base, double exponent) {
  if (S21_IS_NAN(base) || S21_IS_NAN(exponent)) return S21_NAN;

  long double result = 1;

  if (exponent < 0) {
    result = 1. / s21_pow(base, -exponent);
  } else {
    for (int i = 0; i < exponent; i++) {
      result *= base;
    }
  }

  return result;
}
