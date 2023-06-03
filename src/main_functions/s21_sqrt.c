#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0 || S21_IS_NAN(x) || x == S21_INF_NEG) return S21_NAN;
  if (x == 0 || x == S21_INF_POS) return x;

  long double result = 1.0;
  long double tmp = 0.0;

  while (result != tmp) {  // пока не будет достигнута точность
    tmp = result;  // запоминаем предыдущую итерацию
    result = (result + x / result) / 2.0;
  }

  return result;
}