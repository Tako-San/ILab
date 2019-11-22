#include "stack.h"
#include "interface.h"

void init(Stack * new_stack, STK_ERR * err_code)
{
  new_stack->can1 = (can_type*)calloc(STARTSIZE*sizeof(my_type) + 2*sizeof(can_type), 1);
  if(new_stack->can1 == NULL)
  {
    //printf("Memory allocation error\n");
    *err_code = STACK_MEM_ERROR;
    return;
  }

  new_stack->data = (my_type *)(new_stack->can1 + 1);
  new_stack->can2 = (can_type *)(new_stack->data + STARTSIZE);

  new_stack->size = STARTSIZE;
  new_stack->cur_size = 0;

  new_stack->eagle1 = eagle1_val;
  new_stack->eagle2 = eagle2_val;

  new_stack->hash = hash_calc(new_stack, err_code);

  *(new_stack->can1) = can1_val;
  *(new_stack->can2) = can2_val;
}

void destroy(Stack * old_stack, STK_ERR * err_code)
{
  *err_code = STACK_DESTROYED;
  free(old_stack->can1);
  old_stack->size = DEADSTACK;
  old_stack->cur_size = DEADSTACK;
  old_stack->hash = hash_calc(old_stack, err_code);
}


void push(Stack * stack, STK_ERR * err_code)
{
  if(!is_OK(stack, err_code))
    return;

  if(stack->cur_size >= stack->size)
  {
    stack_resize(stack, err_code);
  }

  stack->cur_size++;

  printf("Enter next stack element: ");

  /*my_type temp = 0;
  while(!(std::cin >> temp))
    fflush(stdin);
  stack->data[stack->cur_size - 1] = temp;*/

  std::cin >> stack->data[stack->cur_size - 1];
  stack->hash = hash_calc(stack, err_code);
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

  size_type i = stack->cur_size - 1;
  my_type rez = stack->data[i];
  stack->cur_size--;
  stack->hash = hash_calc(stack, err_code);

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
    printf("REallocation error\n");
    exit(1);
  }
  else
  {
    stack->can1 = (can_type *)temp;
    stack->data = (my_type *)(temp + 1);
    stack->can2 = (can_type *)(stack->data + stack->size);

    *stack->can2 = can2_temp;

    stack->hash = hash_calc(stack, err_code);
  }
}



bool is_OK(Stack * stack, STK_ERR* err_code)
{
  if(stack->eagle1 != eagle1_val)
  {
    *err_code = STACK_EAGLE1_ERROR;
    //printf("\n\nEAGLE1 CHANGED\n\n");
    //fury();
    dump(stack, err_code);
    return false;
    //exit(1);
  }
  else if(stack->eagle2 != eagle2_val)
  {
    *err_code = STACK_EAGLE2_ERROR;
    //printf("\n\nEAGLE2 CHANGED\n\n");
    //fury();
    dump(stack, err_code);
    return false;
    //exit(1);
  }
  else if(*stack->can1 != can1_val)
  {
    *err_code = STACK_CAN1_ERROR;
    //printf("\n\nCANARY1 CHANGED\n\n");
    //fury();
    dump(stack, err_code);
    return false;
    //exit(1);
  }
  else if(*stack->can2 != can2_val)
  {
    *err_code = STACK_CAN2_ERROR;
    //printf("\n\nCANARY2 CHANGED\n\n");
    //fury();
    dump(stack, err_code);
    return false;
    //exit(1);
  }
  else if(stack->hash != hash_calc(stack, err_code))
  {
    *err_code = STACK_HASH_ERROR;
    //printf("\n\nHASH CHANGED\n\n");
    //fury();
    dump(stack, err_code);
    return false;
    //exit(1);
  }
  else
    return true;
}

void data_print(Stack * stack)
{
  printf("\n");
  for(size_type i = 0; i < stack->cur_size; i++)
  {
    printf("stack.data[%llu] = ", i);
    std::cout <<stack->data[i]<< "\n";
  }
  printf("\n");
}

void dump(Stack * stack, STK_ERR * err_code)
{
  fury(err_code);

  printf("can1 =   %16llX     can1_val = %17llX   %s\n", *(stack->can1), can1_val, can1_val == *(stack->can1)?"OK":"ERR");
  printf("can2 =   %16llX     can2_val = %17llX   %s\n", *(stack->can2), can2_val, can2_val == *(stack->can2)?"OK":"ERR");

  printf("\n");

  printf("eagle1 = %16llX     eagle1_val = %15llX   %s\n", stack->eagle1, eagle1_val, eagle1_val == stack->eagle1?"OK":"ERR");
  printf("eagle2 = %16llX     eagle2_val = %15llX   %s\n", stack->eagle2, eagle2_val, eagle2_val == stack->eagle2?"OK":"ERR");

  printf("\n");

  hash_type temp = hash_calc(stack, err_code);
  printf("hash =   %16llX     real hash = %16llX   %s\n", stack->hash, temp, temp == stack->hash?"OK":"ERR");

  printf("\n");

  printf("size = %llu                         \n", stack->size);
  printf("cur_size = %llu                     \n", stack->cur_size);

  data_print(stack);
}

hash_type hash_calc(Stack * stack, STK_ERR * err_code)
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

  /*hash_type hash = 0;

  for (size_type i = 0; i < stack->cur_size; i++)
  {
    hash += (unsigned char)(stack->data[i]);
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);*/

  /*for(unsigned i = 0; i < stack->cur_size; i++)
  {
    hash += (stack->cur_size - i)*stack->data[i];
  }

  hash += 69*(stack->eagle1%420);
  hash += 420*(stack->eagle2%69);
  hash += 89*(stack->size/30);
  hash += 17*(stack->cur_size);*/
  stack->hash = old_hash;

  return hash;
}



void fury(STK_ERR* err_code)
{
  char rage[MAGICNUM] = {};
  char reason[MAGICNUM] = {};
  switch (*err_code) {
    case STACK_NICE:          strcpy(rage, "idk what, why r u called me");
                              strcpy(reason, "Error code is STACK_NICE.");
                              break;
    case STACK_OVERFLOW:      strcpy(rage, "STACK");
                              strcpy(reason, "Stack overflow.");
                              break;
    case STACK_CAN1_ERROR:    strcpy(rage, "CANARY1");
                              strcpy(reason, "Canary1 value changed.");
                              break;
    case STACK_CAN2_ERROR:    strcpy(rage, "CANARY2");
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
    case STACK_EAGLE1_ERROR:  strcpy(rage, "EAGLE1");
                              strcpy(reason, "Eagle1 value changed.");
                              break;
    case STACK_EAGLE2_ERROR:  strcpy(rage, "EAGLE2");
                              strcpy(reason, "Eagle2 value changed.");
                              break;
    case STACK_DESTROYED:     strcpy(rage, "DEADSTACK");
                              strcpy(reason, "Stack is already dead, don't touch it.");
                              break;
  }

  for(int i = 0; i < 2; i++)
    split();
  printf("YOU WANNA FUCK MY %s? FUCK YOU.\n", rage);
  printf("%s\n", reason);
  for(int i = 0; i < 2; i++)
    split();
}
