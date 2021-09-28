#include <stdio.h>
int isprime(int n)
{
	if(n==2)
		return 1;
	else if(n%2==0 || n<2)
		return 0;
	else
	{	int i=0,c=0;
		for(i=3;i<=sqrt(n);i+=2)
			if(n%i==0)
				c++;
		if(c==0)
			return 1;
		else
			return 0;
	}
}
main()
{
	int size=0,i=0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Enterred Array is displayed below: ");
	for(i=0;i<size;i++)
		printf("%d ", arr[i]);
	printf("\nEnterred prime numbers are:\n");
	for(i=0;i<size;i++)
	{
		if(isprime(arr[i])==1)
			printf("%d ", arr[i]);
	}
}
