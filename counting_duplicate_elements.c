#include <stdio.h>

int count_duplicate(int *arr, int n){
    int count=0;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i]==arr[j]){
                count++;
                break;
            }
    return count;
}
void print(int *arr, int n){
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
}
int main(void){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    while(n){
        printf("Enter element: ");
        scanf("%d", &arr[--n]);
    }
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Enterred Array:\t");
    print(arr, n);
    printf("\nNo. of duplicate elements = %d", count_duplicate(arr, n));
    return 0;
}