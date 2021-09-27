#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Employee{
    char eid[5];
    char name[20];
    char add[50];
    long long int phone;
    char sal[15];
}emp;
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    emp e[n];
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]%*c", e[i].eid);
        getchar();
        scanf("%[^\n]%*c", e[i].name);
        getchar();
        scanf("%[^\n]%*c", e[i].add);
        getchar();
        scanf("%lld", &e[i].phone);
        getchar();
        scanf("%[^\n]%*c", e[i].sal);
        getchar();
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n", e[i].eid);
        printf("%s\n", e[i].name);
        printf("%s\n", e[i].add);
        printf("%lld\n",e[i].phone);
        printf("%s\n\n", e[i].sal);
    }
    return 0;
}
