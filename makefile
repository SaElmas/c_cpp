CFLAGS= -Wall -g
CC= gcc

objs = main.o utilities.o playCrap.o turtleGraphics.o knightsTour.o

main: $(objs) defs.h
	$(CC) $(CFLAGS) $(objs) -o main

 main.o:  defs.h

 utilities.o:  utilities.h

 playCrap.o: playCrap.h

 turtleGraphics.o: turtleGraphics.h

 knightsTour.o : knightsTour.h

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
