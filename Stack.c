//
// Created by David Amoah on 10/2/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


struct node;
typedef struct node Node;

struct node {
    char data;
    Node* next;
};

struct stack {
    Node* head;
};

typedef struct stack Stack;


STACK stack_init_default(void) {
    Stack* pStack;
    pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL) {
        pStack->head = NULL;
    }
    return pStack;
}

Status stack_push(STACK hStack, char val) {

    Stack* pStack = (Stack*)hStack;

    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return FAILURE;
    }
    temp->data = val;
    temp->next = pStack->head;
    pStack->head = temp;
    return SUCCESS;
}

Boolean stack_is_empty(STACK hStack) {

    Stack* pStack = (STACK*)hStack;


    return (pStack->head == NULL) ? TRUE : FALSE;
}


void stack_destroy(STACK* phStack) {
    Stack* pStack = (Stack*)*phStack;
    Node* temp;
    while(pStack->head != NULL) {
        temp = pStack->head;
        pStack->head = pStack->head->next;
        free(temp);
    }
    free(pStack);
    *phStack = NULL;
}

Status stack_pop(STACK hStack) {
    Stack* pStack = (Stack*)hStack;
    Node* temp;


    if(stack_is_empty(hStack) == TRUE) {
        return FAILURE;
    }

    temp = pStack->head;
    pStack->head = pStack->head->next;
    free(temp);
    return SUCCESS;
}


char stack_top(STACK hStack, Status* pStatus) {
    Stack* pStack = (Stack*)hStack;

    if (stack_is_empty(hStack) == TRUE) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return '\0';
    }

    if (pStatus != NULL) {
        *pStatus =  SUCCESS;
    }
    return pStack->head->data;
}