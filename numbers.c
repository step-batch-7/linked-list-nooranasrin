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
  printf("Please enter the alphabet of the operation you would like to perform\n");
}

int main(void) {
  print_menu();
  return 0;
}