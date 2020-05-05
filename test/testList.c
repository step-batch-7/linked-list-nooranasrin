#include<stdio.h>
#include "../list.h"
#include "testList.h"

void assert_equal(int expectedValue, int actualValue, char *message) {
  char symbol[] = "✅";

  if(expectedValue !=actualValue ) {
    char error_symbol[] = "❌";
    char errorMessage[] = "failing\n";
    printf("%s %s",symbol, errorMessage);
  }

  printf("%s %s",symbol, message);
}

void test_empty_list_for_add_to_end() {
  char description[] = "should add to the 0th position of an empty list\n";
  List_ptr list = create_list();
  Status actual = add_to_end(list, 5);
  assert_equal(1, actual, description);
}

void test_long_list_for_add_to_end() {
  char description[] = "should add to the end of a long list\n";
  List_ptr list = create_list();
  add_to_start(list, 1);
  add_to_start(list, 2);
  Status actual = add_to_end(list, 5);
  assert_equal(1, actual, description);
}

void run_Tests_For_add_to_end() {
  printf("--------- add_to_end---------\n");
  test_empty_list_for_add_to_end();
  test_long_list_for_add_to_end();
}