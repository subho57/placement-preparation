#include <stdio.h>
#include <stdlib.h>
void deletedup(int *n, long *a)
{
	for(int i=0; i<*n-1; i++)
		for(int j=i+1;j<*n;j++)
			if(a[i]==a[j])
			{
				for(int k=j;k<*n-1;k++)
					a[k]=a[k+1];
				a=(long*)realloc(a,(--*n)*sizeof(long));
			}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	long *scores=(long*)calloc(n,sizeof(long));
	for(int i=0;i<n;i++)
		scanf("%ld", &scores[i]);
	deletedup(&n,scores);
	deletedup(&n,scores);
	scanf("%d",&m);
	long *alice=(long*)calloc(m,sizeof(long));
	for(int i=0;i<m;i++)
		scanf("%ld", &alice[i]);
	for(int i=0;i<m;i++)
	{
		for(int j=n-1;j>=0;j--)
		{	
			if(alice[i]<scores[j])
			{
				printf("%d\n",j+2);
				break;
			}
			else if(alice[i]>=scores[0])
			{
				printf("1\n");
				break;
			}
			
		}
	}
	return 0;
}
