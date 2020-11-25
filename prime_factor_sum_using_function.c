#include <stdio.h>
#include <math.h>

int isprime(int n) {
    if (n < 2 || n % 2 == 0)
        return 0;
    else if (n == 2)
        return 1;
    else {
        int flag = 0;
        for (int i = 3; i <= sqrt(n); i+=2)
            if (n % i == 0) {
                flag = 1;
                break;
            }
        if (flag)
            return 0;
        else
            return 1;
    }
}

int main(void) {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
        if (n % i == 0 && isprime(i))
            {printf("%d ", i); sum += i;}
    printf("Sum of the prime Factors = %d", sum);
    return 0;
}