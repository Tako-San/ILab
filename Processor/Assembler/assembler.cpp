//
// Created by farid on 28.11.2019.
//

#include "assembler.h"

bool Asmr::assembly(const char file_in[], const char file_out[])
{
    txt_get(file_in);
    asmr_parser();
    buf_to_file(buf_out, file_out);

    /*куча всяких free*/
}

void Asmr::asmr_parser(/*const char file_in[]*/)
{
    buf_out = (char *)calloc(tok_num, sizeof(char));

    for(int cur_num = 0; cur_num < tok_num; cur_num++)
    {
        char cur_wrd[LONGEST_WRD] = {};     //ЗАДЕФАЙНИТЬ ЛОНГЕСТ ВОРД
        sscanf(tok_prgrm[cur_num], "%s", cur_wrd)

    #define UNIV_CMD(/*записать тут всякие аргументы*/)   \
        else if(!line_compare(cur_wrd, comm_name))        \
        {                                                 \
            /*тут чета делаем*/                           \
        }                                                 \

        if(/*какое-то первое условие*/)
        {
            /*какое-то действие*/
        }

        #include "../command.h"

        else
        {
            /*Чел, синтаксическая ошибка*/
        }

    #undef MULTI_CMD

    }
}

bool Asmr::buf_to_file(int * buf, char * filename)
{
    FILE * out = fopen(filename, "wb");

    fwrite(buf, sizeof(int), prog->lex_num, out)

    fclose(out);
    return true;
}

void Asmr::txt_get(const char file_in[])
{
#define ERR_CHECK()         \
if(err_code != IS_OK)       \
    return;                 \

    int err_code = IS_OK;

    int txtlen = 0;
    prgrm = file_to_buf(&txtlen, &err_code, file_in);
    ERR_CHECK()

    tok_prgrm = ptr_maker(prgrm, &tok_num, &err_code); //токенизированная прога, ток нум - кол-во слов
    ERR_CHECK()

#undef ERR_CHECK
}

