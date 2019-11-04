#include "stack.h"

void init(Stack * new_stack)
{
  new_stack->stack = (int *)calloc(STARTSIZE, sizeof(int));
  if(new_stack->stack == NULL)
  {
    printf("Memory allocation error.\n");
    exit(1);
  }
  new_stack->size = STARTSIZE;
  new_stack->cur_size = 0;
}

void destroy(Stack * old_stack)
{
  free(old_stack->stack);
  old_stack->size = DEADSTACK;
  old_stack->cur_size = DEADSTACK;
}

void invite()
{
  printf("What u wanna do, dude? You can:\n\n");
  printf("1 - add number to stack\n");
  printf("2 - see last element\n");
  printf("3 - look at last elemet last time and delete\n");
  printf("4 - exit\n\n");
}

void push(Stack * stack)
{
  if(stack->cur_size >= stack->size)
  {
    printf("Stack overflow\n");
  }
  else
  {
    stack->cur_size++;
    printf("Enter next stack element: ");
    scanf("%d", &(stack->stack[stack->cur_size - 1]));
    printf("\n");
  }
}

int peek(Stack * stack)
{
  ui i = stack->cur_size - 1;
  int rez = stack->stack[i];
  return rez;
}

int pop(Stack * stack)
{
  ui i = stack->cur_size - 1;
  int rez = stack->stack[i];
  stack->cur_size--;
  return rez;
}

void split()
{
  printf("___________________________\n\n");
}

int what_to_do(Stack * stack)
{
  int user_wish;
  int condition = 1;
  int last_elem;

  printf("Your choose is number: ");
  scanf("%d", &user_wish);
  printf("\n");

  switch(user_wish)
  {
    case 1: push(stack);
            condition = 1;
            split();
            break;
    case 2: if(stack->cur_size == 0)
              printf("Your stack is empty\n");
            else
            {
              last_elem = peek(stack);
              printf("Last elem = %d\n", last_elem);
            }
            condition = 1;
            split();
            break;
    case 3: if(stack->cur_size == 0)
              printf("Your stack is empty\n");
            else
            {
              last_elem = pop(stack);
              printf("Last elem = %d. And it was deleted\n", last_elem);
            }
            condition = 1;
            split();
            break;
    case 4: destroy(stack);
            printf("Bye ;(\n\n");
            condition = 0;
            break;
    default:  printf("Wrong number, man. Try again\n");
              condition = 1;
              split();
              break;
  }

  return condition;
}
