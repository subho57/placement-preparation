#include <stdio.h>
main()
{
	int a,b,c, min;
	printf("Enter 3 numbers:\n");
	scanf("%d %d %d", &a, &b, &c);
	min=(a<b && a<c)?a:(b<c)?b:c;
	printf("Smallest Number is= %d", min);
}
