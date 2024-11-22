/**********************************************************************
Program: <Implementation of stack DS>
Author: <David C Osei-Amoah>
Date: <date you finish the program>
Time spent: <total amount of time spent on the project>
Purpose: The purpose of this program is to blah blah blah
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int test_case_is_valid(void);
void clear_keyboard_buffer(void);

int main() {

    int n;

    int i;

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





void clear_keyboard_buffer(void) {
    char c;
    int noc;
    noc = scanf("%c", &c);
    while (noc == 1 &&  c != '\n') {
        noc = scanf("%c", &c);
    }
}



int test_case_is_valid(void) {
    STACK hStack = NULL;
    hStack = stack_init_default();

    if (hStack == NULL) {
        printf("Failed to allocate memory for hStack");
        exit(1);
    }

    char ch;
    int noc;
    noc = scanf("%c", &ch);

    while (noc == 1 && ch != '\n'){
        if (ch == '(' || ch == '{' || ch == '[') {
            stack_push(hStack,ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack_is_empty(hStack)) {
                while (noc == 1 && ch != '\n') {
                    noc = scanf("%c", &ch);
                }
                stack_destroy(&hStack);
                return 0;
            }

            char top = stack_top(hStack,NULL);


            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                while (noc == 1 && ch != '\n') {
                    noc = scanf("%c", &ch);
                }
                stack_destroy(&hStack);
                return 0;
            }

            stack_pop(hStack);
        } else {
            while (noc == 1 && ch != '\n') {
                noc = scanf("%c", &ch);
            }
            return 0;
        }

        noc = scanf("%c", &ch);
    }


    int is_valid = stack_is_empty(hStack);
    stack_destroy(&hStack);
    return is_valid;
}



