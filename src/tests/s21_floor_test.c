#include "s21_test.h"

START_TEST(floorTest1) {
  for (int x = -3197; x < 3124; x += 10)
    ck_assert_int_eq(s21_floor(x), floor(x));
}
END_TEST;

START_TEST(floorTest2) {
  double value1 = 1.5;
  ck_assert_double_eq_tol(s21_floor(value1), floor(value1), 0.000001);
  double value2 = 0.45;
  ck_assert_double_eq_tol(s21_floor(value2), floor(value2), 0.000001);
  double value3 = -3.01;
  ck_assert_double_eq_tol(s21_floor(value3), floor(value3), 0.000001);
  double value4 = -0.;
  ck_assert_double_eq_tol(s21_floor(value4), floor(value4), 0.000001);
  double value5 = -0;
  ck_assert_double_eq_tol(s21_floor(value5), floor(value5), 0.000001);
  double value6 = 657489967894.76474674674674;
  ck_assert_double_eq_tol(s21_floor(value6), floor(value6), 0.000001);
  double value7 = 0;
  ck_assert_int_eq(s21_floor(value7), floor(value7));
  ck_assert_double_eq_tol(s21_floor(-0.8), floor(-0.8), 0.000001);
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_eq(s21_floor(-INFINITY), floor(-INFINITY));
  ck_assert_double_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST;

Suite *floorTest(void) {
  Suite *s = suite_create("\033[45mFloor test\033[0m");
  TCase *tc = tcase_create("Floor test");

  tcase_add_test(tc, floorTest1);
  tcase_add_test(tc, floorTest2);

  suite_add_tcase(s, tc);
  return s;
}
