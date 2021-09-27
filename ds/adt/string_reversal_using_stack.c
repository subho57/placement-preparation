#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_arr.h"

int main(void) {
    string s = (string)malloc(sizeof(char));

    printf("Enter a  String: ");
    scanf("%[^\n]%*c", s);

    string stack = (string)malloc(strlen(s)*sizeof(char));

    // reversing the string using stack
    for (int i = 0; i < strlen(s); i++)
        push(stack, s[i]);
    for (int i = 0; i < strlen(s); i++)
        s[i] = pop(stack);

    printf("Reversed String: %s\n", s);

    return 0;
}