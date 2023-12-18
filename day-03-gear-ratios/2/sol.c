#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *fptr;
  char line[255];
  long sol;
  int i, ii;
  int xx;
  int xx2;
  int height, length;
  int tmp;
  int num1, num2;

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
      if (matrix[i][ii] == '*') {
        num1 = 0;
        num2 = 0;
        for (xx = ii - 1; xx < ii + 2; xx++) {
          if (matrix[i - 1][xx] >= 48 && matrix[i - 1][xx] <= 57) {
            for (; matrix[i - 1][xx] >= 48 && matrix[i - 1][xx] <= 57; xx--)
              ;
            xx++;
            num1 = atoi(&matrix[i - 1][xx]);
            if (matrix[i - 1][ii + 1] >= 48 && matrix[i - 1][ii + 1] <= 57 &&
                matrix[i - 1][ii] == '.' && xx < ii) {
              num2 = atoi(&matrix[i - 1][ii + 1]);
            }
            break;
          }
        }

        if (matrix[i][ii - 1] >= 48 && matrix[i][ii - 1] <= 57) {
          for (xx = ii - 1; matrix[i][xx] >= 48 && matrix[i][xx] <= 57; xx--)
            ;
          xx++;
          if (num1 == 0) {
            num1 = atoi(&matrix[i][xx]);
          } else {
            num2 = atoi(&matrix[i][xx]);
          }
        }

        if (matrix[i][ii + 1] >= 48 && matrix[i][ii + 1] <= 57) {
          if (num1 == 0) {
            num1 = atoi(&matrix[i][ii + 1]);
          } else {
            num2 = atoi(&matrix[i][ii + 1]);
          }
        }

        for (xx = ii - 1; xx < ii + 2; xx++) {
          if (matrix[i + 1][xx] >= 48 && matrix[i + 1][xx] <= 57) {
            for (; matrix[i + 1][xx] >= 48 && matrix[i + 1][xx] <= 57; xx--)
              ;
            xx++;
            if (num1 == 0) {
              num1 = atoi(&matrix[i + 1][xx]);
              if (matrix[i + 1][ii + 1] >= 48 && matrix[i + 1][ii + 1] <= 57 &&
                  matrix[i + 1][ii] == '.' && xx < ii) {
                num2 = atoi(&matrix[i + 1][ii + 1]);
              }

            } else {
              num2 = atoi(&matrix[i + 1][xx]);
            }
            break;
          }
        }
        sol += num1 * num2;
      }
    }
  }

  printf("%ld\n", sol);
  return 0;
}
