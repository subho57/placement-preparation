#include <stdio.h>
#include <math.h>
int isprime(int n)
{
	if(n==2)
		return 1;
	else if(n<2 || n%2==0)
		return 0;
	else
	{
		int i,c=0;
		for(i=3;i<=sqrt(n);i+=2)
			if(n%i==0)
				c++;
		if(c==0)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int ul, ll, i;
	printf("Enter the Lower and Upper Limit respectively : ");
	scanf("%d %d", &ll, &ul);
	printf("All the Prime Numbers within range are displayed below:\n");
	while(ll++<=ul)
		if(isprime(ll))
			printf("%d,", ll);
	printf("\b");
	return 0;
}