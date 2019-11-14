#include "stack.h"

class Tortue
{
public:
  int exec1;
  Stack victim;
  int exec2;

  Tortue( void ) : exec1(0),
                   exec2(0)
  {
    init(&victim);
  }

  void StackFuck( void )
  {
    *((can_type *)(&exec1 + 2)) = 228;
    *((can_type *)(&exec2 - 2)) = 0;
  }

  ~Tortue( void )
  {
    destroy(&victim);
  }
};



int main()
{
  /*Tortue trt;
  trt.StackFuck();
  if (!is_OK(&trt.victim))
    printf("ERROR\n");
  printf("%llu\n%llu\n", trt.victim.eagle1, trt.victim.eagle2);
#if 0*/
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
    if(!is_OK(&my_stack))
    {
      printf("Stack is not OK\n");
      exit(1);
    }
    condition = what_to_do(&my_stack);
  }
//#endif
  return 0;
}
