#include <stdio.h>
int main()
{
	int n, sum=0;
	printf("Enter a number:");
	scanf("%d", &n);
	while(n>9)
	{
		sum=0;
		while(n!=0)
		{
			int rem=n%10;
			sum+=rem;
			n/=10;
		}
		n=sum;
	}
	printf("The current number is= %d", n);
	return 0;
}
