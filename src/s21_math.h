#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846
#define S21_NAN 0.0 / 0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_LN2 0.693147180559945309417232
#define S21_E 2.71828182845904523536028747
#define S21_ACC 1e-09

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)

int s21_abs(int x);
int checks(double x, double y);
long double s21_pow(double base, double exponent);
long double s21_sqrt(double x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_factorial(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_log(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

#endif  // SRC_S21_MATH_H_