#ifndef __ONEGIN_H__
#define __ONEGIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define LOCATION __LINE__, __FILE__, __PRETTY_FUNCTION__

typedef struct
{
  int len;
  char * start;
}Line;

enum
{
  IS_OK                          = 0,
  MEM_ALLOC_ERR                  = 1,

  MAKER_TXT_NULL_PTR_ERR         = 2,
  STRINGS_NUM_NULL_PTR_ERR       = 3,

  PRINT_LINE_BUFF_NULL_PTR_ERR   = 4,
  PRINT_STR_NUM_BELOW_ZERO_ERR   = 5,
  PRINT_FILE_OPENING_ERR         = 6,

  READ_FILE_OPENING_ERR          = 7,

  FILE_TO_BUF_FILE_OPENING_ERR   = 8
};

char * file_to_buf(int * txtlen, int * err_code, const char * filename);
int    file_length(FILE * f);
Line * ptr_maker(char * txt, int * strings, int * err_code);

int line_compare(const void * str1, const void * str2);
int back_line_compare(const void * str1, const void * str2);

void lines_copy(Line* dst, Line* src, int size, int * err_code);
void line_swap(Line * line1, Line * line2);
void print_text(Line * str_info, int strings, int * err_code);
//void print_buf(char * txt, int strings);

int is_OK(int * err_code, int line, const char * filename, const char * funcname);

#endif
