#include "stack.h"

int main()
{
  Stack my_stack;
  init(&my_stack);
  if(!is_OK(&my_stack))
  {
    printf("Stack is not OK\n");
    exit(1);
  }

  invite();

  char condition = 1;
  while(condition)
  {
    condition = what_to_do(&my_stack);
    if(!is_OK(&my_stack))
    {
      printf("Stack is not OK\n");
      exit(1);
    }
  }

  return 0;
}
