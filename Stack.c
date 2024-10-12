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


Status stack_push(STACK hStack, char val) {
    // we are going to push a new node onto the stack
    Stack* pStack = (Stack*)hStack;

    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return FAILURE;
    }
    temp->data = val;
    temp->next = pStack->head;
    pStack->head = temp;
    return SUCCESS;
}

Boolean stack_is_empty(STACK hStack) {
    //interface function, cast to the known type
    Stack* pStack = (STACK*)(hStack);

    //returns true if stack's head is NULL
    return (pStack->head == NULL) ? TRUE : FALSE;
}

STACK stack_init_default(void) {
    Stack* pStack;
    pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL) {
        pStack->head = NULL;
    }
    return pStack;
}

// this destroys each node in the stack
void stack_destroy(STACK* phStack) {
    Stack* pStack = (Stack*)*phStack;
    Node* temp;
    while(pStack->head != NULL) {
        temp = pStack->head;
        pStack->head = pStack->head->next;
        free(temp);
    }
    phStack = NULL;
}

Status stack_pop(STACK hStack) {
    Stack* pStack = (Stack*)hStack;
    Node* temp;

    //throws an error if stack is empty so we check
    if(stack_is_empty(hStack) == TRUE) {
        return FAILURE;
    }

    temp = pStack->head;
    pStack->head = pStack->head->next;
    free(temp);
    return SUCCESS;
}

void print_stack(STACK hStack){
    Stack* pStack = (Stack*)hStack;
    if (stack_is_empty(hStack) == FALSE){
        Node* current = pStack->head;
        while(current != NULL) {
            printf("%c\n",current->data);
            current = current->next;
        }
    }
    else {
        printf("Stack is empty");
    }

}

char stack_top(STACK hStack, Status* pStatus) {
    Stack* pStack = (Stack*)hStack;

    if (stack_is_empty(hStack) == TRUE) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return '\0'; // garbage value
    }

    if (pStatus != NULL) {
        *pStatus =  SUCCESS;
    }
    return pStack->head->data;
}
