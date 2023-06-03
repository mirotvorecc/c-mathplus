#include "s21_test.h"

START_TEST(acosTest1) {
  double x = 0.5;
  ck_assert_double_eq_tol(s21_acos(x), acos(x), 0.000001);
}
END_TEST

START_TEST(acosTest2) {
  double x = 0.4523452355;
  ck_assert_double_eq_tol(s21_acos(x), acos(x), 0.000001);
}
END_TEST

START_TEST(acosTest3) {
  double x = NAN;
  ck_assert_double_nan(s21_acos(x));
  ck_assert_double_nan(acos(x));
}
END_TEST

START_TEST(acosTest4) {
  double x = INFINITY;
  ck_assert_double_nan(s21_acos(x));
  ck_assert_double_nan(acos(x));
}
END_TEST

START_TEST(acosTest5) {
  double x = -INFINITY;
  ck_assert_double_nan(s21_acos(x));
  ck_assert_double_nan(acos(x));
}
END_TEST

START_TEST(acosTest6) {
  double x = 347.52;
  ck_assert_double_nan(s21_acos(x));
  ck_assert_double_nan(acos(x));
}
END_TEST

START_TEST(acosTest7) {
  double x = 12;
  ck_assert_double_nan(s21_acos(x));
  ck_assert_double_nan(acos(x));
}
END_TEST

START_TEST(acosTest8) {
  double x = -0.8543;
  ck_assert_double_eq_tol(s21_acos(x), acos(x), 0.000001);
}
END_TEST

Suite *acosTest(void) {
  Suite *s = suite_create("\033[45mAcos test\033[0m");
  TCase *tc = tcase_create("Acos test");

  tcase_add_test(tc, acosTest1);
  tcase_add_test(tc, acosTest2);
  tcase_add_test(tc, acosTest3);
  tcase_add_test(tc, acosTest4);
  tcase_add_test(tc, acosTest5);
  tcase_add_test(tc, acosTest6);
  tcase_add_test(tc, acosTest7);
  tcase_add_test(tc, acosTest8);

  suite_add_tcase(s, tc);
  return s;
}