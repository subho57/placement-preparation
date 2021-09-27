#include<stdio.h>
void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort012(int a[], int size)
{
	int lo=0, hi=size-1, mid=0;
	while(mid<=hi)
	{
		switch(a[mid])
		{
			case 0:	swap(&a[lo++], &a[mid++]);
					break;
			case 1:	mid++;
					break;
			case 2:	swap(&a[mid], &a[hi--]);
					break;
		}
	}
}
int main(void)
{
	int A[]={0,1,1,0,1,2,1,2,0,0,0,1};
	int size=sizeof(A)/sizeof(A[0]);
	printf("Unsorted Array	:	");
	for(int i=0;i<size;i++)
		printf("|%d|", A[i]);
	sort012(A, size);
	printf("\nSorted Array	:	");
	for(int i=0;i<size;i++)
		printf("|%d|", A[i]);
	return 0;
}
