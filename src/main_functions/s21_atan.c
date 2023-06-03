#include "../s21_math.h"

long double s21_atan(double x) {
  if (S21_IS_NAN(x)) return x;
  if (x == S21_INF_POS) return S21_PI / 2;
  if (x == S21_INF_NEG) return -S21_PI / 2;
  if (x == 1) return S21_PI / 4;
  if (x == -1) return -(S21_PI / 4);

  long double result = 0;

  if (x > -1. && x < 1.) {
    for (int i = 0; i < 5000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / (2 * i + 1);
    }
  } else {
    for (int i = 0; i < 7000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
  }

  return result;
}

// checked