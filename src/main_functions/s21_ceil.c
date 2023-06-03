#include "../s21_math.h"

long double s21_ceil(double x) {
  if (S21_IS_INF(x) || S21_IS_NAN(x)) return x;

  double y = x < 0 ? -x : x;
  long double res = (long int)y - 1;
  for (; res < y; res++)
    ;
  if (x < 0) res = -res + 1;

  return res;
}

// checked