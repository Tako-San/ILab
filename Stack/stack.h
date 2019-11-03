#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>

enum
{
  STARTSIZE = 10, //начальный размер массива стека
  DEADSTACK
};

typedef unsigned ui;

typedef struct Stack
{
  int* stack;     //массив со стеком
  ui size;        //текущий размер массива
  ui cur_size;    //активный размер стека
}Stack;

void init(Stack * new_stack);
void destroy(Stack * old_stack);
void invite();
void push(Stack * stack);
int peek(Stack * stack);
int pop(Stack * stack);
void split();
int what_to_do(Stack * stack);

#endif
