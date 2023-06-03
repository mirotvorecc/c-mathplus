#include "s21_test.h"

START_TEST(ceilTest1) {
  ck_assert_double_eq_tol(s21_ceil(-0.1), ceil(-0.1), 0.000001);
}
END_TEST

START_TEST(ceilTest2) {
  ck_assert_double_eq_tol(s21_ceil(-213.3), ceil(-213.3), 0.000001);
}
END_TEST

START_TEST(ceilTest3) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(ceilTest4) {
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(ceilTest5) {
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(ceilTest6) {
  ck_assert_double_eq_tol(s21_ceil(50), ceil(50), 0.000001);
}
END_TEST

START_TEST(ceilTest7) {
  double value1 = 1.5;
  ck_assert_uint_eq(s21_ceil(value1), ceil(value1));
  double value2 = 0.45;
  ck_assert_uint_eq(s21_ceil(value2), ceil(value2));
  double value3 = -3.00000000001;
  ck_assert_uint_eq(s21_ceil(value3), ceil(value3));
  double value4 = -0;
  ck_assert_uint_eq(s21_ceil(value4), ceil(value4));
  double value5 = 1234567;
  ck_assert_uint_eq(s21_ceil(value5), ceil(value5));
}
END_TEST

START_TEST(ceilTest8) {
  double value = 999999.432525345453;
  ck_assert_uint_eq(s21_ceil(value), ceil(value));
}
END_TEST

Suite *ceilTest(void) {
  Suite *s = suite_create("\033[45mCeil test\033[0m");
  TCase *tc = tcase_create("Ceil test");

  tcase_add_test(tc, ceilTest1);
  tcase_add_test(tc, ceilTest2);
  tcase_add_test(tc, ceilTest3);
  tcase_add_test(tc, ceilTest4);
  tcase_add_test(tc, ceilTest5);
  tcase_add_test(tc, ceilTest6);
  tcase_add_test(tc, ceilTest7);
  tcase_add_test(tc, ceilTest8);

  suite_add_tcase(s, tc);
  return s;
}
