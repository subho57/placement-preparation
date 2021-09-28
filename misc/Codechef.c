#include<stdio.h>
#include<math.h>
char isprime(long n)
{
    if (n == 2)
		return 1;
	else if (n < 2 || n % 2 == 0)
		return 0;
	else
	{
		for (long i= 3; i <=(int)sqrt(n); i += 2)
			if (n % i == 0)
				return 0;
		return 1; 
	}
}
long countpf(long n)
{   
    long pf = 0;
	for (long j = 2; j <= n / 2; j++)
		if (n % j == 0 && isprime(j))
			pf++;
	return pf;
}
long countcf(long n)
{
    long cf = 0;
	for (long j = 4; j <= n / 2; j++)
		if (n % j == 0 && isprime(j) == 0)
			cf++;
	return cf;
}
int main()
{
    int tc=0,n=1;
    scanf("%d", &tc);
    while(n++<=tc)
    {
        long x=0,k=0;
        scanf("%ld %ld", &x, &k);
        long cf=x-k-2, flag=0;
        if(x==k && k==2)
            printf("1\n");
        else if(x==0 || k==0)
        	printf("0\n");
        else
        {
            for(long i=1;i<=100;i++)
            {
                if(isprime(i)==0 && countpf(i)==k && countcf(i)==cf)
                {
                    printf("1\n");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
            printf("0\n");
    }
    return 0;
}
