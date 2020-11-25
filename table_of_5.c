#include<stdio.h>
main()
{
	float n; int sum=0;
	printf("Enter a floating point number:");
	scanf("%f", &n);
	sum+=(int)n%10;
	n-=floor(n);
	sum+=(int)(n*10)%10;
	printf("Sum = %d", sum);
}
