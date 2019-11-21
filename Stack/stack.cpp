#include "stack.h"


void init(Stack * new_stack)
{
  new_stack->can1 = (can_type*)calloc(STARTSIZE*sizeof(my_type) + 2*sizeof(can_type), 1);
  if(new_stack->can1 == NULL)
  {
    printf("Memory allocation error\n");
    exit(1);
  }

  new_stack->data = (my_type *)(new_stack->can1 + 1);
  new_stack->can2 = (can_type *)(new_stack->data + STARTSIZE);

  new_stack->size = STARTSIZE;
  new_stack->cur_size = 0;

  new_stack->eagle1 = eagle1_val;
  new_stack->eagle2 = eagle2_val;

  new_stack->hash = hash_calc(new_stack);

  *(new_stack->can1) = can1_val;
  *(new_stack->can2) = can2_val;
}

void destroy(Stack * old_stack)
{
  free(old_stack->can1);
  old_stack->size = DEADSTACK;
  old_stack->cur_size = DEADSTACK;
  old_stack->hash = hash_calc(old_stack);
}



void invite()
{
  printf("What u wanna do, dude? You can:\n");
  printf("      0 - exit\n");
  printf("      1 - add number to stack\n");
  printf("      2 - see last element\n");
  printf("      3 - look at last elemet last time and delete\n");
  printf("      4 - print stack data\n\n");
}

void split()
{
  printf("_____________________________________________________\n\n");
}

int what_to_do(Stack * stack)
{
  int user_wish;
  int condition = 1;
  my_type last_elem;

  split();
  printf("0 - exit  1 - push  2 - peek  3 - pop  4 - print data\n");
  split();
  printf("Your choose is number: ");
  while(!scanf("%d", &user_wish))
  {
    printf("Wrong number, man. Try again\n");
    scanf("%*[^\n]");
  }
  printf("\n");

  switch(user_wish)
  {
    case 0: destroy(stack);
            printf("Bye ;(\n\n");
            condition = 0;
            break;
    case 1: push(stack);
            condition = 1;
            //split();
            break;
    case 2: if(stack->cur_size == 0)
              printf("Your stack is empty\n");
            else
            {
              last_elem = peek(stack);
              printf("\nLast elem = ");
              std::cout << last_elem;
              printf("\n");
            }
            condition = 1;
            //split();
            break;
    case 3: if(stack->cur_size == 0)
              printf("\nYour stack is empty\n");
            else
            {
              last_elem = pop(stack);
              printf("\nLast elem = ");
              std::cout << last_elem;
              printf("\nIt was deleted\n");
            }
            condition = 1;
            //split();
            break;
    case 4: data_print(stack);
            break;
    default:  printf("Wrong number, man. Try again\n");
              condition = 1;
              //split();
              break;
  }

  return condition;
}



void push(Stack * stack)
{
  assert(is_OK(stack));
  if(stack->cur_size >= stack->size)
  {
    stack_resize(stack);
  }

  stack->cur_size++;
  printf("Enter next stack element: ");
  //scanf("%d", &(stack->data[stack->cur_size - 1]));
  std::cin >> stack->data[stack->cur_size - 1];
  stack->hash = hash_calc(stack);
  printf("\n");
}

my_type peek(Stack * stack)
{
  assert(is_OK(stack));
  size_type i = stack->cur_size - 1;
  my_type rez = stack->data[i];
  //stack->hash = hash_calc(stack);
  return rez;
}

my_type pop(Stack * stack)
{
  assert(is_OK(stack));
  size_type i = stack->cur_size - 1;
  my_type rez = stack->data[i];
  stack->cur_size--;
  stack->hash = hash_calc(stack);
  return rez;
}

void stack_resize(Stack * stack)
{
  assert(is_OK(stack));
  stack->size *= 2;
  can_type can2_temp = *stack->can2;
  /*stack->can1 = (can_type *)realloc((can_type *)stack->data - 1, stack->size*sizeof(my_type) + 2*sizeof(can_type));
  stack->data = (my_type *)(stack->can1 + 1);
  stack->can2 = (can_type *)(stack->data + stack->size - 1);
  if(!stack->data)
  {
    printf("REallocation error\n");
    exit(1);
  }
  //stack->can2 = (can_type *)(stack->data + stack->size)+1;*/
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

    stack->hash = hash_calc(stack);
  }
}


bool is_OK(Stack * stack)
{
  if(stack->eagle1 != eagle1_val)
  {
    printf("\n\nEAGLE1 CHANGED\n\n");
    fury();
    dump(stack);
    exit(1);
  }
  else if(stack->eagle2 != eagle2_val)
  {
    printf("\n\nEAGLE2 CHANGED\n\n");
    fury();
    dump(stack);
    exit(1);
  }
  else if(*stack->can1 != can1_val)
  {
    printf("\n\nCANARY1 CHANGED\n\n");
    fury();
    dump(stack);
    exit(1);
  }
  else if(*stack->can2 != can2_val)
  {
    printf("\n\nCANARY2 CHANGED\n\n");
    fury();
    dump(stack);
    exit(1);
  }
  else if(stack->hash != hash_calc(stack))
  {
    printf("\n\nHASH CHANGED\n\n");
    fury();
    dump(stack);
    exit(1);
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

void dump(Stack * stack)
{
  printf("can1 = %llu   can1_val = %llu\n", *(stack->can1), can1_val);
  printf("can2 = %llu   can2_val = %llu\n", *(stack->can2), can2_val);

  printf("eagle1 = %llu   eagle1_val = %llu\n", stack->eagle1, eagle1_val);
  printf("eagle2 = %llu   eagle2_val = %llu\n", stack->eagle2, eagle2_val);

  printf("size = %llu\n", stack->size);
  printf("cur_size = %llu\n", stack->cur_size);

  data_print(stack);
}

void fury()
{
  for(int i = 0; i < 4; i++)
    split();
  printf("YOU WANNA FUCK MY STACK? FUCK YOU\n");
  for(int i = 0; i < 4; i++)
    split();
}


hash_type hash_calc(Stack * stack)
{
  hash_type hash = 0;

  for (size_type i = 0; i < stack->cur_size; i++)
  {
      hash += (unsigned char)(stack->data[i]);
      hash += (hash << 10);
      hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  /*for(unsigned i = 0; i < stack->cur_size; i++)
  {
    hash += (stack->cur_size - i)*stack->data[i];
  }

  hash += 69*(stack->eagle1%420);
  hash += 420*(stack->eagle2%69);
  hash += 89*(stack->size/30);
  hash += 17*(stack->cur_size);*/

  return hash;
}
