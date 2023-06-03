#include "../s21_math.h"

long double s21_tan(double x) {
  x = s21_fmod(x, S21_PI);

  long double cos = s21_cos(x);

  long double result = 0;

  result = s21_sin(x) / cos;

  return result;
}