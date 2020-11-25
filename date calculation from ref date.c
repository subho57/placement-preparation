#include <stdio.h>
#include <time.h>
#include <string.h>
int isleap(int year)
{
	if(year%400 == 0 || year%4==0 && year%100 !=0) return 1;
	else return 0;
}
int main(void)
{
	struct tm refdt, newdt;
	char temp[10];
	printf("Enter reference date in the format dd-mm-yyyy\t: ");
	scanf("%d-%d-%d",&refdt.tm_mday , &refdt.tm_mon, &refdt.tm_year);
	printf("\t\tEnter the name of the week\t: ");
	scanf("%s", temp);
	char arr[7][10]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	for(int i=0; i<7; i++)
		if(strcmp(temp, arr[i])==0)
		{
			refdt.tm_wday=i;
			break;
		}
	
	printf("%d-%d-%d %d", refdt.tm_mday, refdt.tm_mon, refdt.tm_year, refdt.tm_wday);
	return 0;
}
