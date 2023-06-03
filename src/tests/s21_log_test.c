#include "s21_test.h"

START_TEST(logTest1) {
  double x = 2;
  ck_assert_double_eq_tol(s21_log(x), log(x), 0.0000001);
}
END_TEST;

START_TEST(logTest2) {
  ck_assert_double_eq_tol(s21_log(12356), log(12356), 0.000001);
  ck_assert_double_eq_tol(s21_log(1.1), log(1.1), 0.000001);
  for (double i = 1.00002; i < 10; i += 0.2) {
    ck_assert_double_eq_tol(s21_log(i), log(i), 0.000001);
  }
  for (double i = 0.001; i < 2; i += 0.01) {
    ck_assert_double_eq_tol(s21_log(i), log(i), 0.0000001);
  }
}
END_TEST;

START_TEST(logTest3) {
  ck_assert_double_nan(s21_log(-12.36));
  ck_assert_double_nan(log(-12.36));
}
END_TEST;

START_TEST(logTest4) { ck_assert_double_eq(s21_log(0), log(0)); }
END_TEST;

START_TEST(logTest5) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST;

START_TEST(logTest6) {
  ck_assert_double_eq_tol(s21_log(26941.289), log(26941.289), 0.000001);
}
END_TEST;

START_TEST(logTest7) {
  double x = 31241345425.;
  ck_assert_double_eq_tol(s21_log(x), log(x), 0.0000001);
}
END_TEST;

START_TEST(logTest8) {
  double x = NAN;
  ck_assert_double_nan(s21_log(x));
  ck_assert_double_nan(log(x));
}
END_TEST;

START_TEST(logTest9) {
  double x = INFINITY;
  ck_assert_double_eq(s21_log(x), log(x));
}
END_TEST;

START_TEST(logTest10) {
  double x = -INFINITY;
  ck_assert_double_nan(s21_log(x));
  ck_assert_double_nan(log(x));
}
END_TEST;

Suite *logTest(void) {
  Suite *s = suite_create("\033[45mLog test\033[0m");
  TCase *tc = tcase_create("Log test");

  tcase_add_test(tc, logTest1);
  tcase_add_test(tc, logTest2);
  tcase_add_test(tc, logTest3);
  tcase_add_test(tc, logTest4);
  tcase_add_test(tc, logTest5);
  tcase_add_test(tc, logTest6);
  tcase_add_test(tc, logTest7);
  tcase_add_test(tc, logTest8);
  tcase_add_test(tc, logTest9);
  tcase_add_test(tc, logTest10);

  suite_add_tcase(s, tc);
  return s;
}
