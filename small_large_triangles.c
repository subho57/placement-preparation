#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct triangle
{
	int a;
	int b;
	int c;
};
typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    float* s=(float*)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        float p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        s[i]=(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(s[j]<s[i]) {
                int temp=s[j],temp_a=tr[j].a,temp_b=tr[j].b, temp_c=tr[j].c;
                s[j]=s[i];
                s[i]=temp;
                tr[j].a=tr[i].a;
                tr[j].b=tr[i].b;
                tr[j].c=tr[i].c;
                tr[i].a=temp_a;
                tr[i].b=temp_b;
                tr[i].c=temp_c;
            }
    free(s);
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}