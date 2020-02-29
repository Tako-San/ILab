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

  Stack my;

  /*if(!my.init())
    return 0;*/

  if(!my.is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return 0;

  invite();

  while(my.err_code_getter() == STACK_NICE)
    what_to_do(&my);
//#endif
  return 0;
}
