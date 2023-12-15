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
      }
    }
    sol += (line[last] - 48) + ((line[first] - 48) * 10);
  }

  fclose(fptr);

  printf("%d\n", sol);
  return 0;
}
