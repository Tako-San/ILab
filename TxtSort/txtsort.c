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
    {
      StrCount++;
    }
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
    //printf("Making pointers txt[%d]\n", i);
    if(txt[i] == '\n')
    {
      //printf("Here we need ptr: txt[%d]\n", i);
      txt[i] = '\0';
      str_info[string].start = &(txt[i+1]);
      str_info[string - 1].len = str_info[string].start - str_info[string - 1].start;
      string++;
      //printf("strings: %d\n", string);
    }
  }

  /*for(; txt[i] != '\0'; i++)
  {
    if(txt[i] == '\n')
    {
      while(isspace(txt[i]))
        i++;
      //printf("Here we need ptr: txt[%d]\n", i);
      txt[i] = '\0';
      str_info[string].start = &(txt[i+1]);
      str_info[string - 1].len = str_info[string].start - str_info[string - 1].start;
      string++;
      printf("strings: %d\n", string);
    }
  }*/

  str_info[string].len = &(txt[i]) - str_info[string].start;
  //printf("END OF ptr_maker\n");
  return str_info;
}


int line_compare(const void * str1, const void * str2)
{
  int p = 0, q = 0;

  Line line1 = *(Line*)str1;
  Line line2 = *(Line*)str2;

  while((*(line1.start + p) != '\0') && (*(line2.start + q) != '\0'))
  {
    while((!isalpha(*(line1.start + p)))&&(*(line1.start + p) != '\0'))
      p++;
    while((!isalpha(*(line2.start + q)))&&(*(line2.start + q) != '\0'))
      q++;

    if(*(line1.start + p) == *(line2.start + q))
    {
      p++;
      q++;
    }
    else
      break;
  }

  char l1 = *(line1.start + p);
  char l2 = *(line2.start + q);

  if((*(line1.start + p) == '\0') && (*(line2.start + q) == '\0'))
    return 0;
  else if(tolower(l1) == tolower(l2))
    return 0;
  else if(*(line1.start + p) == '\0')
    return -1;
  else if(*(line2.start + q) == '\0')
    return 1;
  else if(tolower(l1) < tolower(l2))
    return -1;
  else if(tolower(l1) > tolower(l2))
    return 1;
  else
    return 0;

  return -100;
}

int back_line_compare(const void * str1, const void * str2)
{
  int p = 0, q = 0;

  Line line1 = *(Line*)str1;
  Line line2 = *(Line*)str2;

  char * last1 = line1.start + line1.len - 1;
  char * last2 = line2.start + line2.len - 1;

  while((last1 - p >= line1.start) && (last2 - q >= line2.start))
  {
    while((!isalpha(*(last1 - p)))&&(last1 - p >= line1.start))
      p++;
    while((!isalpha(*(last2 - q)))&&(last2 - q >= line2.start))
      q++;

    if(*(last1 - p) == *(last2 - q))
    {
      p++;
      q++;
    }
    else
      break;
  }

  char l1 = *(last1 - p);
  char l2 = *(last2 - q);

  if((last1 - p == line1.start) && (last2 - q == line2.start))
    return 0;
  else if(tolower(l1) == tolower(l2))
    return 0;
  else if(l1 == '\0')
    return -1;
  else if(l2 == '\0')
    return 1;
  else if(tolower(l1) < tolower(l2))
    return -1;
  else if(tolower(l1) > tolower(l2))
    return 1;
  else
    return 0;

  return -100;
}


void line_swap(Line * line1, Line * line2)
{
  Line temp = *(line1);
  *(line1) = *(line2);
  *(line2) = temp;
}


void print_text(Line * str_info, int strings)
{
  FILE * f = fopen("Out.txt", "ab");
  for (int i = 0; i < strings; i++)
  {
    //printf("%s\n", str_info[i].start);
    for(int p = 0; *(str_info[i].start+p) != '\0'; p++)
      fputc(*(str_info[i].start+p), f);
    fputc('\n', f);
  }
  fclose(f);
}

void print_buf(char * txt)
{
  FILE * f = fopen("Out.txt", "ab");
  for(int i = 0; txt[i] != EOF; i++)
  {
    if(txt[i] == '\n')
      fputc('\n', f);
    else
      fputc(txt[i], f);
  }
  fputc('\n', f);
  fclose(f);
}
