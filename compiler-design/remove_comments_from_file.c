#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// remove singleline, multiline and document comments from a file
// return 1 if success, 0 if fail
int remove_comments_from_file(char *file_name) {
  // open file
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 0;
  }

  // open a new file to write
  FILE *fp_new = fopen("temp.c", "w");
  if (fp_new == NULL) {
    printf("Error opening file.\n");
    return 0;
  }

  // read file line by line
  char line[100];
  while (fgets(line, sizeof(line), fp)) {
    // check if line is a singleline comment
    if (line[0] == '/' && line[1] == '/') {
      // skip this line
      continue;
    }
    // check if line is a multiline comment
    if (line[0] == '/' && line[1] == '*') {
      // skip this line
      continue;
    }
    // check if line is a document comment
    if (line[0] == '/' && line[1] == '*' && line[strlen(line)-1] == '*' && line[strlen(line)-2] == '/') {
      // skip this line
      continue;
    }
    // if not, write the line
    fprintf(fp_new, "%s", line);
  }

  // close file
  fclose(fp);

  // close file
  fclose(fp_new);

  // remove old file
  remove(file_name);

  // rename new file to old file
  rename("temp.c", file_name);

  return 1;
}

int main(void) {
  char filename[100];
  printf("Enter a filename: ");
  scanf("%s", filename);
  if (remove_comments_from_file(filename)) {
    printf("Successfully removed comments from the file.\n");
  } else {
    printf("Failed to remove comments from the file.\n");
  }
  return 0;
}
