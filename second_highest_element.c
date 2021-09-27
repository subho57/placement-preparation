#include <stdio.h>

int main(void){
    int n, max=INT_MIN, smax=INT_MIN;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
        if(arr[i]>max){
            smax=max;
            max=arr[i];
        }
        else if (arr[i] > smax && arr[i] < max)
            smax=arr[i];
    }
    printf("Second Highest Element is = %d", smax);
    return 0;
}