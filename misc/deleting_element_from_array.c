#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int n){
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
}

int main(void){
    int n, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of the element you want to delete: ");
    scanf("%d", &pos);
    if(pos<0 || pos > n+1){
        printf("Deletion not Possible!");
        exit(0);
    }
    printf("Before Deletion:\t");
    print(arr, n);
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    --n;
    arr=(int*)realloc(arr, n*sizeof(int));
    printf("\n After Deletion:\t");
    print(arr, n);
    free(arr);
    return 0;
}