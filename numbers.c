#include<stdio.h>
#include "list.h"
#include "numbers.h"

void print_menu(void) {
  printf("Main Menu\n");
  printf("---------\n");
  char menu[MENU_LENGTH][85] = MENU;

  for (int index = 0; index < MENU_LENGTH; index++) {
    printf("%s\n", menu[index]);
  }
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
}

void print_status_of_operation(Status isDone, List_ptr list) {
  if(isDone) {
    printf("operation performed successfully\n");
    display(list);
    printf("\n");
    return;
  }
  printf("operation can't perform\n");
}

void perform_operation(int option, List_ptr list) {
  Status isDone;
  int number, position;

  switch (option)
  {
    case 'a':
      printf("Enter the number to insert at the end of the list\n");
      scanf("%d", &number);
      isDone = add_to_end(list, number);
      break;

    case 'b':
      printf("Enter the number to insert at the starting of the list\n");
      scanf("%d", &number);
      isDone = add_to_start(list, number);
      break;

    case 'c':
      printf("Enter the position and number to insert into the list\n");
      scanf("%d%d", &position, &number);
      isDone = insert_at(list, number, position);
      break;

    case 'd':
      printf("Enter the number to insert into the list\n");
      scanf("%d", &number);
      isDone = add_unique(list, number);
      break;

    case 'e':
      isDone = remove_from_start(list);
      break;

    case 'f':
      isDone = remove_from_end(list);
      break;

    case 'g':
      printf("Enter the position to delete the element\n");
      scanf("%d", &position);
      isDone = remove_at(list, position);
      break;

    case 'h':
      printf("Enter the number to remove\n");
      scanf("%d", &number);
      isDone = remove_first_occurrence(list, number);
      break;

    case 'i':
      printf("Enter the number to remove\n");
      scanf("%d", &number);
      isDone = remove_all_occurrences(list, number);
      break;

    default:
      printf("Enter a valid option\n");
  }

  print_status_of_operation(isDone, list);
}

  
int main(void) {
  char option;
  List_ptr list = create_list();

  print_menu();
  scanf(" %c", &option);

  while (option != 'm') {
    perform_operation(option, list);
    print_menu();
    scanf(" %c", &option);
  }

  return 0;
} 