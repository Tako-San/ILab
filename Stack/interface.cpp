#include "interface.h"


int what_to_do(Stack * stack, STK_ERR * err_code)
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
    case 0:   stack_destroy(stack, err_code);
              printf("Bye ;(\n\n");
              break;

    case 1:   my_type new_elem;
              printf("Enter next stack element: ");
              std::cin >> new_elem;
              stack_push(stack, err_code, new_elem);
              printf("\n");
              break;

    case 2:   my_type last_elem1;
              last_elem1 = stack_peek(stack, err_code);
              if(*err_code == STACK_UNDERFLOW)
              {
                printf("Your stack is empty\n");
                *err_code = STACK_NICE;
              }
              else
              {
                printf("\nLast elem = ");
                std::cout << last_elem1;
                printf("\n");
              }
              break;

    case 3:   my_type last_elem2;
              last_elem2 = stack_pop(stack, err_code);
              if(*err_code == STACK_UNDERFLOW)
              {
                printf("Your stack is empty\n");
                *err_code = STACK_NICE;
              }
              else
              {
                printf("\nLast elem = ");
                std::cout << last_elem2;
                printf("\nIt was deleted\n");
              }
              break;

    case 4:   stack_dump(stack, err_code);
              break;

    default:  printf("%d is wrong number, yo man. Try again\n", user_wish);
              break;
  }
  /*if(stack->cur_size == 0)
  printf("Your stack is empty\n");
  else
  {
    my_type last_elem = stack_peek(stack, err_code);
    printf("\nLast elem = ");
    std::cout << last_elem;
    printf("\n");
  }*/

  /*if(stack->cur_size == 0)
  printf("\nYour stack is empty\n");
  else
  {
    my_type last_elem = stack_pop(stack, err_code);
    printf("\nLast elem = ");
    std::cout << last_elem;
    printf("\nIt was deleted\n");
  }*/

  //stack_data_print(stack);

  return 0;
}

void invite()
{
  printf("What u wanna do, dude? You can:\n\n");
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
