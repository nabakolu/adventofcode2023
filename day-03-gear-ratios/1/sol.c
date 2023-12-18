#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *fptr;
  char line[255];
  int sol;
  int i, ii;
  int xx;
  int height, length;
  int tmp;
  int numberLength;

  fptr = fopen(argv[1], "r");

  sol = 0;

  for (height = 0; fgets(line, 255, fptr); height++)
    ;
  fclose(fptr);
  for (length = 0; line[length] != '\0' && line[length] != '\n'; length++)
    ;

  height += 2;
  length += 2;
  char matrix[height][length];

  fptr = fopen(argv[1], "r");

  for (i = 1; i < height - 1; i++) {
    fgets(line, length + 1, fptr);
    matrix[i][0] = '.';
    matrix[i][length - 1] = '.';
    strncpy(&matrix[i][1], line, length - 2);
  }
  for (i = 0; i < length; i++) {
    matrix[0][i] = '.';
    matrix[height - 1][i] = '.';
  }
  fclose(fptr);

  for (i = 1; i < height - 1; i++) {
    for (ii = 1; ii < length - 1; ii++) {
      if (matrix[i][ii] >= 48 && matrix[i][ii] <= 57) {
        tmp = atoi(&matrix[i][ii]);
        for (numberLength = 0; matrix[i][ii + numberLength] >= 48 &&
                               matrix[i][ii + numberLength] <= 57;
             numberLength++)
          ;
        if (matrix[i][ii - 1] != '.' || matrix[i][ii + numberLength] != '.') {
          sol += tmp;
        } else {
          for (xx = ii - 1; xx < ii + 1 + numberLength; xx++) {
            if (matrix[i - 1][xx] != '.' || matrix[i + 1][xx] != '.') {
              sol += tmp;
              break;
            }
          }
        }
        ii += numberLength;
      }
    }
  }

  printf("%d\n", sol);
  return 0;
}
