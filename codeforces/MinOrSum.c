#include <stdio.h>

int main(void) {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int or = a[0];
    for (int i = 1; i < n; i++) {
      or = or | a[i];
    }
    printf("%d\n", or);
  }
  return 0;
}
