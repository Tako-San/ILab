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

typedef struct
{
    char flag;
    int64_t integer;
    /*union
    {
        double floating;
        int64_t integer;
    };*/
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
    };*/
}Command;

const char * DELIM = " \t\n\r";

#endif //PROCESSOR_ASSEMBLER_H
