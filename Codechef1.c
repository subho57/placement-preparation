#include <stdio.h>
int main(void) {
	int test,n,x;
	scanf("%d", &test);
	int output[test];
	for(int i=0;i<test;i++) {
	    scanf("%d %d", &n, &x);
	    int deno[n], sum=0;
	    for(int j=0;j<n;j++) {
	        scanf("%d", &deno[j]);
	        sum+=deno[j];
	    }
	    if(sum%x==0 || n==1 && sum>x)
	        output[i]=sum/x;
	    else if(sum<x)
	        output[i]=-1;
	    else {
	        int nm=sum/x,flag=0;
	        for(int j=0;j<n;j++)
	            if(sum-deno[j]>=nm)
	                flag=1;
            if(flag)
                output[i]=-1;
            else
                output[i]=nm;
	    }
	}
	for(int i=0;i<test;i++)
	    printf("%d\n",output[i]);
	return 0;
}