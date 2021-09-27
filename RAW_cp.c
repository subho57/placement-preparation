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
    while(t--){
        int n;
        fastscan(&n);
        int arr1[n], arr2[n];
        for (size_t i = 0; i < n; i++)
        {
            fastscan(&arr1[i]);
            arr2[i]=arr1[i];
        }
        for (size_t i = n-1, j=0; i>=0 && j<n; i--, j++)
        {
            int sum=arr1[j]+arr2[i];
            int carry=sum/10;
            arr2[i]=sum%10;
            if(i==0)
                arr2[i]+=carry;
            else
                arr2[i-1]+=carry;
        }  
        print(arr2, n);
        printf("\n");
    }
    return 0;
}