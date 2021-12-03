#include <stdio.h>

void usingRecursion(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return usingRecursion(n - 1) + usingRecursion(n - 2);
    printf("%d\n", n);
}

void usingLoop(int n)
{
    int a = 0, b = 1, c;
    printf("%d %d ", a, b);
    for (int c = a + b; c <= n; c = a + b)
    {
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main(void) {
    int n, a, b, c;
    printf("Enter a number: ");
    scanf("%d", &n);
    usingRecursion(n);
    printf("Using loop: ");
    usingLoop(n);
    return 0;
}