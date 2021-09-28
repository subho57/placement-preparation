#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long count=0, eid[], age[], mob[];
char en[][], add[][], pos[][];
struct Employee
{
	int age;
}
main()
{	int ch; char company[100];
	printf("Enter Company Name: ");
	scanf("%[^\n]%*c", company);
	printf("**********************************************************************************************************************************\n");
	printf("***************************///////////////////////\t WELCOME \t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\***************************\n", company);
	printf("*******************///////////////\t%s\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*******************\n", company);
	printf("**********************************************************************************************************************************\n");
	printf("Enter the total number of Employees: ");
	scanf("%d", &ch);
	struct 
	eid[ch]=0;
	age[ch]=0;
	mob[ch]=0;
	en[ch][50]=0;
	add[ch][50]=0;
	pos[ch][20]=0;
	while(1)
	{
		printf("Press:\n1) To register a new Employee.\n2) To view all existing the Employees.\n3) To remove an Employee's from database.\n4) To search a particular Employee.\n5) To exit the program.\nEnter Your Choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	insert();
					break;
			case 2: display();
					break;
			case 3: search();
					break;
			case 4: pop();
					break;
			case 5: exit(0);
			default:printf("Incorrect INPUT. Try a number between (1-4)");
		}
	}
}
