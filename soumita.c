#include <stdio.h>
void main()
{	int c=1; int k=1;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=i;j++)
			printf("*");
		for(int j=3;j>=i && i!=3;)
		{
			printf(" ");
			if(i==1)
			j--;
			else
			j-=2;
		}
		for(int j=1;j<=c;)
		{
			printf("*");
			if(i==1)
			j+=2;
			else
			j++;
		}
		for(int j=3;j>=i && i!=3;)
		{
			printf(" ");
			if(i==1)
			j--;
			else
			j-=2;
		}
		for(int j=1;j<=i;j++)
			printf("*");
		printf("\n");
		c=3;
	}
}
