#ifndef INTERFACE_H
#define INTERFACE_H

#include "stack.h"

void invite();
void split();
int what_to_do(Stack * stack, STK_ERR * err_code);
void fury(STK_ERR* err_code);

#endif
