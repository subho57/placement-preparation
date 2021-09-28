#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int count){
    for (size_t i = 0; i < count; i++)
        printf("%d ", arr[i]);
}

int main(void){
    int count;
    printf("Enter the size of the ARRAY : ");
    scanf("%d", &count);
    int *arr=(int*)calloc(count,sizeof(int));
    for (size_t i = 0; i < count; i++){
        printf("Enter element : ");
        scanf("%d", arr+i);
    }
    printf("Before Deletion : ");
    print(arr, count);
    for (size_t i = 0; i < count-1; i++)
        for (size_t j = i+1; j < count; j++)
            if(arr[i]==arr[j]){
                for (size_t k = j; k < count-1; k++)
                    arr[k]=arr[k+1];
                arr=(int*)realloc(arr, --count*sizeof(int));
            }
    printf("\nAfter Deletion : ");
    print(arr, count);
    free(arr);
    return 0;
}