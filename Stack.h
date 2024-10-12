//
// Created by David Amoah on 10/2/2024.
//

#ifndef STACKDS_STACK_H
#define STACKDS_STACK_H
#include "status.h"


// push pop top empty
typedef void* STACK;

Status stack_push(STACK hStack, char val);

Status stack_pop(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

Boolean stack_is_empty(STACK hStack);

STACK stack_init_default(void);

void stack_destroy(STACK* phStack);

void print_stack(STACK hStack);



#endif //STACKDS_STACK_H
