#ifndef __NUMBERS_H_
#define __NUMBERS_H_

void assert_equal(int expectedValue, int actualValue, char *message);
void test_empty_list_for_add_to_end();
void test_long_list_for_add_to_end();
void run_tests_for_add_to_end();
void test_empty_list_for_add_to_start();
void test_long_list_for_add_to_start();
void run_tests_for_add_to_start();
void run_tests_for_insert_at();
void test_invalid_position_for_insert_at();
void test_position_0_for_insert_at();
void test_add_to_end_for_insert_at();
void test_add_to_middle();
void run_tests_for_insert_at();
void test_add_unique_element();
void run_tests_for_add_unique();
void run_tests_for_remove_from_start();

#endif
