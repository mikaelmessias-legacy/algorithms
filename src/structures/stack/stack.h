#ifndef STACK_H
#define STACK_H

typedef struct node *Stack;

Stack *stack_create();

void stack_push();

int stack_pop();

int stack_size();

void stack_destroy();

#endif