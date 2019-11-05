#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>

typedef unsigned ui;
typedef long long int lli;

typedef struct Stack
{
  int* stk;     //массив со стеком
  ui size;        //текущий размер массива
  ui cur_size;    //активный размер стека
  lli hash;       //хэш
}Stack;

enum
{
  STARTSIZE = 10, //начальный размер массива стека
  DEADSTACK = 0  //мертвый стек
};

void init(Stack * new_stack);
void invite();
void destroy(Stack * old_stack);

void push(Stack * stack);
int peek(Stack * stack);
int pop(Stack * stack);
void stack_resize(Stack * stack);

void split();
int what_to_do(Stack * stack);

#endif
