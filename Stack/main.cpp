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
    stack_init(&victim);
  }

  void StackFuck( void )
  {
    *((can_type *)(&exec1 + 2)) = 228;
    *((can_type *)(&exec2 - 2)) = 0;
  }

  ~Tortue( void )
  {
    stack_destroy(&victim);
  }
};*/



int main()
{
  /*Torture trt;
  trt.StackFuck();
  if (!stack_is_OK(&trt.victim))
    printf("ERROR\n");
  printf("%llu\n%llu\n", trt.victim.eagle1, trt.victim.eagle2);
#if 0*/

  //STK_ERR err_code = STACK_NICE;
  Stack my_stack = {};

  if(!stack_init(&my_stack))
    return 0;

  if(!stack_is_OK(&my_stack))
    return 0;

  invite();

  while(my_stack.err_code == STACK_NICE)
    what_to_do(&my_stack);
//#endif
  return 0;
}
