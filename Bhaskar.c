#include <stdio.h>
int n=0, u[100][100];
void generate()//generates unit matrix of order nxn
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			u[i][j]=(i==j);
}
void sum(int a[n][n])
{
	printf("Summation of the Matrix is as follows:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",u[i][j]);
		if(i==n/2)
			printf("\t+\t");
		else
			printf("\t\t");
		for(int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		if(i==n/2)
			printf("\t=\t");
		else
			printf("\t\t");
		for(int j=0;j<n;j++)
		{
			u[i][j]+=a[i][j];
			printf("%d ",u[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	printf("-------Please Create a n x n Matrix-------\nEnter the value of n:");
	scanf("%d",&n);
	u[n][n];
	generate();
	int a[n][n];
	label:
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			printf("Enter the element at a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("Entered Matrix is displayed below:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	sum(a);
	int ch;
	printf("If you want to Continue Press '1': ");
	scanf("%d",&ch);
	if(ch==1)
		goto label;
	return 0;
}
