# Author: John Steele
# Date: January 19, 2011
# Used for CSS422 HW_3 IEEE754 program. 
CC=g++ 
CFLAGS=-Wall -g  
OBJS=main.o
PROG=Fexpand

#Link
all: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

#Compile
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS)

