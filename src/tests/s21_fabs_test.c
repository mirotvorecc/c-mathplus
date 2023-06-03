#include "s21_test.h"

START_TEST(fabs1) {
  for (double x = -31897.; x < 32533.; x += 115.5)
    ck_assert_double_eq_tol(s21_fabs(x), fabs(x), 0.000001);
}
END_TEST;

Suite *fabsTest(void) {
  Suite *s = suite_create("\033[45mFabs test\033[0m");
  TCase *tc = tcase_create("Fabs test");

  tcase_add_test(tc, fabs1);

  suite_add_tcase(s, tc);
  return s;
}