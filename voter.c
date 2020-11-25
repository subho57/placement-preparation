#include <stdio.h>
main()
{
	int a;
	printf("Enter your age:");
	scanf("%d", &a);
	if(a>=18)
		printf("You are a voter!");
	else
		printf("Sorry to say, you are a baby! :p");
}
