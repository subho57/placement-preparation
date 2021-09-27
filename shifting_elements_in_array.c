#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int n){
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
}

void shift_by_space(int *arr, int *n, int val){
    for (int i = 0; i < val; i++) {
        int temp=arr[i];
        arr=(int*)realloc(arr, (*n+1)*sizeof(int));
        arr[*n++]=temp;
    }
    n-=val;
    arr+=val;
}

void shift_in_place(int *arr, int n, int val){
    for (int i = 0; i < val; i++){
        int temp=arr[0];
        for (int j = 0; j < n-1; j++)
            arr[j]=arr[j+1];
        arr[n-1]=temp;
    }
}

int main(void){
    int n, val;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the value by which you want to shift: ");
    scanf("%d", &val);
    printf("\nBefore Shifting:\t");
    print(arr, n);
    shift_in_place(arr, n, val);
    printf("\n After Shifting:\t");
    print(arr, n);
    free(arr);
    return 0;
}