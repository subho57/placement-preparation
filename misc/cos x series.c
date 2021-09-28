//SET I
//Question 3

#include<stdio.h>
#include<math.h>
#define pi 3.142
int fact(int x)
{
	if(x==0)
		return 1;
	return x*fact(x-1);
}
float cosine(float x, int n)
{
	float sum=0.0;
	int i=0, count=1;
	while(i<=n)
	{
		printf("%d/%d!", (int)pow(x,i),i);
		if(count%2==0)
		{
			sum-=pow(x,i)/fact(i);
			if(i!=x )
				printf(" + ");
		}
		else
		{
			sum+=pow(x,i)/fact(i);
			if(i!=x)
				printf(" - ");
		}
		count++;
		i+=2;
	}
	return sum;
}
int main(void)
{
	float x=0;
	int n=0;
	printf("Enter the value of x:");
	scanf("%f", &x);
	printf("Enter the limit for the cos x series: ");
	scanf("%d", &n);
	printf("\nThe Sum = %.4f", cosine(x,n));
	return 0;
}
