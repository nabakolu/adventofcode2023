#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *fptr;
  char line[255];
  int sol;
  int i;
  int tmp, green, red, blue;
  int id;

  fptr = fopen(argv[1], "r");

  sol = 0;

  while (fgets(line, 255, fptr)) {
    red = 0;
    green = 0;
    blue = 0;
    id = atoi(&line[5]);
    for (i = 5; line[i] != '\0'; i++) {
      for (; line[i] != ' '; i++)
        ;
      for (; line[i] == ' '; i++)
        ;
      tmp = atoi(&line[i]);
      for (; line[i] != ' '; i++)
        ;
      for (; line[i] == ' '; i++)
        ;
      if (strncmp("red", &line[i], 3) == 0) {
        red = tmp;
        i += 3;
      } else if (strncmp("green", &line[i], 5) == 0) {
        green = tmp;
        i += 5;
      } else if (strncmp("blue", &line[i], 4) == 0) {
        blue = tmp;
        i += 4;
      }
      if (line[i] == ';') {
        if (!(red <= 12 && green <= 13 && blue <= 14)) {
          break;
        }
        red = 0;
        green = 0;
        blue = 0;
      }
    }
    if (red <= 12 && green <= 13 && blue <= 14) {
      sol += id;
    }
  }

  fclose(fptr);

  printf("%d\n", sol);
  return 0;
}
