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

