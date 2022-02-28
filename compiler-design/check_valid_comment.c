#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// check whether a string is valid comment or not
// return 1 if valid, 0 if not
int check_valid_comment(char *s) {
  if ((s[0] == '/' && s[1] == '/') || (s[0] == '/' && s[1] == '*' && s[strlen(s)-1] == '/' && s[strlen(s)-2] == '*')) {
    return 1;
  }
  return 0;
}

int main(void) {
  char s[100];
  printf("Enter a string: ");
  scanf("%[^\n]%*c", s);
  if (check_valid_comment(s)) {
    printf("It is a valid comment.\n");
  } else {
    printf("It is not a valid comment.\n");
  }
  return 0;
}
