//
// Created by farid on 28.11.2019.
//

#include "assembler.h"

int main()
{
    /*Lexema prog;
    buffering(&prog);
    buf_to_file()

    free(prog.fer);
    free(prog.word);
    free(buf_out);*/

    RAM mem;
    int str_err = IS_OK;
    mem.buf = file_to_buf(&mem.buf_len, &str_err, "prog.txt");

    Lex prog;
    prog.words = ptr_maker(mem.buf, &prog.num, &str_err);

    assembly();


    free(mem.buf);
    free(prog.words);

    return 0;
}