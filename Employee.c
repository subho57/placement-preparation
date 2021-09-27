#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long ch=0, count=0;
struct Employee
{
	char en[50], add[50], pos[20];
	long eid, age, mob;
}

main()
{	char company[100];
	printf("Enter Company Name: ");
	scanf("%[^\n]%*c", company);
	printf("**********************************************************************************************************************************\n");
	printf("***************************///////////////////////\t WELCOME \t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\***************************\n", company);
	printf("*******************///////////////\t%s\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*******************\n", company);
	printf("**********************************************************************************************************************************\n");
	printf("Enter the total number of Employees: ");
	scanf("%d", &ch);
	struct Employee ptr;
	while(1)
	{
		printf("Press:\n1) To register a new Employee.\n2) To view all existing the Employees.\n3) To remove an Employee's from database.\n4) To search a particular Employee.\n5) To exit the program.\nEnter Your Choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	
					break;
			case 2: 
					break;
			case 3: 
					break;
			case 4: 
					break;
			case 5: exit(0);
			default:printf("Incorrect INPUT. Try a number between (1-4)");
		}
	}
}
