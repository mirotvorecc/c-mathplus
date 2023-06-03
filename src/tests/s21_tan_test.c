#include "s21_test.h"

START_TEST(tanTest1) {
  double value1 = 0.23;
  ck_assert_double_eq_tol(s21_tan(value1), tan(value1), 0.000001);
  double value2 = 1234567;
  ck_assert_double_eq_tol(s21_tan(value2), tan(value2), 0.000001);
  double value3 = -1234567;
  ck_assert_double_eq_tol(s21_tan(value3), tan(value3), 0.000001);
  double value4 = 341235.25452345645;
  ck_assert_double_eq_tol(s21_tan(value4), tan(value4), 0.000001);
  double value5 = S21_PI;
  ck_assert_double_eq_tol(s21_tan(value5), tan(value5), 0.000001);

  for (double i = -1000; i < 1000; i += 20) {
    ck_assert_double_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_double_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
}
END_TEST;

Suite *tanTest(void) {
  Suite *s = suite_create("\033[45mTan test\033[0m");
  TCase *tc = tcase_create("Tan test");

  tcase_add_test(tc, tanTest1);

  suite_add_tcase(s, tc);
  return s;
}
