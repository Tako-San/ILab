#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


void answer(char * str);
char * my_strtok(char * ptr);
void skip_spaces(char ** cur_ptr_ptr);
void skip_non_spaces(char ** cur_ptr_ptr);

int main()
{
  char text[] = "Farid MIPT Farid hey!";
  answer(text);
  return 0;
}

void answer(char * str)
{
  char * p = my_strtok(str);
  if(!p)
    printf("NULL_PTR\n");
  else if(strcmp(p, "Intel") == 0)
    printf("%d\n", 1);

  p = my_strtok(NULL);
  if(!p)
    printf("NULL_PTR\n");
  else if(strcmp(p, "MIPT") == 0)
    printf("%d\n", 2);

  p = my_strtok(str);
  if(!p)
    printf("NULL_PTR\n");
  else if(strcmp(p, "Farid") == 0)
    printf("%d\n", 3);
}

char * my_strtok(char * ptr)
{
  static char * cur_ptr = NULL;

  if(ptr)
    cur_ptr = ptr;
  if(!cur_ptr)
    return NULL;

  char * start_ptr = cur_ptr;

  skip_spaces(&cur_ptr);
  skip_non_spaces(&cur_ptr);

  assert(cur_ptr);
  *cur_ptr = '\0';
  cur_ptr++;

  return start_ptr;
}

void skip_spaces(char ** cur_ptr_ptr)
{
  assert(cur_ptr_ptr);
  for(; **cur_ptr_ptr == ' '; (*cur_ptr_ptr)++);
}

void skip_non_spaces(char ** cur_ptr_ptr)
{
  assert(cur_ptr_ptr);
  for(; **cur_ptr_ptr != ' '; (*cur_ptr_ptr)++)
  {
    if(**cur_ptr_ptr == '\0')
      break;
  }
}
