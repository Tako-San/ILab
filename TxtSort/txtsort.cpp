#include "txtsort.h"

char * file_to_buf(int * txtlen, int * err_code, const char * filename)
{
  if(txtlen == NULL || filename == NULL)
  {
    * err_code = FUNC_ARG_NULL_PTR_ERR;
    return NULL;
  }
  FILE * f;
  if ((f = fopen(filename, "rb")) == NULL)
  {
    //printf("File reading failure.\n");
    //exit(1);
    * err_code = FILE_TO_BUF_FILE_OPENING_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return NULL;
  }

  int flen = file_length(f, err_code);

  if(!is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__))
    return NULL;

  char * text = (char *)calloc(flen + 1, sizeof(text[0]));
  if(!text)
  {
    //printf("Allocation failure\n");
    //exit(1);
    * err_code = MEM_ALLOC_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return NULL;
  }

  flen = fread(text, sizeof(text[0]), flen, f);

  text[flen] = '\0';

  fclose(f);

  *txtlen = flen;
  return text;
}


int file_length(FILE * f, int * err_code)
{
  if(f == NULL)
  {
    * err_code = FUNC_ARG_NULL_PTR_ERR;
    return 0;
  }
  fseek(f, 0, SEEK_END);
  int len = ftell(f);
  if(len == -1L)
  {
    //printf("fseek error\n");
    //exit(1);
    * err_code = FSEEK_ERR;
    return 0;
  }
  rewind(f);
  return len;
}


Line * ptr_maker(char * txt, int * strings, int * err_code)
{
  if(txt == NULL || strings == NULL)
  {
    * err_code = FUNC_ARG_NULL_PTR_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return NULL;
  }

  int StrCount = 0;

  for(int i = 0; txt[i] != '\0'; i++)
  {
    if(txt[i] == '\n')
      StrCount++;
  }
  *strings = StrCount;
  StrCount++;

  Line * str_info = (Line *)calloc(StrCount, sizeof(Line));
  if(!str_info)
  {
    //printf("Allocation failure\n");
    //exit(1);
    * err_code = MEM_ALLOC_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return NULL;
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

  while(/*(l1[p] != '\0') && (l2[q] != '\0')*/(p >= 0) && (q >= 0))
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


void print_text(Line * str_info, int strings, int * err_code, char * filename)
{
  if(str_info == NULL)
  {
    * err_code = FUNC_ARG_NULL_PTR_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return;
  }

  if(strings <= 0)
  {
    *err_code = PRINT_STR_NUM_BELOW_ZERO_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return;
  }

  FILE * f;
  if ((f = fopen(filename, "ab")) == NULL)
  {
    //printf("File opening failure.\n");
    //exit(1);
    * err_code = PRINT_FILE_OPENING_ERR;
    is_OK(err_code, __LINE__, __FILE__, __PRETTY_FUNCTION__);
    return;
  }

  for (int i = 0; i < strings; i++)
  {
    /*for(int p = 0; *(str_info[i].start+p) != '\0'; p++)
      fputc(*(str_info[i].start+p), f);
    fputc('\n', f);*/
    fputs(str_info[i].start, f);
    fputc('\n', f);
  }

  fputc('\n', f);

  fclose(f);
}

void lines_copy(Line* dst, Line* src, int size, int * err_code)
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

int is_OK(int * err_code, int line, const char * filename, const char * funcname)
{
#define COND_CHECK(err_name, err_massage)  \
else if(* err_code == err_name)            \
{                                          \
  printf("%s\n", err_massage);             \
  printf("File: %s\n", filename);          \
  printf("Func: %s\n", funcname);          \
  printf("Line: %d\n", line);              \
  return 0;                                \
}                                          \

  if(* err_code == IS_OK)
    return 1;
  COND_CHECK(MEM_ALLOC_ERR, "Memory allocation error")
  COND_CHECK(FUNC_ARG_NULL_PTR_ERR, "Function argument pointer is NULL.")

  //COND_CHECK(MAKER_TXT_NULL_PTR_ERR, "Text buffer pointer is NULL")
  //COND_CHECK(STRINGS_NUM_NULL_PTR_ERR, "Strings num pointer is NULL")

  //COND_CHECK(PRINT_LINE_BUFF_NULL_PTR_ERR, "line buffer pointer is NULL")
  COND_CHECK(PRINT_STR_NUM_BELOW_ZERO_ERR, "String number is too low.")
  COND_CHECK(PRINT_FILE_OPENING_ERR, "Writing file opening error.")

  COND_CHECK(READ_FILE_OPENING_ERR, "Reading file opening error.")

  else
  {
    printf("Unknown error code\n");
    return 0;
  }


#undef COND_CHECK
}
