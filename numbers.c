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

void perform_operation(int option, List_ptr list, int number) {
  Status isDone;

  switch (option)
  {
    case 'a':
      isDone = add_to_end(list, number);
      print_status_of_operation(isDone, list);
      break;

    case 'b':
      isDone = add_to_start(list, number);
      print_status_of_operation(isDone, list);
      break;
  }
}


int main(void) {
  char option;
  List_ptr list = create_list();
  int number;

  print_menu();
  scanf(" %c", &option);

  while (option != 'm') {
    printf("Enter the number\n");
    scanf("%d", &number);
    perform_operation(option, list, number);
    print_menu();
    scanf(" %c", &option);
  }

  return 0;
} 