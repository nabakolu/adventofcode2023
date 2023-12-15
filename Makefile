CC = gcc

day-01-1-trebuchet: day-01-1-trebuchet/sol

day-01-1-trebuchet/sol: day-01-1-trebuchet/sol.c
	$(CC) -o day-01-1-trebuchet/sol day-01-1-trebuchet/sol.c

clean:
	rm */sol
