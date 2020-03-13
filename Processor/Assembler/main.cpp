//
// Created by farid on 28.11.2019.
//

#include "assembler.h"

int main()
{
    Asmr asmr;

    printf("going to assembly\n");

    asmr.assembly("program.txt", "machine_code.f");
    return 0;
}