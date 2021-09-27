#include <stdio.h>

int main(void) {
    int n, i = 2, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    while (n != 1) {
        if (n % i == 0) {
            sum += i;
            while (n % i == 0)
                n /= i;
        }
        else
            i++;
    }
    printf("Sum of all prime factors = %d\n", sum);
    return 0;
}