#include "stack.h"

int main()
{
  Stack my_stack;
  init(&my_stack);

  invite();

  int condition = 1;
  while(condition)
  {
    condition = what_to_do(&my_stack);
  }

  return 0;
}
