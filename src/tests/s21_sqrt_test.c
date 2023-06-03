#include "s21_test.h"

START_TEST(sqrtTest1) {
  double x = 4.;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
}
END_TEST;

START_TEST(sqrtTest2) {
  double x = 43424.;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}
END_TEST;

START_TEST(sqrtTest3) {
  double x = 0.;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
}
END_TEST;

START_TEST(sqrtTest4) {
  double x = 1.;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(sqrtTest5) {
  double x = INFINITY;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
}
END_TEST;

START_TEST(sqrtTest6) {
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
}
END_TEST;

START_TEST(sqrtTest7) {
  double x = 82632427435;
  for (int i = 0; i < 1000; i++) {
    x += 100;
    double res = s21_sqrt(x);
    double res2 = sqrt(x);
    ck_assert_double_eq_tol(res, res2, 0.000001);
  }
}
END_TEST;

Suite *sqrtTest(void) {
  Suite *s = suite_create("\033[45mSqrt test\033[0m");
  TCase *tc = tcase_create("Sqrt test");

  tcase_add_test(tc, sqrtTest1);
  tcase_add_test(tc, sqrtTest2);
  tcase_add_test(tc, sqrtTest3);
  tcase_add_test(tc, sqrtTest4);
  tcase_add_test(tc, sqrtTest5);
  tcase_add_test(tc, sqrtTest6);
  tcase_add_test(tc, sqrtTest7);

  suite_add_tcase(s, tc);
  return s;
}
