#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_arr.h"

int main(void) {
    string s = (string)malloc(sizeof(char));
    string stack = (string)malloc(sizeof(char));
    printf("Enter the string: ");
    scanf("%[^\n]%*c", s);
    char temp;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(stack, s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty(top) || (stack[top-1] == '(' && s[i] != ')') || (stack[top-1] == '{' && s[i] != '}') || (stack[top-1] == '[' && s[i] != ']')) {
                printf("Brackets Are Not Balanced!\n");
                return 0;
            }
            else
                temp = pop(stack);
        }
    }
    if (isEmpty(top))
        printf("Brackets Are Balanced!\n");
    else
        printf("Brackets Are Not Balanced!\n");
    free(s);
    free(stack);
    return 0;
}