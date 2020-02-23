//
// Created by farid on 28.11.2019.
//

#include "assembler.h"
#include "../Str_funcs/str_funcs.h"

/*void (Lex * prog)
{
    /*prog->fer = file_to_buf(prof->fer.len, "Prog.txt");
    prog->words = ptr_maker(&(prog->fer.mem), &(prog->lex_num));

}*/

char * assembly()
{
    int pos = 0;
    buf_out = (int *)calloc(prog->lex_num, sizeof(int));
    int * bptr = buf_out;

    for(int cur_word_num = 0; cur_word_num < prog->lex_num; cur_word_num++)
    {
        char cur_word[LONGEST_NAME] = {};
        if(sscanf(prog->words[cur_word_num], "%s %d", cur_word, &pos) != 1)
            return false;
        if(!line_compare(cur_word, "end"))
        {
            *bptr++ = ASM_END;
            break;
        }
        else if(!line_compare(cur_word, "push"))
        {
            int push_num = 0;
            cur_word_num++;
            if(sscanf(prog->words[cur_word_num], " %d", &push_num) != 1)
            {
                *bptr++ = ASM_PUSH;
                *bptr++ = push_num;
            }
            else
            {
                printf("Error: \"push\" without arg");
            }
        }
        else if(!line_compare(cur_word, "add")
        {
            *bptr++ = ASM_ADD;
        }
        else
        {
            printf("Unknown command.");
            return false;
        }
    }
    return true;
}

bool buf_to_file(int * buf, char * filename)
{
    FILE * out = fopen(filename, "wb");

    fwrite(buf, sizeof(int), prog->lex_num, out)

    fclose(out);
    return true;
}