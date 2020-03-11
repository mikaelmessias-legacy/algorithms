#include <stdlib.h>
#include "stack.h"

struct node
{
  int data;
  struct node *prox;
};

typedef struct node Node;

Stack *stack_create()
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));

  if (stack != NULL)
  {
    *stack = NULL;
  }

  return stack;
}