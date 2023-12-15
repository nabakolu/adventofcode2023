CC = gcc

all: day-01-trebuchet-1 day-01-trebuchet-2

day-01-trebuchet-1: day-01-trebuchet/1/sol
day-01-trebuchet-2: day-01-trebuchet/2/sol

day-01-trebuchet/1/sol: day-01-trebuchet/1/sol.c
	$(CC) -o day-01-trebuchet/1/sol day-01-trebuchet/1/sol.c

day-01-trebuchet/2/sol: day-01-trebuchet/2/sol.c
	$(CC) -o day-01-trebuchet/2/sol day-01-trebuchet/2/sol.c

clean:
	rm */*/sol
