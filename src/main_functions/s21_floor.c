#include "../s21_math.h"

long double s21_floor(double x) {
  if (S21_IS_INF(x) || S21_IS_NAN(x)) return x;

  long double result = (long double)(long long)x;
  if (x < 0 && x != (long long)x) result = (long double)(long long)x - 1;

  return result;
}