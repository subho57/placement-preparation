#include <stdio.h>
main()
{
	int a,b,c,p;
	printf("Enter three subject marks:");
	scanf("%d %d %d", &a,&b,&c);
	p=(a+b+c)*100/300;
	if(p>=60)
		printf("First Division!");
	else if(p<60 && p>=50)
		printf("Second Division!");
	else if(p>=40 && p<50)
		printf("Third Division!");
	else if(p<40)
		printf("Fail!");
}
