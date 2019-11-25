#include "interface.h"


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
    case 0:   stack_destroy(stack);
              printf("Bye ;(\n\n");
              break;

    case 1:   my_type new_elem;
              printf("Enter next stack element: ");
              std::cin >> new_elem;
              stack_push(stack, new_elem);
              printf("\n");
              break;

    case 2:   my_type last_elem1;
              last_elem1 = stack_peek(stack);

              if(stack->err_code == STACK_UNDERFLOW)
              {
                printf("Your stack is empty\n");
                stack->err_code = STACK_NICE;
                stack->hash = stack_hash_hash(stack);
              }
              else
              {
                printf("\nLast elem = ");
                std::cout << last_elem1;
                printf("\n");
              }
              break;

    case 3:   my_type last_elem2;
              last_elem2 = stack_pop(stack);

              if(stack->err_code == STACK_UNDERFLOW)
              {
                printf("Your stack is empty\n");
                stack->err_code = STACK_NICE;
                //stack->hash = stack_hash_hash(stack);
              }
              else
              {
                printf("\nLast elem = ");
                std::cout << last_elem2;
                printf("\nIt was deleted\n");
              }

              break;

    case 4:   stack_dump(stack);
              break;

    default:  printf("%d is wrong number, yo man. Try again\n", user_wish);
              break;
  }

  return 0;
}

void invite()
{
  printf("\nWhat u wanna do, dude? You can:\n\n");
  split();
  printf("            0 - exit\n");
  printf("            1 - add number to stack\n");
  printf("            2 - see last element\n");
  printf("            3 - look at last elemet last time and delete\n");
  printf("            4 - print stack data\n\n");
}

void split()
{
  printf("_______________________________________________________________________________\n\n");
}