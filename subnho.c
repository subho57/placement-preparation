#include <stdio.h>
main()
{
	int a,b;
	printf("Enter two numbers:");
	scanf("%d %d", &a,&b);
	printf("A&B=%d",(a&b));
	printf("\nA|B=%d",(a|b));
	printf("\nA^B=%d",(a^b));
	printf("\n~A=%d",(~a));
}
