#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Comparison Based Sorting Techniques
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end - 1];
    int pIndex = start;
    for (int i = start; i < end - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = arr[end - 1];
    arr[end - 1] = arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;
}

void quick_sort(int *arr, int start, int end)
{
    if (start >= end - 1)
        return;
    int pIndex = partition(arr, start, end);
    quick_sort(arr, start, pIndex - 1);
    quick_sort(arr, pIndex + 1, end);
}

void merge_arrays(int *left, int *right, int *arr, int mid, int n)
{
    int i = 0, j = 0, k = 0, nL = mid, nR = n - mid;
    while (i < nL && j < nR)
    {
        if (left[i] < right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }
    while (i < nL)
        arr[k++] = left[i++];
    while (j < nR)
        arr[k++] = right[j++];
}
void merge_sort(int *arr, int n)
{
    if (n < 2)
        return;

    int mid = n / 2;

    int *left = (int *)malloc(mid * sizeof(int));
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    int *right = (int *)malloc((n - mid) * sizeof(int));
    for (int i = 0; i < n - mid; i++)
        right[i] = arr[i + mid];

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge_arrays(left, right, arr, mid, n);
}
void shell_sort(int *arr, int fake, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int value = arr[i], hole = i;
            while (hole >= gap && arr[hole - gap] > value)
            {
                arr[hole] = arr[hole - gap];
                hole -= gap;
            }
            arr[hole] = value;
        }
    }
}

void insertion_sort(int *arr, int fake, int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = arr[i], hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}

void bubble_sort(int *arr, int fake, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void selection_sort(int *arr, int fake, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i], index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

// NON-Comparison Based Sorting Techniques
void frequency_sort(int *arr, int fake, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int *freq = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 0, j = 0; i < n;)
    {
        if (freq[j] != 0 && j <= max)
        {
            arr[i++] = j;
            freq[j]--;
        }
        else
            j++;
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
int main(void)
{
    int n = 1000000;
    printf("Enter the size of the array: %d\n", n);
    int *arr1 = (int *)malloc(n * sizeof(int));  // selection
    int *arr2 = (int *)malloc(n * sizeof(int));  // bubble
    int *arr3 = (int *)malloc(n * sizeof(int));  // insertion
    int *arr4 = (int *)malloc(n * sizeof(int));  // shell
    int *arr5 = (int *)malloc(n * sizeof(int));  // merge
    int *arr6 = (int *)malloc(n * sizeof(int));  // quick
    int *arr7 = (int *)malloc(n * sizeof(int));  // inbuilt quick
    int *arr8 = (int *)malloc(n * sizeof(int));  // counting
    int *arr9 = (int *)malloc(n * sizeof(int));  // bucket
    int *arr10 = (int *)malloc(n * sizeof(int)); // radix
    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 1000000000 + 1;
        // printf("Enter element at arr[%d]: %d\n", i, arr1[i]);
        arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] = arr7[i] = arr8[i] = arr9[i] = arr10[i] = arr1[i];
    }
    // void (*func_ptr[])(int*, int, int) = {selection_sort, bubble_sort, insertion_sort, shell_sort, merge_sort, quick_sort};
    // int **arr={arr1, arr2, arr3, arr4, arr5, arr6};
    time_t start_t, end_t;
    double diff_t;
    // printf("Time Taken by Comparison Based Sorting Techniques:\nSelection Sort\tBubble Sort\tInsertion Sort\tShell Sort\tMerge Sort\tQuick Sort\tInbuilt Quick Sort\n");
    // time(&start_t);
    // selection_sort(arr1, 0, n);
    // time(&end_t);
    // diff_t = difftime(end_t, start_t);
    // printf("%lf\t", diff_t);

    // time(&start_t);
    // bubble_sort(arr2, 0, n);
    // time(&end_t);
    // diff_t = difftime(end_t, start_t);
    // printf("%lf\t", diff_t);

    // time(&start_t);
    // insertion_sort(arr3, 0, n);
    // time(&end_t);
    // diff_t = difftime(end_t, start_t);
    // printf("%lf\t", diff_t);

    // time(&start_t);
    // shell_sort(arr4, 0, n);
    // time(&end_t);
    // diff_t = difftime(end_t, start_t);
    // printf("%lf\t", diff_t);

    // time(&start_t);
    // merge_sort(arr5, 0, n);
    // time(&end_t);
    // diff_t = difftime(end_t, start_t);
    // printf("\nMerge Sort=%lf\t", diff_t);

    // time(&start_t);
    // quick_sort(arr6, 0, n);
    // time(&end_t);
    // diff_t = difftime(end_t, start_t);
    // printf("\nQuick Sort=%lf\t", diff_t);

    time(&start_t);
    qsort(arr7, n, sizeof(arr7[0]), cmpfunc);
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    printf("\nInbuilt Quick Sort=%lf\n", diff_t);

    printf("Time Taken by NON-Comparison Based Sorting Techniques:\nCounting Sort\tBucket Sort\tRadix Sort\tFrequency Sort\n");
    time(&start_t);
    frequency_sort(arr10, 0, n);
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    printf("\nFrequency Sort=%lf\n", diff_t);

    return 0;
}