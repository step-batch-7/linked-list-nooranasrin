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
void test_remove_from_empty_list_for_remove_from_start();
void test_remove_from_long_list_for_remove_from_start();
void run_tests_for_remove_from_end();
void test_remove_from_empty_list_for_remove_from_end();
void test_remove_from_long_list_for_remove_from_end();
void test_remove_from_a_single_elment_list();
void test_invalid_position_for_remove_at();
void test_position_0_for_remove_at();
void test_add_to_end_for_remove_at();
void test_add_to_middle_for_remove_at();
void run_tests_for_remove_at();
void run_tests_for_remove_first_occurrence();
void test_non_existing_element();
void test_single_occurrence();
void test_multiple_occurrence();
void run_tests_for_remove_all_occurrences();

#endif
