#include <stdio.h>
#include "testList.h"
#include "../list.h"

void test_empty_list() {
  char description[] = "should add to the 0th position of an empty list\n";
  List_ptr list = create_list();
  Status actual = add_to_end(list, 5);
  assert_equal(1, actual, description);
}

void test_long_list() {
  char description[] = "should add to the end of a long list\n";
  List_ptr list = create_list();
  add_to_start(list, 1);
  add_to_start(list, 2);
  Status actual = add_to_end(list, 5);
  assert_equal(1, actual, description);
}

void run_Tests_For_add_to_end() {
  printf("--------- add_to_end---------\n");
  test_empty_list();
  test_long_list();
}

int main(void) {
  run_Tests_For_add_to_end();
  return 0;
}