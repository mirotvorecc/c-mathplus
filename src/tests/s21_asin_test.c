#include "s21_test.h"

START_TEST(asinTest1) {
  ck_assert_double_nan(s21_asin(-INFINITY));
  ck_assert_double_nan(asin(-INFINITY));
}
END_TEST;

START_TEST(asinTest2) {
  ck_assert_double_eq_tol(s21_asin(0.289), asin(0.289), 0.000001);
  ck_assert_double_eq_tol(asin(S21_ACC), s21_asin(S21_ACC), 0.000001);
}
END_TEST;

START_TEST(asinTest3) {
  ck_assert_double_eq_tol(asin(0.1234), s21_asin(0.1234), 0.000001);
  ck_assert_double_eq_tol(asin(0), s21_asin(0), 0.000001);
}
END_TEST;

START_TEST(asinTest4) {
  ck_assert_double_eq_tol(s21_asin(0.289), asin(0.289), 0.000001);
  ck_assert_double_eq_tol(asin(S21_ACC), s21_asin(S21_ACC), 0.000001);
}
END_TEST;

START_TEST(asinTest5) {
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 0.000001);
  ck_assert_double_eq_tol(asin(-1), s21_asin(-1), 0.000001);
}
END_TEST;

START_TEST(asinTest6) {
  ck_assert_double_eq_tol(asin(0.5), s21_asin(0.5), 0.000001);
  ck_assert_double_eq_tol(asin(-0.5), s21_asin(-0.5), 0.000001);
}
END_TEST;

START_TEST(asinTest7) {
  ck_assert_double_eq_tol(asin(-0.4235), s21_asin(-0.4235), 0.000001);
}
END_TEST;

START_TEST(asinTest8) {
  ck_assert_double_nan(s21_asin(-16));
  ck_assert_double_nan(asin(-16));
}
END_TEST;

START_TEST(asinTest9) {
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(asin(NAN));
}
END_TEST;

START_TEST(asinTest10) {
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(asin(INFINITY));
}
END_TEST;

// START_TEST(asinTest11) {
//   ck_assert_double_eq_tol(asin(0.999999), s21_asin(0.999999), 0.000001);
// }
// END_TEST;

Suite *asinTest(void) {
  Suite *s = suite_create("\033[45mAsin test\033[0m");
  TCase *tc = tcase_create("Asin test");

  tcase_add_test(tc, asinTest1);
  tcase_add_test(tc, asinTest2);
  tcase_add_test(tc, asinTest3);
  tcase_add_test(tc, asinTest4);
  tcase_add_test(tc, asinTest5);
  tcase_add_test(tc, asinTest6);
  tcase_add_test(tc, asinTest7);
  tcase_add_test(tc, asinTest8);
  tcase_add_test(tc, asinTest9);
  tcase_add_test(tc, asinTest10);
  //  tcase_add_test(tc, asinTest11);

  suite_add_tcase(s, tc);
  return s;
}
