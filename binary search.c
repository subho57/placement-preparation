#include <stdio.h> 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	while (l <= r) { 
		int m = l + (r - l) / 2; 
		if (arr[m] == x) 
			return m; 
		if (arr[m] < x) 
			l = m + 1; 
		else
			r = m - 1; 
	}
	return -1; 
} 

int main(void) 
{ 
	int n=21000;
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	int mn=19562;
	int result = binarySearch(arr, 0, n - 1, mn);
	(result == -1) ? printf("\nNumber Not found!") : printf("\nMissing Number found at position arr[%d]", result);
	return 0; 
}
