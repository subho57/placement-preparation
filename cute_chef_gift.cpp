#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    gcd(b, a%b);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "OK";
        for (int i = 0; i < n-1; i++) {
            int chef = 1, chefina = 1;
            for (int j = 0; j <= i; j++)
                chef *= arr[j];
            for (int j = i+1; j < n; j++)
                chefina *= arr[j];
            if(gcd(chef, chefina) == 1) {
                cout << i+1 << "\n";
                break;
            }
        }
    }
	return 0;
}
