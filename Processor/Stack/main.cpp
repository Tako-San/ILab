#include "stack.h"
#include "interface.h"

int main()
{
    Stack my_stack = {};

    if(!stack_init(&my_stack))
        return 0;

    if(!stack_is_OK(&my_stack, __LINE__, __FILE__, __PRETTY_FUNCTION__))
        return 0;

    invite();

    while(my_stack.err_code == STACK_NICE)
        what_to_do(&my_stack);
    return 0;
}