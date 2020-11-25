#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void takeinput(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
}

void print(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void matrix_squared(int n, int arr[n][n], int res[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int sum=0;
            for (int k = 0; k < n; k++)
                sum+=arr[i][k]*arr[k][j];
            res[i][j]=sum;
        }
}

void matrix_add(int size, int mat1[size][size], int mat2[size][size], int res[size][size]) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            res[i][j]=mat1[i][j]+mat2[i][j];
}

int **get_unit_matrix(int order){
    int (*mat)[order]=malloc(order*order*sizeof(mat[0][0]));
    for(int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            mat[i][j]=(i==j)?1:0;
    return mat;
}

int main(void) {
    const int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    // declaraing VLA's
    int (*arr)[n]=malloc(n*n*sizeof(arr[0][0]));
    int (*res)[n]=malloc(n*n*sizeof(res[0][0]));
    for (int i = 0; i < n; i++)
        takeinput(arr[i], n);
    printf("Enterred matrix is:\n");
    for (int i = 0; i < n; i++){
        print(arr[i], n);
        printf("\n");
    }
    printf("After solving A^2 + A + I, we get...\n");
    matrix_squared(n, arr, res);
    matrix_add(n, arr, res, res);
    matrix_add(n, res, get_unit_matrix(n), res);
    for (int i = 0; i < n; i++){
        print(res[i], n);
        printf("\n");
    }
    return 0;
}