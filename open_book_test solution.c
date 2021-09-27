#include<stdio.h>//importing the header file
main()//main method()
{
	int n, c=2, d=2, i=10, j=0;
	printf("Enter the number of turns:");
	scanf("%d", &n);//taking user input
	if(n<2 || n>1000)
		printf("Invalid INPUT!\nThe Value of 'n' should be within 2 and 1000");
	else
	{
		while(d<=n)
		{
			if(c==1)
			{	
				i+=d++*10;
				c++;
			}
			else if(c==2)
			{
				j+=d++*10;
				c++;
			}
			else if(c==3)
			{
				i-=d++*10;
				c++;
			}
			else if(c==4)
			{
				j-=d++*10;
				c=1;
			}
		}
		printf("Position of the man is: %d %d", i,j);//printing the position
	}
}
