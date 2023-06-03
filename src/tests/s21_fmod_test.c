#include "s21_test.h"

START_TEST(fmodTest1) {
  ck_assert_int_eq(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7));
  ck_assert_int_eq(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1));
  ck_assert_int_eq(s21_fmod(23.456, 4.355), fmod(23.456, 4.355));
  ck_assert_double_nan(s21_fmod(NAN, NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(-INFINITY, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, -INFINITY));
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, INFINITY));
  ck_assert_double_nan(s21_fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(s21_fmod(-INFINITY, NAN));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
  ck_assert_double_nan(s21_fmod(INFINITY, 3));
  ck_assert_double_nan(fmod(INFINITY, 3));
}
END_TEST;

Suite *fmodTest(void) {
  Suite *s = suite_create("\033[45mFmod test\033[0m");
  TCase *tc = tcase_create("Fmod test");

  tcase_add_test(tc, fmodTest1);

  suite_add_tcase(s, tc);
  return s;
}
