#include <stdio.h>
main()
{
	char s[100]; int i=0,c=0;
	printf("Enter a String:\n");
	scanf("%[^\n]*c", s);
	while(s[i++]!='\0')
		c++;
	printf("The length of the String is= %d", c);
}
