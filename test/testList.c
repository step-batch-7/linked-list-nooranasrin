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

