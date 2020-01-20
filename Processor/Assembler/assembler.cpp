//
// Created by farid on 28.11.2019.
//

#include "assembler.h"

char * file_to_buf(const char * filename, /*some_type err_code*/)
{
    FILE * f;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        printf("File reading failure.\n");
        //err_code = ...;
    }

    int flen = file_length(f);

    char * text = (char *)calloc(flen + 1, sizeof(text[0]));
    if(!text)
    {
        printf("Allocation failure\n");
        //err_code = ...;
    }

    flen = fread(text, sizeof(text[0]), flen, f);

    text[flen] = '\0';

    fclose(f);

    *txtlen = flen;
    return text;
}

/*void cut_buf(char * buf)
{
    while(strtok(buf, " \t\n\r"));
}*/

Lexem * sint_an(char * buf)
{
    char * temp = nullptr;
    while(temp = strtok(buf, DELIM))
    {

    }
}

sem_an
{
    SMOTRIM CHO KAK BOLEE PODROBNO
}

bin_to_file
{
    VIVODIM BINARNIY COD V FILE
}


int str_compare(const void * str1, const void * str2)
{
    Line line1 = *(Line*)str1;
    Line line2 = *(Line*)str2;

    char* l1 = line1.start;
    char* l2 = line2.start;

    int p = 0, q = 0;
    while((l1[p] != '\0') && (l2[q] != '\0'))
    {
        while((!isalpha(l1[p]))&&(l1[p] != '\0'))
            p++;
        while((!isalpha(l2[q]))&&(l2[q] != '\0'))
            q++;

        if(l1[p] == l2[q])
        {
            p++;
            q++;
        }
        else
            break;
    }

    return (tolower(l1[p]) - tolower(l2[q]));

}