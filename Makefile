NAME=gcaro
CFLAGS=-g -Wall -o $(NAME)
GTKFLAGS=-export-dynamic `pkg-config --cflags --libs gtk+-3.0`
SRCS=gcaro.c
CC=gcc

# top-level rule to create the program.
all: main

# compiling the source file.
main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(GTKFLAGS)

# cleaning everything that can be automatically recreated with "make".
clean: /bin/rm -f $(NAME)
