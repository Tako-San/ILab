//
// Created by farid on 21.01.2020.
//

#ifndef PROCESSOR_STR_FUNCS_H
#define PROCESSOR_STR_FUNCS_H

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <cstring>


typedef struct
{
    int len;
    char * start;
}Line;

char * file_to_buf(int * txtlen, char * filename);
int file_length(FILE * f);
Line * ptr_maker(char * txt, int * strings);

int line_compare(const void * str1, const void * str2);
int back_line_compare(const void * str1, const void * str2);

void lines_copy(Line* dst, Line* src, int size);
void line_swap(Line * line1, Line * line2);
void print_text(Line * str_info, int strings);


#endif //PROCESSOR_STR_FUNCS_H
