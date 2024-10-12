/**********************************************************************
Program: <Implementation of stack DS>
Author: <David C Osei-Amoah>
Date: <date you finish the program>
Time spent: <total amount of time spent on the project>
Purpose: The purpose of this program is to blah blah blah
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int test_case_is_valid(void);
void clear_keyboard_buffer(void);

int main() {

    int n; // takes the int number of strings

    int i; // used for iteration

    scanf("%d", &n);

    clear_keyboard_buffer();


    for (i = 0; i < n; i++) {
        if (test_case_is_valid()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }


    return 0;
}



int test_case_is_valid(void) {

    STACK hStack;
    hStack = stack_init_default();
    if (hStack == NULL) {
        printf("Failed to allocate memory for hStack");
        exit(1);
    }

    char new_chars;
    int noc;
    noc = scanf("%c", &new_chars);

    while (noc == 1 && new_chars != '\n') {

        if (new_chars == '{' || new_chars == '(' || new_chars == '[') {
            stack_push(hStack, new_chars);
        }

        else if (new_chars == '}' || new_chars == ')' || new_chars == ']') {
            //check to see if stack is empty

            if (stack_is_empty(hStack)) {
                stack_destroy(&hStack);
            }

            char top = stack_top(hStack, NULL);



            if ((new_chars == ')' && top != '(') ||
                (new_chars == '}' && top != '{') ||
                (new_chars == ']' && top != '[')) {

                stack_destroy(&hStack);
                return 0;
            }
        }

        noc = scanf("%c", &new_chars);


    }

    if (!stack_is_empty(hStack)) {
        stack_destroy(&hStack);
        return 0;
    }

    stack_destroy(&hStack);
    return 1;
}



void clear_keyboard_buffer(void) {
    char c;
    while ((c= (char)getchar()) != '\n' && c != EOF);
}