#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if (checks(x, y)) return S21_NAN;
  if (S21_IS_INF(y)) return x;

  long double z = x / y;
  return x - y * (long double)(long)z;
}

int checks(double x, double y) {
  if (S21_IS_NAN(x) || S21_IS_NAN(y)) return 1;
  if (S21_IS_INF(x) || S21_IS_INF(y)) return 1;
  if (y == 0) return 1;
  return 0;
}