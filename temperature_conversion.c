#include <stdio.h>
main()
{
	int c; double ct, temp;
	printf("Press\n1) To Convert Celsius To Farenheit.\n2) To Convert Farenheit To Celsius.\nEnter your Choice: ");
	scanf("%d", &c);
	printf("Enter temperature: ");
	scanf("%lf", &temp);
	switch(c)
	{
		case 1: ct=temp*9/5+32;
				printf("%.2lf°C in Farenheit is: %.2lf°F", temp, ct);
				break;
		case 2: ct=(temp-32)*5/9;
				printf("%.2lf°F in Celsius is: %.2lf°C", temp, ct);
				break;
		default:printf("ERROR: INVALID INPUT");
	}
}
