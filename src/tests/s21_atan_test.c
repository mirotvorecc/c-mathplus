#include "s21_test.h"

START_TEST(atanTest1) {
  double value1 = 0.43;
  ck_assert_double_eq_tol(s21_atan(value1), atan(value1), 0.000001);
  double value2 = 0.12;
  ck_assert_double_eq_tol(s21_atan(value2), atan(value2), 0.000001);
  double value3 = 1;
  ck_assert_double_eq_tol(s21_atan(value3), atan(value3), 0.000001);
  double value4 = -1;
  ck_assert_double_eq_tol(s21_atan(value4), atan(value4), 0.000001);
  double value5 = 0;
  ck_assert_double_eq_tol(s21_atan(value5), atan(value5), 0.000001);
}
END_TEST;

START_TEST(atanTest2) {
  double value6 = 0.332;
  ck_assert_double_eq_tol(s21_atan(value6), atan(value6), 0.000001);
  double value7 = 0.001;
  ck_assert_double_eq_tol(s21_atan(value7), atan(value7), 0.000001);
  double value8 = -0.124325345;
  ck_assert_double_eq_tol(s21_atan(value8), atan(value8), 0.000001);
}
END_TEST;

START_TEST(atanTest3) {
  for (double i = -1.; i < 1.; i += 0.3) {
    ck_assert_double_eq_tol(s21_atan(i), atan(i), 0.000001);
  }
}
END_TEST;

START_TEST(atanTest4) {
  double value1 = NAN;
  ck_assert_double_nan(s21_atan(value1));
  ck_assert_double_nan(atan(value1));
  double value2 = INFINITY;
  ck_assert_double_eq_tol(s21_atan(value2), atan(value2), 0.000001);
  double value3 = -INFINITY;
  ck_assert_double_eq_tol(s21_atan(value3), atan(value3), 0.000001);
}
END_TEST;

Suite *atanTest(void) {
  Suite *s = suite_create("\033[45mAtan test\033[0m");
  TCase *tc = tcase_create("Atan test");

  tcase_add_test(tc, atanTest1);
  tcase_add_test(tc, atanTest2);
  tcase_add_test(tc, atanTest3);
  tcase_add_test(tc, atanTest4);

  suite_add_tcase(s, tc);
  return s;
}