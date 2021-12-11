OBJS = main.o instructionbuilder.o listbuilder.o utilities.o
SOURCE = main.c instructionbuilder.c listbuilder.c utilities.c
HEADER = instructionbuilder.h listbuilder.h utilities.h
OUT	= a.out
CC = gcc
FLAGS = -g -c
LFLAGS = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

instructionbuilder.o: instructionbuilder.c
	$(CC) $(FLAGS) instructionbuilder.c 

listbuilder.o: listbuilder.c
	$(CC) $(FLAGS) listbuilder.c 

utilities.o: utilities.c
	$(CC) $(FLAGS) utilities.c 


clean:
	rm -f $(OBJS) $(OUT)