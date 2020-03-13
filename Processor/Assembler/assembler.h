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

#define LONGEST_WRD 15

class Asmr
{
private:

    char * prgrm, * buf_out;
    Line * tok_prgrm;
    int    prgrm_len, tok_num, buf_out_len;

public:

    Asmr();
    bool   assembly(const char file_in[], const char file_out[]);
    ~Asmr();

private:

    bool   asmr_parser(const char file_in[]);
    void   txt_get(const char file_in[]);
    bool   buf_to_file(const char file_out[]);

};

#endif //PROCESSOR_ASSEMBLER_H
