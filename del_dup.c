#include <stdio.h>
#include <stdlib.h>
void deletedup(int *n, int *a)
{
	for(int i=0; i<*n-1; i++)
		for(int j=i+1;j<*n;j++)
			if(a[i]==a[j])
			{
				for(int k=j;k<*n-1;k++)
					a[k]=a[k+1];
				a=(int*)realloc(a,(--*n)*sizeof(int));
			}
}
int main()
{
	int n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int *a=(int*)calloc(n,sizeof(int));
	printf("Enter the elements in the array:\n");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("Displaying the elements in the array:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	deletedup(&n,a);
	deletedup(&n,a);
	printf("\nDisplaying the elements in the array after removing the duplicate elements:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
