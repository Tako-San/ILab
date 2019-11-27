#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <assert.h>

#define LOCATION __LINE__, __FILE__, __PRETTY_FUNCTION__


typedef int my_type;

typedef unsigned long long size_type;
typedef unsigned long long hash_type;
typedef unsigned long long can_type;


const can_type can1_val   = 0xBBBDFDFD;
const can_type can2_val   = 0XBACFCABF;

const can_type eagle1_val = 0xDEADBEEF;
const can_type eagle2_val = 0xAAADDDCB;


enum STK_ERR
{
  STACK_NICE              =     0,
  STACK_OVERFLOW          =     1,
  STACK_CAN1_ERROR        =     2,
  STACK_CAN2_ERROR        =     3,
  STACK_HASH_ERROR        =     4,
  STACK_SIZE_ERROR        =     5,
  STACK_DATA_ERROR        =     6,
  STACK_MEM_ERROR         =     7,
  STACK_NEW_SIZE_ERROR    =     8,
  STACK_EAGLE1_ERROR      =     9,
  STACK_EAGLE2_ERROR      =    10,
  STACK_NULLPTR_ERROR     =    11,
  STACK_DESTROYED         =    12,
  STACK_UNDERFLOW         =    13,
};

class Stack
{
public:

  can_type    eagle1;

  my_type*    data;     //массив со стеком
  size_type   size;        //текущий размер массива
  size_type   cur_size;    //активный размер стека

  hash_type   hash;       //хэш
  hash_type   data_hash;
  can_type*   can1;
  can_type*   can2;
  STK_ERR     err_code;

  can_type    eagle2;
};

enum
{
  RE_COEFF                 =     2,  //коэффициент при увеличении размера стека
  STARTSIZE                =     1, //начальный размер массива стека
  DEADSTACK                =     0, //мертвый стек
  DEADHASH                 =     0,
  MAGICNUM                 =   500,
  THE_STRASHNAYA_CONSTANTA =   666,
  DELTA                    =     2,
};

enum STK_RESIZE
{
  STACK_INCREASE   = 10,
  STACK_REDUCE     =  1,
};

bool       stack_init(Stack * baby_stack);
void       stack_destroy(Stack * old_stack);

bool       stack_push(Stack * stack, my_type new_elem);
my_type    stack_peek(Stack * stack);
my_type    stack_pop(Stack * stack);
bool       stack_resize(Stack * stack, STK_RESIZE relay);

void       stack_data_print(Stack * stack);
//void       stack_dump(Stack * stack);
void       stack_dump(Stack * stack, int line, const char * filename, const char * funcname);
bool       stack_is_OK(Stack * stack, int line, const char * filename, const char * funcname);
void       stack_fury(STK_ERR err_code);

hash_type  stack_hash_calc(void *data, size_t size_of, size_t num = 1);
bool       stack_hash_recalc(Stack * stack);
hash_type  stack_hash_hash(Stack * stack);

#endif
