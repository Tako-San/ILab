#include "stack.h"
#include "interface.h"

void init(Stack * baby_stack, STK_ERR * err_code)
{
  baby_stack->can1 = (can_type*)calloc(STARTSIZE*sizeof(my_type) + 2*sizeof(can_type), sizeof(char));
  if(baby_stack->can1 == NULL)
  {
    *err_code = STACK_MEM_ERROR;
    return;
  }
  baby_stack->data = (my_type *)(baby_stack->can1 + 1);
  baby_stack->can2 = (can_type *)(baby_stack->data + STARTSIZE);

  baby_stack->size = STARTSIZE;
  baby_stack->cur_size = 0;

  baby_stack->eagle1 = eagle1_val;
  baby_stack->eagle2 = eagle2_val;

  *(baby_stack->can1) = can1_val;
  *(baby_stack->can2) = can2_val;


  hash_recalc(baby_stack);
  /*baby_stack->data_hash = data_hash(baby_stack);
  baby_stack->hash = hash_calc(baby_stack);*/
}

void destroy(Stack * old_stack, STK_ERR * err_code)
{
  *err_code = STACK_DESTROYED;
  free(old_stack->can1);
  old_stack->size = DEADSTACK;
  old_stack->cur_size = DEADSTACK;
  hash_recalc(old_stack);
  //old_stack->hash = hash_calc(old_stack);
}


void push(Stack * stack, STK_ERR * err_code)
{
  if(!is_OK(stack, err_code))
    return;

  if(stack->cur_size >= stack->size)
  {
    stack_resize(stack, err_code);
    if(!is_OK(stack, err_code))
      return;
  }

  printf("Enter next stack element: ");
  std::cin >> stack->data[stack->cur_size++];

  hash_recalc(stack);
  //stack->data_hash = data_hash(stack);
  //stack->hash = hash_calc(stack);

  printf("\n");

  if(!is_OK(stack, err_code))
    return;
}

my_type peek(Stack * stack, STK_ERR * err_code)
{
  if(!is_OK(stack, err_code))
    return 666;

  size_type i = stack->cur_size - 1;
  my_type rez = stack->data[i];

  if(!is_OK(stack, err_code))
    return 666;

  else
    return rez;
}

my_type pop(Stack * stack, STK_ERR * err_code)
{
  if(!is_OK(stack, err_code))
    return 666;

  my_type rez = stack->data[--stack->cur_size];

  hash_recalc(stack);
  //stack->data_hash = data_hash(stack);
  //stack->hash = hash_calc(stack);

  if(!is_OK(stack, err_code))
    return 666;
  else
    return rez;
}

void stack_resize(Stack * stack, STK_ERR * err_code)
{
  if(!is_OK(stack, err_code))
    return;

  stack->size *= RE_COEFF;
  can_type can2_temp = *stack->can2;

  can_type * temp = (can_type *)realloc(stack->can1, stack->size*sizeof(my_type) + 2*sizeof(can_type));
  if(!temp)
  {
    *err_code = STACK_NEW_SIZE_ERROR;
    is_OK(stack, err_code);
    return;
  }

  stack->can1 = (can_type *)temp;
  stack->data = (my_type *)(temp + 1);
  stack->can2 = (can_type *)(stack->data + stack->size);

  *stack->can2 = can2_temp;

  hash_recalc(stack);
  //stack->data_hash = data_hash(stack);
  //stack->hash = hash_calc(stack);
}



bool is_OK(Stack * stack, STK_ERR* err_code)
{
#define STACK_COND_CHECK(cond, err)                    \
else if(cond)                                          \
{                                                      \
  *err_code = err;                                     \
  dumb(stack, err_code);                               \
  destroy(stack, err_code);                            \
  return false;                                        \
}

if(0)
  ;
STACK_COND_CHECK(*err_code == STACK_NEW_SIZE_ERROR, STACK_NEW_SIZE_ERROR)

STACK_COND_CHECK(stack->size < stack->cur_size, STACK_SIZE_ERROR)

STACK_COND_CHECK(stack->eagle1 != eagle1_val, STACK_EAGLE1_ERROR)

STACK_COND_CHECK(stack->eagle2 != eagle2_val, STACK_EAGLE2_ERROR)

STACK_COND_CHECK(*stack->can1 != can1_val, STACK_CAN1_ERROR)

STACK_COND_CHECK(*stack->can2 != can2_val, STACK_CAN2_ERROR)

STACK_COND_CHECK(stack->data_hash != hash_calc(stack->data, sizeof(my_type), stack->size)/*hash_calc(stack, sizeof(Stack))*/, STACK_DATA_ERROR)

STACK_COND_CHECK(stack->hash != hash_hash(stack), STACK_HASH_ERROR)

else
  return true;

/*if(*err_code == STACK_NEW_SIZE_ERROR)
  {
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
  }
  else if(stack->size < stack->cur_size)
  {
    *err_code = STACK_SIZE_ERROR;
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
  }
  else if(stack->eagle1 != eagle1_val)
  {
    *err_code = STACK_EAGLE1_ERROR;
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
  }
  else if(stack->eagle2 != eagle2_val)
  {
    *err_code = STACK_EAGLE2_ERROR;
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
  }
  else if(*stack->can1 != can1_val)
  {
    *err_code = STACK_CAN1_ERROR;
    //printf("\n\nCANARY1 CHANGED\n\n");
    //fury();
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
    //exit(1);
  }
  else if(*stack->can2 != can2_val)
  {
    *err_code = STACK_CAN2_ERROR;
    //printf("\n\nCANARY2 CHANGED\n\n");
    //fury();
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
    //exit(1);
  }
  else if(stack->data_hash != data_hash(stack))
  {
    *err_code = STACK_DATA_ERROR;
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
  }
  else if(stack->hash != hash_calc(stack))
  {
    *err_code = STACK_HASH_ERROR;
    //printf("\n\nHASH CHANGED\n\n");
    //fury();
    dumb(stack, err_code);
    destroy(stack, err_code);
    return false;
    //exit(1);
  }
  else
    return true;*/

    #undef STACK_COND_CHECK
}

void data_print(Stack * stack)
{
  printf("\n");
  for(size_type i = 0; i < stack->cur_size; i++)
  {
    printf("stack.data[%llu] = ", i);
    std::cout << stack->data[i] << std::endl;
  }
  printf("\n");
}

void dumb(Stack * stack, STK_ERR * err_code)
{
  fury(err_code);

  printf("can1 =   %16llX     can1_val = %17llX    %s\n", *(stack->can1), can1_val, can1_val == *(stack->can1)?"OK":"ERR");
  printf("can2 =   %16llX     can2_val = %17llX    %s\n", *(stack->can2), can2_val, can2_val == *(stack->can2)?"OK":"ERR");

  printf("\n");

  printf("eagle1 = %16llX     eagle1_val = %15llX    %s\n", stack->eagle1, eagle1_val, eagle1_val == stack->eagle1?"OK":"ERR");
  printf("eagle2 = %16llX     eagle2_val = %15llX    %s\n", stack->eagle2, eagle2_val, eagle2_val == stack->eagle2?"OK":"ERR");

  printf("\n");

  hash_type temp = hash_calc(stack->data, sizeof(my_type), stack->size);
  //hash_type temp = data_hash(stack);
  printf("dhash =  %16llX     real dhash = %15llX   %s\n", stack->data_hash, temp, temp == stack->data_hash?"OK":"ERR");

  temp = hash_calc(stack, sizeof(Stack));
  //temp = hash_calc(stack);
  printf("hash =   %16llX     real hash = %16llX    %s\n", stack->hash, temp, temp == stack->hash?"OK":"ERR");

  printf("\n");

  printf("size = %llu                         \n", stack->size);
  printf("cur_size = %llu                     \n", stack->cur_size);

  data_print(stack);
}

hash_type hash_calc(void *data, size_t size_of, size_t num /*= 1*/)
{
  const unsigned char* bytes = (unsigned char*)data;
  size_t bytes_len = size_of * num;

  hash_type hash = 0;

  for (size_t i = 0; i < bytes_len; i++)
  {
    hash +=  bytes[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}

hash_type hash_hash(Stack * stack)
{
  hash_type temp = stack->hash;
  stack->hash = 0;

  hash_type result = hash_calc(stack, sizeof(Stack));
  stack->hash = temp;

  return result;
}

bool hash_recalc(Stack * stack)
{
  stack->hash = stack->data_hash = 0;

  stack->data_hash = hash_calc(stack->data, sizeof(my_type), stack->size);
  stack->hash = hash_calc(stack, sizeof(Stack));

  return true;
}

/*hash_type hash_calc(Stack * stack)
{
  hash_type old_hash = stack->hash;
  stack->hash = 0;

  const unsigned char* bytes = (unsigned char*)stack;
  size_t bytes_len = sizeof(*stack);

  hash_type hash = 0;

  for (size_type i = 0; i < bytes_len; i++)
  {
    hash += (unsigned char)(bytes[i]);
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  stack->hash = old_hash;

  return hash;
}

hash_type data_hash(Stack * stack)
{
  hash_type hash = 0;

  for (size_t i = 0; i < stack->cur_size; i++)
  {
      hash += (unsigned char)(stack->data[i]);
      hash += (hash << 10);
      hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}*/

void fury(STK_ERR* err_code)
{
  char rage[MAGICNUM] = {};
  char reason[MAGICNUM] = {};
  switch (*err_code)
  {
    case STACK_NICE:          strcpy(rage, "idk what, why r u called me");
                              strcpy(reason, "Error code is STACK_NICE.");
                              break;
    case STACK_OVERFLOW:      strcpy(rage, "STACK");
                              strcpy(reason, "Stack overflow.");
                              break;
    case STACK_CAN1_ERROR:    strcpy(rage, "FIRST CANARY");
                              strcpy(reason, "Canary1 value changed.");
                              break;
    case STACK_CAN2_ERROR:    strcpy(rage, "SECOND CANARY");
                              strcpy(reason, "Canary2 value changed.");
                              break;
    case STACK_HASH_ERROR:    strcpy(rage, "HASH");
                              strcpy(reason, "Real hash and calced hash doesn't match.");
                              break;
    case STACK_SIZE_ERROR:    strcpy(rage, "STACK SIZE");
                              strcpy(reason, "):(");
                              break;
    case STACK_DATA_ERROR:    strcpy(rage, "DATA");
                              strcpy(reason, "Data changed.");
                              break;
    case STACK_MEM_ERROR:     strcpy(rage, "MEMORY");
                              strcpy(reason, "Memory error.");
                              break;
    case STACK_NEW_SIZE_ERROR:strcpy(rage, "NEW SIZE OF STACK");
                              strcpy(reason, "Memory reallocation error.");
                              break;
    case STACK_EAGLE1_ERROR:  strcpy(rage, "FIRST EAGLE");
                              strcpy(reason, "Eagle1 value changed.");
                              break;
    case STACK_EAGLE2_ERROR:  strcpy(rage, "SECOND EAGLE");
                              strcpy(reason, "Eagle2 value changed.");
                              break;
    case STACK_DESTROYED:     strcpy(rage, "DEADSTACK");
                              strcpy(reason, "Stack is already dead, don't touch it.");
                              break;
  }

  for(int i = 0; i < 2; i++)
    split();
  printf("YOU WANNA FUCK MY %s? FUCK YOU.\n\n", rage);
  printf("%s\n", reason);
  for(int i = 0; i < 2; i++)
    split();
}
