#include "txtsort.h"

int main()
{
#define ERR_CHECK()       \
if(err_code != IS_OK)     \
  return 0;               \

  int err_code = IS_OK;

  int txtlen = 0;
  char * text = file_to_buf(&txtlen, &err_code, "ONEGIN.txt");
  ERR_CHECK()

  int strings = 0;
  Line * str_info = ptr_maker(text, &strings, &err_code);
  ERR_CHECK()

  Line * original_text = (Line*)calloc(strings, sizeof(Line));
  lines_copy(original_text, str_info, strings, &err_code);
  ERR_CHECK()

  qsort(str_info, strings, sizeof(str_info[0]), line_compare);
  print_text(str_info, strings, &err_code);
  ERR_CHECK()

  qsort(str_info, strings, sizeof(str_info[0]), back_line_compare);
  print_text(str_info, strings, &err_code);
  ERR_CHECK()

  print_text(original_text, strings, &err_code);
  ERR_CHECK()

  free(original_text);
  free(str_info);
  free(text);

#undef ERR_CHECK
  return 0;
}
