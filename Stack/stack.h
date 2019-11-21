#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>


typedef int my_type;


typedef unsigned long long size_type;
typedef unsigned long long hash_type;
typedef unsigned long long can_type;

//#define (STARTSIZE*sizeof(my_type)+2*sizeof(can_type)) INIT

const can_type can1_val = 0xBBBDFDFD;
const can_type can2_val = 0XBACFCABF;

const can_type eagle1_val = 0xDEADBEEF;
const can_type eagle2_val = 0xAAADDDCB;



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
  STARTSIZE = 1, //начальный размер массива стека
  DEADSTACK = 0, //мертвый стек
  DEADHASH = 0
};

void init(Stack * new_stack);
void destroy(Stack * old_stack);

void push(Stack * stack);
my_type peek(Stack * stack);
my_type pop(Stack * stack);
void stack_resize(Stack * stack);

void data_print(Stack * stack);
void dump(Stack * stack);
bool is_OK(Stack * stack);
hash_type hash_calc(Stack * stack);

void invite();
void split();
int what_to_do(Stack * stack);
void fury();

#endif
