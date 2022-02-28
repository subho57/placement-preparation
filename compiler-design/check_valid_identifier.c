#include <stdio.h>
#include <string.h>
#include <ctype.h>

// check whether a string is valid identifier or not
// return 1 if valid, 0 if not
int check_valid_identifier(char *s) {
  if (s[0] == '\0') {
    return 0;
  }
  if (!isalpha(s[0]) && s[0] != '_' && s[0] != '$') {
    return 0;
  }
  for (int i = 1; s[i] != '\0'; i++) {
    if (!isalnum(s[i]) && s[i] != '_' && s[i] != '$') {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  char s[100];
  printf("Enter a string: ");
  scanf("%[^\n]%*c", s);
  if (check_valid_identifier(s)) {
    printf("It is a valid identifier.\n");
  } else {
    printf("It is not a valid identifier.\n");
  }
}
