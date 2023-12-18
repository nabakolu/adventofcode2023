CC = gcc

all: day-01-trebuchet-1 day-01-trebuchet-2 day-02-cube-conundrum-1 day-02-cube-conundrum-2 day-03-gear-ratios-1

day-01-trebuchet-1: day-01-trebuchet/1/sol
day-01-trebuchet-2: day-01-trebuchet/2/sol
day-02-cube-conundrum-1: day-02-cube-conundrum/1/sol
day-02-cube-conundrum-2: day-02-cube-conundrum/2/sol
day-03-gear-ratios-1: day-03-gear-ratios/1/sol

day-01-trebuchet/1/sol: day-01-trebuchet/1/sol.c
	$(CC) -o day-01-trebuchet/1/sol day-01-trebuchet/1/sol.c

day-01-trebuchet/2/sol: day-01-trebuchet/2/sol.c
	$(CC) -o day-01-trebuchet/2/sol day-01-trebuchet/2/sol.c

day-02-cube-conundrum/1/sol: day-02-cube-conundrum/1/sol.c
	$(CC) -o day-02-cube-conundrum/1/sol day-02-cube-conundrum/1/sol.c

day-02-cube-conundrum/2/sol: day-02-cube-conundrum/2/sol.c
	$(CC) -o day-02-cube-conundrum/2/sol day-02-cube-conundrum/2/sol.c

day-03-gear-ratios/1/sol: day-03-gear-ratios/1/sol.c
	$(CC) -o day-03-gear-ratios/1/sol day-03-gear-ratios/1/sol.c

clean:
	rm */*/sol
