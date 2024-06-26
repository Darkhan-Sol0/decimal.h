#include "test_main.h"

int main(void) {
  int failed = 0;
  Suite *s21_decimal_test[] = {test_arithmetic_add(),
                               test_arithmetic_sub(),
                               test_arithmetic_mul(),
                               test_arithmetic_div(),
                               test_comparison(),
                               test_setters(),
                               test_big_comparison(),
                               test_support_functions(),
                               test_convertors(),
                               test_other_functions(),
                               NULL};

  for (int i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_decimal_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed;
}
