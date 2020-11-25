#include <stdio.h>
#include <math.h>
int main()
{
	int i, sum=0, n=2;
	for(i=0;i<=n;i++)
	sum+=pow(2,i);
	printf("%d",sum);
	return 0;
}
