#include "interface.h"

/**
 * \Allows user choose what to do.
 * \param [in] stack  Pointer to stack structure.
 * \return zero
*/
int what_to_do(Stack * stack)
{
  int user_wish = 0;

  split();
  printf("0 - exit    1 - stack_push    2 - stack_peek    3 - stack_pop    4 - print data\n");
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
    case 0:   stack->destroy();
              printf("Bye ;(\n\n");
              break;

    case 1:   my_type new_elem;
              printf("Enter next stack element: ");
              std::cin >> new_elem;
              stack->push(new_elem);
              printf("\n");
              break;

    case 2:   my_type last_elem1;
              last_elem1 = stack->peek();

              if(stack->err_code == STACK_UNDERFLOW)
              {
                printf("Your stack is empty\n");
                stack->err_code = STACK_NICE;
                stack->hash_recalc();
              }
              else
              {
                printf("\nLast elem = ");
                std::cout << last_elem1;
                printf("\n");
              }
              break;

    case 3:   my_type last_elem2;
              last_elem2 = stack->pop();

              if(stack->err_code == STACK_UNDERFLOW)
              {
                printf("Your stack is empty\n");
                stack->err_code = STACK_NICE;
                stack->hash_recalc();
              }
              else
              {
                printf("\nLast elem = ");
                std::cout << last_elem2;
                printf("\nIt was deleted\n");
              }

              break;

    case 4:   stack->data_print();
              //stack->dump(__LINE__, __FILE__, __PRETTY_FUNCTION__);
              break;

    default:  printf("%d is wrong number, yo man. Try again\n", user_wish);
              break;
  }

  return 0;
}/* End of 'what_to_do' function */


/**
 * \Print invite.
 * \return none
*/
void invite()
{
  printf("\nWhat u wanna do, dude? You can:\n\n");
  split();
  printf("            0 - exit\n");
  printf("            1 - add number to stack\n");
  printf("            2 - see last element\n");
  printf("            3 - look at last elemet last time and delete\n");
  printf("            4 - print stack data\n\n");
}/* End of 'invite' function */

/**
 * \Print line
 * \return none
*/
void split()
{
  printf("_______________________________________________________________________________\n\n");
}/* End of 'split' function */
