#include <stdio.h>
main()
{
	int a;
	printf("Enter your age:");
	scanf("%d", &a);
	if(a<=30)
	printf("You are Young. Be strong!");
	else if(a>30 && a<=55)
	printf("You are having mid-life crisis!");
	else
	printf("Sorry to say, you are old!");
}
