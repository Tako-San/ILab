#include "stack.h"


void init(Stack * new_stack)
{
  //new_stack->data = (my_type *)((can_type *)calloc(STARTSIZE*sizeof(my_type)+2*sizeof(can_type), 1) + 1);
  new_stack->data = (my_type *)calloc(STARTSIZE, sizeof(my_type));
  if(new_stack->data == NULL)
  {
    printf("Memory allocation error\n");
    exit(1);
  }
  new_stack->size = STARTSIZE;
  new_stack->cur_size = 0;

  new_stack->eagle1 = eagle1_val;
  new_stack->eagle2 = eagle2_val;

  /*new_stack->can1 = (can_type *)(new_stack->data) - 1;
  new_stack->can2 = (can_type *)(new_stack->data + STARTSIZE) + 1;

  *(new_stack->can1) = can1_val;
  *(new_stack->can2) = can2_val;*/
}

void destroy(Stack * old_stack)
{
  //free((can_type *)old_stack->data - 1);
  free(old_stack->data);
  old_stack->size = DEADSTACK;
  old_stack->cur_size = DEADSTACK;
}



void invite()
{
  printf("What u wanna do, dude? You can:\n\n");
  printf("0 - exit\n");
  printf("1 - add number to stack\n");
  printf("2 - see last element\n");
  printf("3 - look at last elemet last time and delete\n\n");
}

void split()
{
  printf("___________________________\n\n");
}

int what_to_do(Stack * stack)
{
  int user_wish;
  int condition = 1;
  my_type last_elem;

  printf("Your choose is number: ");
  scanf("%d", &user_wish);
  printf("\n");

  switch(user_wish)
  {
    case 0: destroy(stack);
            printf("Bye ;(\n\n");
            condition = 0;
            break;
    case 1: push(stack);
            condition = 1;
            split();
            break;
    case 2: if(stack->cur_size == 0)
              printf("Your stack is empty\n");
            else
            {
              last_elem = peek(stack);
              std::cout << "Last elem = " << last_elem << "\n";
            }
            condition = 1;
            split();
            break;
    case 3: if(stack->cur_size == 0)
              printf("Your stack is empty\n");
            else
            {
              last_elem = pop(stack);
              //printf("Last elem = %d. And it was deleted\n", last_elem);
              std::cout << "Last elem = " << last_elem << "\nIt was deleted\n";
            }
            condition = 1;
            split();
            break;
    default:  printf("Wrong number, man. Try again\n");
              condition = 1;
              split();
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
  printf("\n");
}

my_type peek(Stack * stack)
{
  assert(is_OK(stack));
  size_type i = stack->cur_size - 1;
  my_type rez = stack->data[i];
  return rez;
}

my_type pop(Stack * stack)
{
  assert(is_OK(stack));
  size_type i = stack->cur_size - 1;
  my_type rez = stack->data[i];
  stack->cur_size--;
  return rez;
}

void stack_resize(Stack * stack)
{
  assert(is_OK(stack));
  stack->size *= 2;
  /*stack->can1 = (can_type *)realloc((can_type *)stack->data - 1, stack->size*sizeof(my_type) + 2*sizeof(can_type));
  stack->data = (my_type *)(stack->can1 + 1);
  stack->can2 = (can_type *)(stack->data + stack->size - 1);
  if(!stack->data)
  {
    printf("REallocation error\n");
    exit(1);
  }
  //stack->can2 = (can_type *)(stack->data + stack->size)+1;*/
  my_type * temp = (my_type *)realloc(stack->data, stack->size*sizeof(my_type));
  if(!temp)
  {
    printf("REallocation error\n");
    exit(1);
  }
  else
  {
    stack->data = temp;
  }
}


int is_OK(Stack * stack)
{
  if(stack->eagle1 != eagle1_val)
  {
    printf("\n\nEAGLE1 CHANGED\n\n");
    fury();
    exit(1);
  }
  else if(stack->eagle2 != eagle2_val)
  {
    printf("\n\nEAGLE2 CHANGED\n\n");
    fury();
    exit(1);
  }
  else
    return 1;
}

void fury()
{
  for(int i = 0; i < 4; i++)
    split();
  printf("YOU WANNA FUCK MY EAGLES? FUCK YOU\n");
  for(int i = 0; i < 4; i++)
    split();
}
