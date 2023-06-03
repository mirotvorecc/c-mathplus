#include "../s21_math.h"

long double s21_sin(double x) {
  long double result = 0;

  // функция гармоническая поэтому можно сдвигать синусоиду без потери точности

  x = s21_fmod(x, 2 * S21_PI);

  for (int i = 0; i < 100; i++) {
    result += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_factorial(2 * i + 1);
  }

  return result;
}