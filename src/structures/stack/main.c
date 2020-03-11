#include <stdio.h>
#include "stack.h"

int main()
{
  Stack *stack = stack_create();

  printf("%lx", sizeof(stack));

  return 0;
}