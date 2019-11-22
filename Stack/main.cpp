#include "stack.h"
#include "interface.h"

/*class Tortue
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
};*/



int main()
{
  /*Tortue trt;
  trt.StackFuck();
  if (!is_OK(&trt.victim))
    printf("ERROR\n");
  printf("%llu\n%llu\n", trt.victim.eagle1, trt.victim.eagle2);
#if 0*/

  STK_ERR err_code = STACK_NICE;
  Stack my_stack;

  init(&my_stack, &err_code);
  if(!is_OK(&my_stack, &err_code))
  {
    //printf("Stack is not OK\n");
    //exit(1);
    return 0;
  }

  invite();

  //char condition = 1;
  while(err_code == STACK_NICE)
  {
    /*if(!is_OK(&my_stack, &err_code))
    {
      printf("Stack is not OK\n");
      exit(1);
    }*/
    //condition = what_to_do(&my_stack, &err_code);
    //is_OK(&my_stack, &err_code);
    what_to_do(&my_stack, &err_code);
  }
//#endif
  return 0;
}
