//
// Created by farid on 28.11.2019.
//

#include "assembler.h"

Asmr::Asmr()
{
    prgrm = buf_out = nullptr;
    tok_prgrm = nullptr;
    tok_num = buf_out_len = 0;

    printf("asmr born\n");
}

Asmr::~Asmr()
{
    if(prgrm != nullptr)
        free(prgrm);
    if(buf_out != nullptr)
        free(buf_out);
    if(tok_prgrm != nullptr)
        free(tok_prgrm);
    printf("asmr dead\n");
}

bool Asmr::assembly(const char file_in[], const char file_out[])
{
    printf("assembly func\n");

    txt_get(file_in);
    asmr_parser(file_in);
    buf_to_file(file_out);

    /*куча всяких free*/
    return true;
}

bool Asmr::asmr_parser(const char file_in[])
{
    buf_out = (char *)calloc(tok_num, sizeof(char));
    char * buf_cp = buf_out;

    for(int cur_num = 0; cur_num < tok_num; cur_num++) {
        char cur_wrd[LONGEST_WRD] = {};
        int pos = 0;

        sscanf(tok_prgrm[cur_num].start, "%s %n", cur_wrd, &pos);

#define UNIV_CMD(cmd_name, cmd_num, len, asmr, cpu, disasmr)        \
        else if(line_compare(cur_wrd, #cmd_name) == 0)    \
        {                                                 \
            *buf_cp = cmd_num;                            \
            buf_cp++;                                     \
            buf_out_len++;                                \
            asmr;                                         \
        }                                                 \

        if (false) {
            /*какое-то действие*/
        }

        #include "../commands.h"

        else {
            printf("Syntax error, man. You should be more accurate.");
            return false;
        }
    }
#undef MULTI_CMD
}

bool Asmr::buf_to_file(const char file_out[]) // Тут какая-то хрень. Разобраться
{
    FILE * out = fopen(file_out, "wb");

    if(out == nullptr)
        return false;

    fwrite(buf_out, sizeof(char), buf_out_len, out);

    fclose(out);
    return true;
}

void Asmr::txt_get(const char file_in[]) // Сделать функцию булевской после того как добавлю проверки
{
    printf("txt_get func\n");

#define ERR_CHECK()         \
if(err_code != IS_OK)       \
    return;                 \

    int err_code = IS_OK;
    prgrm = file_to_buf(&prgrm_len, &err_code, file_in); // txtlen нам возможно не пригодится
    printf("%d\n", err_code);
    ERR_CHECK()

    printf("err_check1\n");

    tok_prgrm = ptr_maker(prgrm, &tok_num, &err_code); //токенизированная прога, ток нум - кол-во слов
    ERR_CHECK()
    printf("err check2\n");

#undef ERR_CHECK
}

