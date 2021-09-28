#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int coeff;
  int expo;
  struct Node * link;
}node;

void create(node ** p) {
  node * new = (node * ) malloc(sizeof(node));
  printf("Enter the value of coefficient=");
  scanf("%d", & (new -> coeff));
  printf("Enter the value of exponent=");
  scanf("%d", & (new -> expo));
  new -> link = NULL;
  if ( * p == NULL) {
    * p = new;
  } else {
    node * temp = * p;
    while (temp -> link != NULL) {
      temp = temp -> link;
    }
    temp -> link = new;
  }
}
void polyadd(node ** p1, node ** p2, node ** result) {
  while (( * p1)!=NULL && ( * p2)!=NULL)
  {
    node* new= (node * ) malloc(sizeof(node));
    if (( * p1) -> expo > ( * p2) -> expo)
    {
      new -> coeff = ( * p1) -> coeff;
      new -> expo = ( * p1) -> expo;
      p1 = & ( * p1) -> link;
    }
    else if (( * p2) -> expo > ( * p1) -> expo)
    {
      new -> coeff = ( * p2) -> coeff;
      new -> expo = ( * p2) -> expo;
      p2 = & ( * p2) -> link;
    }
    else
    {
      new-> coeff = ( * p1) -> coeff + ( * p2) -> coeff;
      new-> expo = ( * p1) -> expo;
      p1 = & ( * p1) -> link;
      p2 = & ( * p2) -> link;
    }
    new-> link = NULL;
    if ( *result == NULL) {
      *result = new;
    }
    else
    {
      while ((*result) -> link != NULL) {
        result = &(*result) -> link;
      }
      (*result) -> link = new;
    }
  }
  while (( * p1) !=NULL || ( * p2)!=NULL)
  {
    node* new= (node * ) malloc(sizeof(node));
    new->link=NULL;
    
    if (( * p1)!=NULL)
    {
      new-> coeff = ( * p1) -> coeff;
      new-> expo = ( * p1) -> expo;
      p1 = & ( * p1) -> link;
    }
    if (( * p2)!=NULL)
    {
      new-> coeff = ( * p2) -> coeff;
      new-> expo = ( * p2) -> expo;
      p2 = & ( * p2) -> link;
    }
    if ( *result == NULL) {
      *result = new;
    }
    else
    {
      while ((*result) -> link != NULL) {
        result = &(*result) -> link;
      }
      (*result) -> link = new;
    }
  }
  printf("\nPolynomials Added!!");
}
void display(node ** p) {
  node * temp = * p;
  while (temp != NULL) {
    printf("%dx^%d + ", temp -> coeff, temp -> expo);
    temp = temp -> link;
  }
}
void main() {
  node *poly1 = NULL;
  node *poly2 = NULL;
  node *result = NULL;
  printf("\nEnter:-\n1)1 to add values to polynomial 1\n2)2 to add values to polynomial 2\n3)3 to add  2 polynomials  \n4)to display polynomial 1 \n5)to display polynomial 2\n6)to display the result\n7)exit");
  int n;
  while (1) {
    printf("\nEnter your Choice : ");
    scanf("%d", & n);
    switch (n) {
    case 1:
      create( & poly1);
      break;
    case 2:
      create( & poly2);
      break;
    case 3:
      polyadd( &poly1, &poly2, &result);
      break;
    case 4:
      display( & poly1);
      break;
    case 5:
      display( & poly2);
      break;
    case 6:
      display( & result);
      break;
    case 7:
      exit(0);
    default:
      printf("Wrong Choice!!");
    }
  }

}