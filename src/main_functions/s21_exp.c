#include "../s21_math.h"

// exp(x) = 1 + x + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!

long double s21_exp(double x) {
  if (x == S21_INF_NEG) return 0.0;
  if (S21_IS_NAN(x)) return S21_NAN;
  if (S21_IS_INF(x)) return S21_INF_POS;

  int isNegative = 0;
  if (x < 0) {
    isNegative = 1;
    x = -x;
  }

  long double iteration = 1;
  long double sum = 1;

  // провверяем достижение необходимой точности(8 знаков после запятой)
  for (long double i = 1; s21_fabs(iteration) > S21_ACC; i++) {
    iteration *= x / i;  // вычисление очередного члена ряда
    sum += iteration;     // вычисление суммы ряда
    if (sum > DBL_MAX) {  // отлавливание переполнения
      sum = S21_INF_POS;
      break;
    }
  }

  if (sum != S21_INF_POS && isNegative) {
    sum = 1. / sum;
  } else if (sum == S21_INF_POS && isNegative) {
    sum = 0.;
  }

  return sum;
}

// checked