#include <stdio.h>
#include <stdlib.h>

int main(void){
    int r1,c1,r2,c2;
    printf("Enter the order of the 1st matrix (m x n): ");
    scanf("%d x %d", &r1, &c1);
    printf("Enter the order of the 2nd matrix (m x n): ");
    scanf("%d x %d", &r2, &c2);
    if(c1!=r2){
        printf("Matrix Multiplication is not possible between these matrices!!\nProgram will exit now!");
        exit(0);
    }
    int mat1[r1][c1],mat2[r2][c2], mat3[r1][c2];
    printf("\n~~~~~~~~~~~~~~~~Enter elements in Matrix 1~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("Enter elements at Matrix1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n~~~~~~~~~~~~~~~~Enter elements in Matrix 2~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            printf("Enter elements at Matrix2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    // Multiplying the matrices
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int sum=0;
            for(int k=0;k<c1;k++)
                sum+=mat1[i][k]*mat2[k][j];
            mat3[i][j]=sum;
        }
    }
    printf("Printing Matrix 1:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("|%d|\t", mat1[i][j]);
        }
        printf("\n");
    }
    printf("Printing Matrix 2:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            printf("|%d|\t", mat2[i][j]);
        }
        printf("\n");
    }
    printf("Printing the Multiplied Matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("|%d|\t", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}