#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>



typedef unsigned long long size_type;
typedef unsigned long long hash_type;
typedef unsigned long long can_type;

typedef int my_type;
//typedef long long int lli;

//#define (STARTSIZE*sizeof(my_type)+2*sizeof(can_type)) INIT

typedef struct Stack
{
  can_type eagle1;

  my_type* data;     //массив со стеком
  size_type size;        //текущий размер массива
  size_type cur_size;    //активный размер стека

  hash_type hash;       //хэш
  can_type* can1;
  can_type* can2;
  
  can_type eagle2;
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
my_type peek(Stack * stack);
my_type pop(Stack * stack);
void stack_resize(Stack * stack);

void split();
int what_to_do(Stack * stack);

#endif
