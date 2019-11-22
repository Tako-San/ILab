#include "interface.h"


int what_to_do(Stack * stack, STK_ERR * err_code)
{
  int user_wish;
  //int condition = 1;
  my_type last_elem;

  split();
  printf("0 - exit    1 - push    2 - peek    3 - pop    4 - print data\n");
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
    case 0: destroy(stack, err_code);
            printf("Bye ;(\n\n");
            //condition = 0;
            break;
    case 1: push(stack, err_code);
            //condition = 1;
            break;
    case 2: if(stack->cur_size == 0)
              printf("Your stack is empty\n");
            else
            {
              last_elem = peek(stack, err_code);
              printf("\nLast elem = ");
              std::cout << last_elem;
              printf("\n");
            }
            //condition = 1;
            break;
    case 3: if(stack->cur_size == 0)
              printf("\nYour stack is empty\n");
            else
            {
              last_elem = pop(stack, err_code);
              printf("\nLast elem = ");
              std::cout << last_elem;
              printf("\nIt was deleted\n");
            }
            //condition = 1;
            break;
    case 4: //data_print(stack);
            dumb(stack, err_code);
            break;
    default:  printf("Wrong number, man. Try again\n");
              //condition = 1;
              break;
  }

  return 0;
}

void invite()
{
  printf("What u wanna do, dude? You can:\n\n");
  split();
  printf("      0 - exit\n");
  printf("      1 - add number to stack\n");
  printf("      2 - see last element\n");
  printf("      3 - look at last elemet last time and delete\n");
  printf("      4 - print stack data\n\n");
}

void split()
{
  printf("______________________________________________________________\n\n");
}
