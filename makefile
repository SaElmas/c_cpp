CFLAGS= -Wall -g
CC= gcc

objs = main.o utilities.o playCrap.o turtleGraphics.o knightsTour.o eightQueens.o \
		recursiveFunctions.o poker.o maxSubSeq.o

main: $(objs) defs.h
	$(CC) $(CFLAGS) $(objs) -o main

main.o:  defs.h

utilities.o:  utilities.h

playCrap.o: playCrap.h

turtleGraphics.o: turtleGraphics.h

knightsTour.o : knightsTour.h

recursiveFunctions.o : recursiveFunctions.h

poker.o: poker.h

maxSubSeq.o: maxSubSeq.h

eightQueens.o : eightQueens.h knightsTour.h
	$(CC) $(CFLAGS) -c eightQueens.c knightsTour.c


.PHONY: clean
clean:
	rm -rf *.o main 

.PHONY: all
all: clean main


.PHONY: run
run:
	./main

.PHONY: run1
run1:
	./main > output.txt

.PHONY: run2
run2:
	./main >> output.txt
