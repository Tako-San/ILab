//
// Created by farid on 28.11.2019.
//

#ifndef PROCESSOR_ASSEMBLER_H
#define PROCESSOR_ASSEMBLER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cassert>
#include <cstdint>

#include "../Str_funcs/str_funcs.h"

/*typedef struct
{
    char flag;
    int64_t integer;
    union
    {
        double floating;
        int64_t integer;
    };
}Lexem;

typedef struct
{
    char CMD_flag;
    uint16_t CMD_CODE;
    char arg_flag;
    int64_t integer;
    /*union
    {
        double floating;
        int64_t integer;
    };
}Command;*/

typedef struct
{
    Line * words;
    int num;
}Lex;

typedef struct
{
    char * buf;
    int buf_len;
}RAM;

enum
{
    ASMR_PUSH = 1,
    ASMR_POP
}Commands;

const char * DELIM = " \t\n\r";

#define LONGEST_NAME 15

#endif //PROCESSOR_ASSEMBLER_H
