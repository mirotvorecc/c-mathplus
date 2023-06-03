#include "../s21_math.h"

long double s21_cos(double x) {
  if (x == S21_PI) return -1;

  if (x == -S21_PI) return -1;

  return s21_sin((S21_PI / 2.0) - x);
}

// checked
