#include <stdio.h>
void scandup(int a[],int n)
{
	int dup=0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n && a[j]==a[i];j++)
		{
			dup++;
			i=j;
		}
	printf("\nTotal no. of Duplicate elements= %d",dup);
}
void sort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	printf("\nPrinting the sorted array elements: ");
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
}
int main()
{
	int n;
	printf("Enter the size of the array:");
	scanf("%d", &n);
	int a[n];
	printf("Enter elements: ");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("Printing the array elements: ");
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	sort(a, n);
	scandup(a,n);
	return 0;
}
