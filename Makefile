CC = gcc

day-01-trebuchet: day-01-trebuchet/1/sol

day-01-trebuchet/1/sol: day-01-trebuchet/1/sol.c
	$(CC) -o day-01-trebuchet/1/sol day-01-trebuchet/1/sol.c

clean:
	rm */*/sol
