#include <stdio.h>
#include <stdlib.h>

void takeinput(int *poly, int size){
    for (int i = size-1; i >= 0; i--){
        printf("Enter coefficient of x^%d : ", i);
        scanf("%d", &poly[i]);
    } 
}

void add(int *poly1, int size1, int *poly2, int size2, int *res){
   // Initialize the product polynomial 
   for (int i = 0; i<size1; i++) 
     res[i] = poly1[i]; 
  
   // Take every term of first polynomial 
   for (int i=0; i<size2; i++) 
       res[i] += poly2[i];
}

void multiply(int *poly1, int size1, int *poly2, int size2, int *res){
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            res[i+j]+=poly1[i]*poly2[j];
}

// declare the degree off the polynomial
void printpoly(int *poly, int size){
    for (int i = size-1; i >= 0; i--)
        if(poly[i]!=0){
            if(i==0)
                printf("%d", poly[i]);
            else if(i==1)
                printf("%dx + ", poly[i]);
            else
                printf("%dx^%d + ", poly[i], i);
        }
}

int main(void){
    int size1, size2, size3;
    printf("Enter the highest degree of Polynomial 1: ");
    scanf("%d", &size1);
    printf("Enter the highest degree of Polynomial 2: ");
    scanf("%d", &size2);
    size1++; size2++;
    size3=(size1>=size2)?size1:size2;

    // creation of the arrays
    int *poly1=(int*)calloc(size1, sizeof(int));
    int *poly2=(int*)calloc(size2, sizeof(int));
    int *poly3=(int*)calloc(size3, sizeof(int));

    // accepting user input
    printf("\nTaking input in the 1st Polynomial...\n");
    takeinput(poly1, size1);
    printf("\nTaking input in the 2nd Polynomial...\n");
    takeinput(poly2, size2);

    // adding the polynomials
    add(poly1, size1, poly2, size2, poly3);

    // printing the polynomials
    printf("\nPolynomial 1: ");
    printpoly(poly1, size1);
    printf("\nPolynomial 2: ");
    printpoly(poly2, size2);
    printf("\nAdded Polynomial: ");
    printpoly(poly3, size3);
    return 0;
}


