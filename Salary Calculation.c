//SET I
//Question 2
#include<stdio.h>
float salary_calc(float bs)
{
	float hra=0.0,da=0.0;
	if(bs<=10000)
		hra=0.20*bs, da=0.80*bs;
	else if(bs>=10001 && bs<=20000)
		hra=0.25*bs, da=0.90*bs;
	else
		hra=0.30*bs, da=0.95*bs;
	return bs+hra+da;
}
int main(void)
{
	float bs;
	printf("Enter a the Basic Salary\t::\t");
	scanf("%f", &bs);
	printf("Calculated Gross Salary is\t::\t%f",salary_calc(bs));
	return 0;
}

/*OUTPUT
Enter a the Basic Salary        ::      15000.256
Calculated Gross Salary is      ::      32250.550781
--------------------------------
Process exited after 11.31 seconds with return value 0
Press any key to continue . . .
*/
