CFLAGS= -Wall -g
CC= gcc

objs = main.o utilities.o

main: $(objs) defs.h
	$(CC) $(CFLAGS) $(objs) -o main

 main.o:  defs.h

 utilities.o:  utilities.h

.PHONY: clean
clean:
	rm -rf *.o main 

.PHONY: all
all: clean main

.PHONY: run1
run1:
	./main	
