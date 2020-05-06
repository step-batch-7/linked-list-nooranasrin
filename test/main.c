#include <stdio.h>
#include "testList.h"
#include "../list.h"

int main(void) {
  run_tests_for_add_to_end();
  run_tests_for_add_to_start();
  run_tests_for_insert_at();
  run_tests_for_add_unique();
  run_tests_for_remove_from_start();
  return 0;
}