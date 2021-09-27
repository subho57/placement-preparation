#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() 
{ 
    char sen[20], ch, s[10];
    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]%*c", sen);
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s", sen);
    return 0; 
} 

