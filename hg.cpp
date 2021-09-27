#include<stdio.h>
int main()
{
	char ch, w[10], s[100];
	scanf("%c",&ch);
	printf("%c\n",ch);
	scanf("\n%s", w);
	printf("%s\n", w);
	scanf("\n%[^\n]*%c",s);
	printf("%s\n",s);
	return 0;
}
