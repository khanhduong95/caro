NAME=caro
CFLAGS=-g -Wall -o $(NAME)
SRCS=caro.c
CC=gcc

# top-level rule to create the program.
all: main

# compiling the source file.
main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

# cleaning everything that can be automatically recreated with "make".
clean: /bin/rm -f $(NAME)
