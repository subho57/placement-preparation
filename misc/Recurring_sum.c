//SET I
//Question 1
#include<stdio.h>
int recurring_sum(int n)
{
	while(n>9)
	{
		int sum=0;
		while(n!=0)
		{
			sum+=n%10;
			n/=10;
		}
		n=sum;
	}
	return n;
}
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	printf("New Modified Number is : %d",recurring_sum(n));
	return 0;
}

/*OUTPUT:

Enter a number:1546
New Modified Number is : 7
--------------------------------
Process exited after 3.056 seconds with return value 0
Press any key to continue . . .
*/

