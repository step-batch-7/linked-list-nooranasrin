#include<stdio.h>
#include "../list.h"
#include "testList.h"

void assert_equal(int expectedValue, int actualValue, char *message) {
  char symbol[] = "✅";

  if(expectedValue !=actualValue ) {
    char error_symbol[] = "❌";
    char errorMessage[] = "failing\n";
    printf("%s %s",error_symbol, errorMessage);
    return;
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
  printf("\n");
}

void test_empty_list_for_add_to_start() {
  char description[] = "should add to the 0th position of an empty list\n";
  List_ptr list = create_list();
  Status actual = add_to_start(list, 5);
  assert_equal(1, actual, description);
}

void test_long_list_for_add_to_start() {
  char description[] = "should add to the start of a long list\n";
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 2);
  Status actual = add_to_start(list, 5);
  assert_equal(1, actual, description);
}

void run_Tests_For_add_to_start() {
  printf("--------- add_to_start---------\n");
  test_empty_list_for_add_to_start();
  test_long_list_for_add_to_start();
  printf("\n");
}

void test_invalid_position_for_insert_at() {
  char description[] = "should give Failure when the position is not valid\n";
  List_ptr list = create_list();
  Status actual = insert_at(list, 5, 3);
  assert_equal(0, actual, description);
  actual = insert_at(list, 5, -3);
  assert_equal(0, actual, description);
}

void test_position_0_for_insert_at() {
  char description[] = "should add the element into the 0th position when the position is 0\n";
  List_ptr list = create_list();
  Status actual = insert_at(list, 5, 0);
  assert_equal(1, actual, description);
}

void test_add_to_end_for_insert_at() {
  char description[] = "should add the element into the end of the list when the position is equal to the length of the list\n";
  List_ptr list = create_list();
  add_to_start(list , 1);
  add_to_start(list, 2);
  Status actual = insert_at(list, 5, 2);
  assert_equal(1, actual, description);
}

void test_add_to_middle() {
  char description[] = "should add to the middle of the list when the position is in between 0 and length of the list\n";
  List_ptr list = create_list();
  add_to_start(list , 1);
  add_to_start(list, 2);
  Status actual = insert_at(list, 5, 1);
  assert_equal(1, actual, description);
}

void run_Tests_For_insert_at() {
  printf("--------- insert_at---------\n");
  test_invalid_position_for_insert_at();
  test_position_0_for_insert_at();
  test_add_to_end_for_insert_at();
  test_add_to_middle();
  printf("\n");
}