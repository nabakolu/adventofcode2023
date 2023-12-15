#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *fptr;
  char line[255];
  int first, last;
  int sol;
  int i;

  fptr = fopen(argv[1], "r");

  sol = 0;

  while (fgets(line, 255, fptr)) {
    first = -1;
    last = -1;
    for (i = 0; line[i] != '\0'; i++) {
      if (line[i] >= 48 && line[i] <= 57) {
        if (first == -1) {
          first = i;
        }
        last = i;
      } else {
        switch (line[i]) {
        case 'o':
          if (line[i + 1] == 'n') {
            if (line[i + 2] == 'e') {
              line[i] = '1';
              i--;
              continue;
            }
          }
          break;
        case 't':
          switch (line[i + 1]) {
          case 'w':
            if (line[i + 2] == 'o') {
              line[i] = '2';
              i--;
              continue;
            }
            break;
          case 'h':
            if (line[i + 2] == 'r') {
              if (line[i + 3] == 'e') {
                if (line[i + 4] == 'e') {
                  line[i] = '3';
                  i--;
                  continue;
                }
              }
            }
            break;
          }
          break;
        case 'f':
          switch (line[i + 1]) {
          case 'o':
            if (line[i + 2] == 'u') {
              if (line[i + 3] == 'r') {
                line[i] = '4';
                i--;
                continue;
              }
            }
            break;
          case 'i':
            if (line[i + 2] == 'v') {
              if (line[i + 3] == 'e') {
                line[i] = '5';
                i--;
                continue;
              }
            }
            break;
          }
          break;
        case 's':
          switch (line[i + 1]) {
          case 'i':
            if (line[i + 2] == 'x') {
              line[i] = '6';
              i--;
              continue;
            }
            break;
          case 'e':
            if (line[i + 2] == 'v') {
              if (line[i + 3] == 'e') {
                if (line[i + 4] == 'n') {
                  line[i] = '7';
                  i--;
                  continue;
                }
              }
            }
            break;
          }
          break;
        case 'e':
          if (line[i + 1] == 'i') {
            if (line[i + 2] == 'g') {
              if (line[i + 3] == 'h') {
                if (line[i + 4] == 't') {
                  line[i] = '8';
                  i--;
                  continue;
                }
              }
            }
          }
          break;
        case 'n':
          if (line[i + 1] == 'i') {
            if (line[i + 2] == 'n') {
              if (line[i + 3] == 'e') {
                line[i] = '9';
                i--;
                continue;
              }
            }
          }
          break;
        default:
          break;
        }
      }
    }
    sol += (line[last] - 48) + ((line[first] - 48) * 10);
  }

  fclose(fptr);

  printf("%d\n", sol);
  return 0;
}
