#include<stdio.h>
int main()
{
	int n=21;
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	printf("Printing the array:\n");
	for(int i=0;i<n;i++)
		printf("%d ", arr[i]);
	int mn=19;
	for(int i=0;i<n;i++)
		if(arr[i]==mn)
		{
			printf("\nMissing Number found at position arr[%d]",i);
			exit(0);
		}
	printf("Number Not found!");
	return 0;
}
