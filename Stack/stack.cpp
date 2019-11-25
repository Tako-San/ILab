#include "stack.h"
#include "interface.h"

bool stack_init(Stack * baby_stack, STK_ERR * err_code)
{
#define STACK_BABYSITTER(err)             \
{                                         \
  *err_code = err;                        \
  stack_is_OK(baby_stack, err_code);      \
  return false;                           \
}

  if(!baby_stack)
    STACK_BABYSITTER(STACK_NULLPTR_ERROR)

  baby_stack->can1 = (can_type*)calloc(STARTSIZE*sizeof(my_type) + 2*sizeof(can_type), sizeof(char));
  if(!baby_stack->can1)
    STACK_BABYSITTER(STACK_MEM_ERROR)

  baby_stack->data = (my_type *)(baby_stack->can1 + 1);
  baby_stack->can2 = (can_type *)(baby_stack->data + STARTSIZE);

  baby_stack->size = STARTSIZE;
  baby_stack->cur_size = 0;

  baby_stack->eagle1 = eagle1_val;
  baby_stack->eagle2 = eagle2_val;

  *(baby_stack->can1) = can1_val;
  *(baby_stack->can2) = can2_val;

  stack_hash_recalc(baby_stack);

  return true;

#undef STACK_BABYSITTER
}

void stack_destroy(Stack * old_stack, STK_ERR * err_code)
{
  if(!old_stack)
  {
    *err_code = STACK_NULLPTR_ERROR;
    stack_is_OK(old_stack, err_code);
    return;
  }
  *err_code = STACK_DESTROYED;
  free(old_stack->can1);
  old_stack->size = DEADSTACK;
  old_stack->cur_size = DEADSTACK;
  stack_hash_recalc(old_stack);
}


bool stack_push(Stack * stack, STK_ERR * err_code, my_type new_elem)
{
  if(!stack_is_OK(stack, err_code))
    return false;

  if(stack->cur_size >= stack->size)
  {
    stack_resize(stack, err_code, STACK_INCREASE);
    if(!stack_is_OK(stack, err_code))
      return false;
  }

  size_type pos = stack->cur_size++;
  stack->data[pos] = new_elem;

  stack_hash_recalc(stack);

  if(!stack_is_OK(stack, err_code))
    return false;

  return true;
}

my_type stack_peek(Stack * stack, STK_ERR * err_code)
{
  if(stack->cur_size == 0)
    *err_code = STACK_UNDERFLOW;
  if(!stack_is_OK(stack, err_code))
    return THE_STRASHNAYA_CONSTANTA;  // See: Pennywise et al. Murder and Nightmare. Proc. Prof. Killers conf. NY, 2019

  size_type pos = stack->cur_size - 1;
  my_type   res = stack->data[pos];

  if(!stack_is_OK(stack, err_code))
    return THE_STRASHNAYA_CONSTANTA;
  else
    return res;
}

my_type stack_pop(Stack * stack, STK_ERR * err_code)
{
  if(stack->cur_size == 0)
    *err_code = STACK_UNDERFLOW;
  if(!stack_is_OK(stack, err_code))
    return THE_STRASHNAYA_CONSTANTA;

  if(stack->cur_size < (stack->size/RE_COEFF) - DELTA)
  {
    stack_resize(stack, err_code, STACK_REDUCE);
    if(!stack_is_OK(stack, err_code))
      return THE_STRASHNAYA_CONSTANTA;
  }

  my_type res = stack->data [--stack->cur_size];

  stack_hash_recalc(stack);

  if(!stack_is_OK(stack, err_code))
    return THE_STRASHNAYA_CONSTANTA;
  else
    return res;
}

bool stack_resize(Stack * stack, STK_ERR * err_code, STK_RESIZE relay)
{
#define STACK_CALL_THE_POLICE(err)                        \
{                                                         \
  *err_code = err;                                        \
  stack_is_OK(stack, err_code);                           \
  return false;                                           \
}

  if(!stack_is_OK(stack, err_code))
    return false;

  if(relay == STACK_INCREASE)
    stack->size *= RE_COEFF;
  else if(relay == STACK_REDUCE)
    stack->size /= RE_COEFF;
  else
    STACK_CALL_THE_POLICE(STACK_NEW_SIZE_ERROR)

  can_type can2_temp = *stack->can2;

  can_type * temp = (can_type *)realloc(stack->can1, stack->size*sizeof(my_type) + 2*sizeof(can_type));
  if(!temp)
    STACK_CALL_THE_POLICE(STACK_NEW_SIZE_ERROR)

  stack->can1 = (can_type *)temp;
  stack->data = (my_type *)(temp + 1);
  stack->can2 = (can_type *)(stack->data + stack->size);

  *stack->can2 = can2_temp;

  stack_hash_recalc(stack);

  return true;
#undef STACK_CALL_THE_POLICE
}



bool stack_is_OK(Stack * stack, STK_ERR* err_code)
{
#define STACK_COND_CHECK(cond, err)                    \
else if(cond)                                          \
{                                                      \
  *err_code = err;                                     \
  stack_dump(stack, err_code);                         \
  stack_destroy(stack, err_code);                      \
  return false;                                        \
}

if(*err_code == STACK_UNDERFLOW)
  return false;

STACK_COND_CHECK(stack == nullptr, STACK_NULLPTR_ERROR)

STACK_COND_CHECK(*err_code == STACK_NEW_SIZE_ERROR, STACK_NEW_SIZE_ERROR)

STACK_COND_CHECK(stack->size < stack->cur_size, STACK_SIZE_ERROR)

STACK_COND_CHECK(stack->eagle1 != eagle1_val, STACK_EAGLE1_ERROR)

STACK_COND_CHECK(stack->eagle2 != eagle2_val, STACK_EAGLE2_ERROR)

STACK_COND_CHECK(*stack->can1 != can1_val, STACK_CAN1_ERROR)

STACK_COND_CHECK(*stack->can2 != can2_val, STACK_CAN2_ERROR)

STACK_COND_CHECK(stack->data_hash != stack_hash_calc(stack->data, sizeof(my_type), stack->size), STACK_DATA_ERROR)

STACK_COND_CHECK(stack->hash != stack_hash_hash(stack), STACK_HASH_ERROR)

else
  return true;

#undef STACK_COND_CHECK
}

void stack_data_print(Stack * stack)
{
  printf("\n");
  if(stack->cur_size == 0)
  {
    printf("Stack is empty\n");
  }
  else
  {
    for(size_type i = 0; i < stack->cur_size; i++)
    {
      printf("stack.data[%llu] = ", i);
      std::cout << stack->data[i] << std::endl;
    }
  }
  printf("\n");
}

void stack_dump(Stack * stack, STK_ERR * err_code)
{
  stack_fury(err_code);

  printf("can1 =   %16llX     can1_val =  %17llX    %s\n", *(stack->can1), can1_val, can1_val == *(stack->can1)?"OK":"ERR");
  printf("can2 =   %16llX     can2_val =  %17llX    %s\n", *(stack->can2), can2_val, can2_val == *(stack->can2)?"OK":"ERR");

  printf("\n");

  printf("eagle1 = %16llX     eagle1_val =  %15llX    %s\n", stack->eagle1, eagle1_val, eagle1_val == stack->eagle1?"OK":"ERR");
  printf("eagle2 = %16llX     eagle2_val =  %15llX    %s\n", stack->eagle2, eagle2_val, eagle2_val == stack->eagle2?"OK":"ERR");

  printf("\n");

  hash_type temp = stack_hash_calc(stack->data, sizeof(my_type), stack->size);
  printf("dhash =  %16llX     real dhash = %16llX    %s\n", stack->data_hash, temp, temp == stack->data_hash?"OK":"ERR");

  temp = stack_hash_hash(stack);
  printf("hash =   %16llX     real hash =  %16llX    %s\n", stack->hash, temp, temp == stack->hash?"OK":"ERR");

  printf("\n");

  printf("size = %llu                         \n", stack->size);
  printf("cur_size = %llu                     \n", stack->cur_size);

  stack_data_print(stack);
  split();
}

hash_type stack_hash_calc(void *data, size_t size_of, size_t num)
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

hash_type stack_hash_hash(Stack * stack)
{
  hash_type temp = stack->hash;
  stack->hash = 0;

  hash_type result = stack_hash_calc(stack, sizeof(Stack));
  stack->hash = temp;

  return result;
}

bool stack_hash_recalc(Stack * stack)
{
  stack->hash = stack->data_hash = 0;

  stack->data_hash = stack_hash_calc(stack->data, sizeof(my_type), stack->size);
  stack->hash = stack_hash_calc(stack, sizeof(Stack));

  return true;
}


void stack_fury(STK_ERR* err_code)
{
  char rage[MAGICNUM] = {};
  char reason[MAGICNUM] = {};

  #define STACK_PHRASE_CHOISE(err, str1, str2)           \
  case err:          strcpy(rage, str1);                 \
                     strcpy(reason, str2);               \
                     break;                              \

  switch(*err_code)
  {
    STACK_PHRASE_CHOISE(STACK_NICE, "idk what, why r u called me", "Error code is STACK_NICE.")

    STACK_PHRASE_CHOISE(STACK_OVERFLOW, "STACK", "Stack overflow.")

    STACK_PHRASE_CHOISE(STACK_CAN1_ERROR, "FIRST CANARY", "Canary1 value changed.")

    STACK_PHRASE_CHOISE(STACK_CAN2_ERROR, "SECOND CANARY", "Canary2 value changed.")

    STACK_PHRASE_CHOISE(STACK_HASH_ERROR, "HASH", "Real hash and calced hash doesn't match.")

    STACK_PHRASE_CHOISE(STACK_SIZE_ERROR, "STACK SIZE", "):(")

    STACK_PHRASE_CHOISE(STACK_DATA_ERROR, "DATA", "Data changed.")

    STACK_PHRASE_CHOISE(STACK_MEM_ERROR, "MEMORY", "Memory error.")

    STACK_PHRASE_CHOISE(STACK_NEW_SIZE_ERROR, "NEW SIZE OF STACK", "Memory reallocation error.")

    STACK_PHRASE_CHOISE(STACK_EAGLE1_ERROR, "FIRST EAGLE", "Eagle1 value changed.")

    STACK_PHRASE_CHOISE(STACK_EAGLE2_ERROR, "SECOND EAGLE", "Eagle2 value changed.")

    STACK_PHRASE_CHOISE(STACK_DESTROYED, "DEADSTACK", "Stack is already dead, don't touch it.")

    STACK_PHRASE_CHOISE(STACK_UNDERFLOW, "EMPTY STACK", "How dare you call me to underflow stack?")

    STACK_PHRASE_CHOISE(STACK_NULLPTR_ERROR, "YOU DON'T EVEN KNOW WHAT", "Yor stack has nullptr.")
  }

  for(int i = 0; i < 2; i++)
    split();
  printf("YOU WANNA FUCK MY %s? FUCK YOU.\n\n", rage);
  printf("%s\n", reason);
  for(int i = 0; i < 2; i++)
    split();

  #undef STACK_PHRASE_CHOISE
}
