#include "s21_test.h"

START_TEST(abs1) {
  for (int x = -31897; x < 32533; x += 150)
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST;

Suite *absTest(void) {
  Suite *s = suite_create("\033[45mAbs test\033[0m");
  TCase *tc = tcase_create("Abs test");

  tcase_add_test(tc, abs1);

  suite_add_tcase(s, tc);
  return s;
}