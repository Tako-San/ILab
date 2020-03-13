//
// Created by farid on 01.03.2020.
//

#define DATA_SIZE sizeof(int)

UNIV_CMD(PUSH, 1, len,
{
    int num_push = 0;

    if(sscanf(tok_prgrm[cur_num].start + pos, "%d", &num_push) == 1)
    {
        *((int *)buf_cp) = num_push;
        buf_cp = (char *)(++buf_cp);
        buf_out_len += DATA_SIZE;
    }
    else
    {
        printf("No argument for push, bro.");
        return false;
    }
},
{},
{})

UNIV_CMD(POP, 2, len,
{},
{},
{})

UNIV_CMD(ADD, 3, len,
{},
{},
{})

UNIV_CMD(SUB, 4, len,
{},
{},
{})

UNIV_CMD(MUL, 5, len,
{},
{},
{})

UNIV_CMD(DIV, 6, len,
{},
{},
{})

UNIV_CMD(OUT, 7, len,
{},
{},
{})

UNIV_CMD(END, -1, len,
{
    return true;
},
{},
{})

/*UNIV_CMD(, , ,
{},
{},
{})*/