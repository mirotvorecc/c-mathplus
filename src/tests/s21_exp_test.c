#include "s21_test.h"

START_TEST(expTest1) {
  long double result = s21_exp(19);
  long double expected = exp(19);
  ck_assert_double_eq_tol(result, expected, 0.0000001);
}
END_TEST;

START_TEST(expTest2) {
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));
}
END_TEST;

START_TEST(expTest3) {
  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), 0.0000001);
}
END_TEST;

START_TEST(expTest4) { ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY)); }
END_TEST;

START_TEST(expTest5) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST;

START_TEST(expTest6) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST;

START_TEST(expTest7) { ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001); }
END_TEST;

START_TEST(expTest8) { ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001); }
END_TEST;

START_TEST(expTest9) {
  ck_assert_double_eq_tol(s21_exp(5), exp(5), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-2), exp(-2), 0.000001);
  ck_assert_double_eq_tol(s21_exp(0.42453251351353), exp(0.42453251351353),
                          0.000001);
  for (double i = -10; i < 10; i++) {
    ck_assert_double_eq_tol(s21_exp(i), exp(i), 0.000001);
  }
}
END_TEST;

START_TEST(expTest10) {
  ck_assert_double_eq_tol(s21_exp(0.54356823673485), exp(0.54356823673485),
                          0.000001);
}
END_TEST;

START_TEST(expTest11) {
  ck_assert_double_eq_tol(s21_exp(-53245245.453), exp(-53245245.453), 0.000001);
}
END_TEST;

Suite *expTest(void) {
  Suite *s = suite_create("\033[45mExp test\033[0m");
  TCase *tc = tcase_create("Exp test");

  tcase_add_test(tc, expTest1);
  tcase_add_test(tc, expTest2);
  tcase_add_test(tc, expTest3);
  tcase_add_test(tc, expTest4);
  tcase_add_test(tc, expTest5);
  tcase_add_test(tc, expTest6);
  tcase_add_test(tc, expTest7);
  tcase_add_test(tc, expTest8);
  tcase_add_test(tc, expTest9);
  tcase_add_test(tc, expTest10);
  tcase_add_test(tc, expTest11);

  suite_add_tcase(s, tc);
  return s;
}
