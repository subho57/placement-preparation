#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a=(int*)malloc(6*sizeof(int));
	int *b=(int*)calloc(6,sizeof(int));
	printf("%u %u", *a,*b);
	free(a);
}
