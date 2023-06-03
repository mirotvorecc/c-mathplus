#include "../s21_math.h"

// используем метод Галея
// x = x + 2 * ((x - exp(x)) / (x + exp(x)))

long double s21_log(double x) {
  if (x < 0) {
    return S21_NAN;
  }
  if (x == 0) {
    return S21_INF_NEG;
  }
  if (x == S21_INF_POS) {
    return x;
  }

  int counter = 0;
  long double result = 0;

  // смотрим сколько раз в x помещается exp, приближаем x к
  // значениям близким к exp потому что формула работает лучше с
  // такими значениями, в конце прибавляем counter
  for (; x >= S21_E; x /= S21_E) {
    counter++;
  }

  for (int i = 0; i < 100; i++) {
    long double tmp = result;
    result = tmp + 2 * ((x - s21_exp(tmp)) / (x + s21_exp(tmp)));
  }

  result += counter;

  return result;
}