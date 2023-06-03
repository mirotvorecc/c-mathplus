#include "s21_test.h"

START_TEST(sinTest1) {
  double value1 = 0;
  ck_assert_int_eq(s21_sin(value1), sin(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_sin(value2), sin(value2));
  double value3 = -3234567;
  ck_assert_int_eq(s21_sin(value3), sin(value3));
  for (double i = -S21_PI; i < S21_PI; i += 0.01) {
    ck_assert_int_eq(s21_sin(i), sin(i));
  }
}
END_TEST;

START_TEST(sinTest2) {
  ck_assert_double_eq_tol(s21_sin(-14.96), sin(-14.96), 0.000001);
  ck_assert_double_eq_tol(s21_sin(25524525), sin(25524525), 0.000001);
  ck_assert_double_eq_tol(s21_sin(25524525), sin(25524525), 0.000001);
  ck_assert_double_eq_tol(s21_sin(4236265.2435252455), sin(4236265.2435252455),
                          0.000001);
  ck_assert_double_eq_tol(s21_sin(2), sin(2), 0.000001);
  ck_assert_double_nan(s21_sin(INFINITY));
  ck_assert_double_nan(sin(INFINITY));
}
END_TEST;

Suite *sinTest(void) {
  Suite *s = suite_create("\033[45mSin test\033[0m");
  TCase *tc = tcase_create("Sin test");

  tcase_add_test(tc, sinTest1);
  tcase_add_test(tc, sinTest2);

  suite_add_tcase(s, tc);
  return s;
}