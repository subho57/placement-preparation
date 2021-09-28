#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *string=(char*)malloc(sizeof(char));
    scanf("%s", string);
    for(int i=48;i<=57;i++){
        int count=0;
        for(int j=0;j<strlen(string);j++){
            if(string[j]==i)
                count++;
        }
        printf("%d ", count);
    }
    return 0;
}