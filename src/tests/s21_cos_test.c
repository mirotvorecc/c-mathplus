#include "s21_test.h"

START_TEST(cosTest1) {
  double value1 = 0;
  ck_assert_double_eq_tol(s21_cos(value1), cos(value1), 0.000001);
  double value2 = 12347;
  ck_assert_double_eq_tol(s21_cos(value2), cos(value2), 0.000001);
  double value3 = -34567;
  ck_assert_double_eq_tol(s21_cos(value3), cos(value3), 0.000001);
  for (double i = -S21_PI; i < S21_PI; i += 0.01) {
    ck_assert_int_eq(s21_cos(i), cos(i));
  }
}
END_TEST;

START_TEST(cosTest2) {
  ck_assert_double_eq_tol(s21_cos(-14.96), cos(-14.96), 0.000001);
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(cos(INFINITY));
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_nan(cos(-INFINITY));
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(cos(NAN));
  ck_assert_double_eq_tol(s21_cos(0), cos(0), 0.000001);
  ck_assert_double_eq_tol(s21_cos(-M_PI_2), cos(-M_PI_2), 0.000001);
  ck_assert_double_eq_tol(s21_cos(M_PI), cos(M_PI), 0.000001);
  ck_assert_double_eq_tol(s21_cos(1234567), cos(1234567), 0.000001);
  ck_assert_double_eq_tol(s21_cos(-1234567), cos(-1234567), 0.000001);
  ck_assert_double_eq_tol(s21_cos(-0.54356), cos(-0.54356), 0.000001);
  ck_assert_double_eq_tol(s21_cos(-4236526.54356), cos(-4236526.54356),
                          0.000001);
  ck_assert_double_eq_tol(s21_cos(34), cos(34), 0.000001);
}
END_TEST;

Suite *cosTest(void) {
  Suite *s = suite_create("\033[45mCos test\033[0m");
  TCase *tc = tcase_create("Cos test");

  tcase_add_test(tc, cosTest1);
  tcase_add_test(tc, cosTest2);

  suite_add_tcase(s, tc);
  return s;
}