#include "txtsort.h"

char * file_to_buf(int * txtlen)
{
  FILE * f;
  if ((f = fopen("ONEGIN.txt", "rb")) == NULL)
  {
    printf("File reading failure.\n");
    exit(1);
  }

  int flen = file_length(f);

  char * text = (char *)calloc(flen + 1, sizeof(text[0]));
  if(!text)
  {
    printf("Allocation failure\n");
    exit(1);
  }

  flen = fread(text, sizeof(text[0]), flen, f);

  text[flen] = '\0';

  fclose(f);

  *txtlen = flen;
  return text;
}


int file_length(FILE * f)
{
  fseek(f, 0, SEEK_END);
  int len = ftell(f);
  if(len == -1L)
  {
    printf("fseek error\n");
    exit(1);
  }
  rewind(f);
  return len;
}


Line * ptr_maker(char * txt, int * strings)
{

  int StrCount = 0;

  for(int i = 0; txt[i] != '\0'; i++)
  {
    if(txt[i] == '\n')
      StrCount++;
  }
  StrCount++;
  *strings = StrCount;

  Line * str_info = (Line *)calloc(StrCount, sizeof(Line));
  if(!str_info)
  {
    printf("Allocation failure\n");
    exit(1);
  }

  str_info[0].start = txt;

  int i = 0;
  int string = 1;

  for(; txt[i] != '\0'; i++)
  {
    if(txt[i] == '\n')
    {
      txt[i] = '\0';
      str_info[string].start = &(txt[i+1]);
      str_info[string - 1].len = str_info[string].start - str_info[string - 1].start;
      string++;
    }
  }

  str_info[string - 1].len = &(txt[i]) - str_info[string].start;

  return str_info;
}


int line_compare(const void * str1, const void * str2)
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


int back_line_compare(const void * str1, const void * str2)
{
  Line line1 = *(Line*)str1;
  Line line2 = *(Line*)str2;

  char* l1 = line1.start;
  char* l2 = line2.start;

  int p = line1.len - 1;
  int q = line2.len - 1;

  while((p >= 0) && (q >= 0))
  {
    while((!isalpha(l1[p]))&&(p >= 0))
      p--;
    while((!isalpha(l2[q]))&&(q >= 0))
      q--;

    if(l1[p] == l2[q])
    {
      p--;
      q--;
    }
    else
      break;
  }

  if(l1[p] == l2[q])
    return (p - q);
  else
    return (tolower(l1[p]) - tolower(l2[q]));
}


void line_swap(Line * line1, Line * line2)
{
  Line temp = *(line1);
  *(line1) = *(line2);
  *(line2) = temp;
}


void print_text(Line * str_info, int strings)
{
  FILE * f;
  if ((f = fopen("Out.txt", "ab")) == NULL)
  {
    printf("File opening failure.\n");
    exit(1);
  }

  for (int i = 0; i < strings; i++)
  {
    /*for(int p = 0; *(str_info[i].start+p) != '\0'; p++)
      fputc(*(str_info[i].start+p), f);
    fputc('\n', f);*/
    fputs(str_info[i].start, f);
  }
  fclose(f);
}

void lines_copy(Line* dst, Line* src, int size)
{
  for(int i = 0; i < size; i++)
    dst[i] = src[i];
}
/*void print_buf(char * txt, int strings)
{
  FILE * f = fopen("Out.txt", "ab");
  for (int i = 0; i < strings; i++)
  {
    for(int p = 0; txt[i] != '\0'; p++)
      fputc(txt[i], f);
    fputc('\n', f);
  }
  fclose(f);
}*/
