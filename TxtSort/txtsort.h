#ifndef __ONEGIN_H__
#define __ONEGIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>


typedef struct
{
  int len;
  char * start;
} Line;

char * file_to_buf(int * txtlen);
int file_length(FILE * f);
Line * ptr_maker(char * txt, int * strings);
//void BubbleSort(Line * str_info, int strs);
int line_compare(const void * str1, const void * str2);
void line_swap(Line * line1, Line * line2);
void print_text(Line * str_info, int strings);

#endif
