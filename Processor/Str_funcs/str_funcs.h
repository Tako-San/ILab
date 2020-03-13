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

#define LOCATION __LINE__, __FILE__, __PRETTY_FUNCTION__

typedef struct
{
    int len;
    char * start;
}Line;

enum STR_ERR
{
    IS_OK                          = 0,
    MEM_ALLOC_ERR                  = 1,

    PRINT_STR_NUM_BELOW_ZERO_ERR   = 2,
    PRINT_FILE_OPENING_ERR         = 3,

    READ_FILE_OPENING_ERR          = 4,

    FILE_TO_BUF_FILE_OPENING_ERR   = 5,

    FUNC_ARG_NULL_PTR_ERR          = 6,

    FSEEK_ERR                      = 7,
};

char *   file_to_buf(int * txtlen, int * err_code, const char * filename);
int      file_length(FILE * f, int * err_code);
Line *   ptr_maker(char * txt, int * strings, int * err_code);

int      line_compare(const void * str1, const void * str2);
int      back_line_compare(const void * str1, const void * str2);

void     lines_copy(Line* dst, Line* src, int size, int * err_code);
void     line_swap(Line * line1, Line * line2);
void     print_text(Line * str_info, int strings, int * err_code, char * filename);

int      is_OK(int * err_code, int line, const char * filename, const char * funcname);

#endif
