#include <stdio.h>

void fastscan(int *number) { 
    //variable to indicate sign of input number 
    int negative = 0; 
    register int c; 
    (*number) = 0; 
    // extract current character from buffer 
    c = _getchar_nolock(); 
    if (c=='-') { 
        // number is negative 
        negative = 1; 
        // extract the next character from the buffer 
        c = _getchar_nolock(); 
    }
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=_getchar_nolock()) 
        (*number) = (*number) *10 + c - 48; 
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        (*number) *= -1; 
}
void print(int *arr, int n){
    for (int i=0;i<n;i++)
        printf("%d", arr[i]);
}
int main(void){
    int t;
    fastscan(&t);
    while(t--) {
        int a, d, k, n, inc;
        fastscan(&a);
        fastscan(&d);
        fastscan(&k);
        fastscan(&n);
        fastscan(&inc);
        for(int i=1, j=1; i<n; i++)
        {
            if(j==k)
            {
                j=1;
                d+=inc;
            }
            else
            {
                j++;
            }
            a+=d;
            printf("%d\n", a);
        }
        printf("%d\n", a);
    }
    return 0;
}