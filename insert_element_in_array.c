#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void print(int *arr, int n){
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
}

int main(void){
    int n, key, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr=(int *)malloc((n+1) *sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to insert: ");
    scanf("%d", &key);
    printf("Enter the position where you want to insert: ");
    scanf("%d", &pos);
    if(pos<0 || pos > n+1){
        printf("Insertion not Possible!");
        exit(0);
    }
    printf("Before Insertion:\t");
    print(arr, n);
    for(int i=n;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=key;
    printf("\nAfter Insertion:\t");
    print(arr, n+1);
    return 0;
}