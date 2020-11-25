#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int linear_search(int *arr, int n, int key){
    for(int i=0; i < n; i++){
        if(arr[i]==key)
            return i;
    }
    return 0;
}

// NON-Comparison Based Sorting Techniques
void frequency_sort(int *arr, int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]> max)
            max=arr[i];
    }
    int *freq=(int*)calloc(max+1, sizeof(int));
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0, j=0;i<n;){
        if(freq[j]!=0 && j<=max){
            arr[i++]=j;
            freq[j]--;
        }
        else j++;
    }
}

int binary_search(int *arr, int n, int key){
    // frequency_sort(arr, n);
    int lower=0, upper=n-1;
    while(lower<=upper && key >= arr[lower] && key <= arr[upper] ){
        int mid=lower+(upper-lower)/2;
        if(arr[mid]==key)
            return mid;
        else if(key > arr[mid])
            lower=mid+1;
        else
            upper=mid-1;
    }
    return 0;
}

int interpolation_search(int *arr, int n, int key){
    int lower=0, upper=n-1;
    while(lower <= upper && key >= arr[lower] && key <= arr[upper]){
        if(lower==upper){
            if(arr[lower]==key)
                return lower;
            return 0;
        }
        int pos=lower+(key-arr[lower])/(arr[upper]-arr[lower])*(upper-lower);
        if(arr[pos]==key)
            return pos;
        else if(key > arr[pos])
            lower=pos+1;
        else
            upper=pos-1;
    }
    return 0;
}

int main(void){
    int n=10000000, key;
    printf("Enter the size of the array: %d\n", n);
    int *arr1=(int*)malloc(n*sizeof(int)); // linear
    // int *arr2=(int*)malloc(n*sizeof(int)); // binary
    for (int i=0;i<n;i++){
        arr1[i]=i;
        // printf("Enter element at arr[%d]: %d\n", i, arr1[i]);
        // arr2[i]=arr1[i];
    }
    key=arr1[rand()%n];
    printf("Enter the search key: %d\n", key);
    time_t start_t, end_t;
    double diff_t;
    time(&start_t);
    int ind=linear_search(arr1, n, key);
    time(&end_t);
    if(ind)
        printf("%d is found at arr[%d].", key, ind);
    diff_t = difftime(end_t, start_t);
    printf("\nTime taken by Linear Search=%lf\n", diff_t);

    time(&start_t);
    ind=binary_search(arr1, n, key);
    time(&end_t);
    if(ind)
        printf("%d is found at arr[%d].", key, ind);
    diff_t = difftime(end_t, start_t);
    printf("\nTime taken by Binary Search=%lf\n", diff_t);

    time(&start_t);
    ind=interpolation_search(arr1, n, key);
    time(&end_t);
    if(ind)
        printf("%d is found at arr[%d].", key, ind);
    diff_t = difftime(end_t, start_t);
    printf("\nTime taken by Interpolation Search=%lf\n", diff_t);
    return 0;
}