#include <stdio.h>
main()
{
	int a,b,c, min;
	printf("Enter 3 numbers:\n");
	scanf("%d %d %d", &a, &b, &c);
	if(a!=b && b!=c && a!=c)
		printf("1");
	else
		printf("0");
}
	
