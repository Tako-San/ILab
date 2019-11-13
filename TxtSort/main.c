#include "txtsort.h"

int main()
{

  int txtlen = 0;
  char * text = file_to_buf(&txtlen);

  int strings = 0;
  Line * str_info = ptr_maker(text, &strings);;
  

  qsort(str_info, strings, sizeof(str_info[0]), line_compare);
  print_text(str_info, strings);

  qsort(str_info, strings, sizeof(str_info[0]), back_line_compare);
  print_text(str_info, strings);


  free(str_info);
  free(text);

  return 0;

}
