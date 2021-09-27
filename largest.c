#include <stdio.h>
main()
{
	int a,b,c,max;
	printf("Enter three numbers:");
	scanf("%d %d %d", &a,&b,&c);
	max=((a>b)&&(a>c))?a:((b>a) && (b>c))?b:c;
	printf("Largest Number=%d", max);
}
