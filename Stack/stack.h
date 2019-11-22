#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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



class Stack
{
public:

  can_type eagle1;

  my_type* data;     //массив со стеком
  size_type size;        //текущий размер массива
  size_type cur_size;    //активный размер стека

  hash_type hash;       //хэш
  hash_type data_hash;
  can_type* can1;
  can_type* can2;

  can_type eagle2;
};

enum
{
  RE_COEFF = 2,  //коэффициент при увеличении размера стека
  STARTSIZE = 1, //начальный размер массива стека
  DEADSTACK = 0, //мертвый стек
  DEADHASH = 0,
  MAGICNUM = 500,
};

enum STK_ERR
{
  STACK_NICE             =     0,
  STACK_OVERFLOW         =     1,
  STACK_CAN1_ERROR       =     2,
  STACK_CAN2_ERROR       =     3,
  STACK_HASH_ERROR       =     4,
  STACK_SIZE_ERROR       =     5,
  STACK_DATA_ERROR       =     6,
  STACK_MEM_ERROR        =     7,
  STACK_NEW_SIZE_ERROR   =     8,
  STACK_EAGLE1_ERROR     =     9,
  STACK_EAGLE2_ERROR     =    10,
  STACK_DESTROYED        =    11,
};

void init(Stack * baby_stack, STK_ERR * err_code);
void destroy(Stack * old_stack, STK_ERR * err_code);

void push(Stack * stack, STK_ERR * err_code);
my_type peek(Stack * stack, STK_ERR * err_code);
my_type pop(Stack * stack, STK_ERR * err_code);
void stack_resize(Stack * stack, STK_ERR * err_code);

void data_print(Stack * stack);
void dumb(Stack * stack, STK_ERR * err_code);
bool is_OK(Stack * stack, STK_ERR* err_code);

hash_type hash_calc(void *data, size_t size_of, size_t num = 1);
bool hash_recalc(Stack * stack);
hash_type hash_hash(Stack * stack);

/*hash_type data_hash(Stack * stack);
hash_type hash_calc(Stack * stack);*/

#endif
