NAME=caro
NAME1=gcaro
NAME2=gcaro2
CFLAGS=-g -Wall -o $(NAME)
CFLAGS1=-g -Wall -o $(NAME1)
CFLAGS2=-g -Wall -o $(NAME2)
GTKFLAGS=-export-dynamic `pkg-config --cflags --libs gtk+-3.0`
SRCS=caro.c
SRCS1=gcaro.c
SRCS2=gcaro2.c
CC=gcc

# top-level rule to create the program.
all: caro gcaro gcaro2

# compiling the source file.
caro: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)	
	
gcaro: $(SRCS1)
	$(CC) $(CFLAGS1) $(SRCS1) $(GTKFLAGS)	

gcaro2: $(SRCS2)
	$(CC) $(CFLAGS2) $(SRCS2) $(GTKFLAGS)

# cleaning everything that can be automatically recreated with "make".
BINARIES=$(NAME) $(NAME1) $(NAME2)

.PHONY: clean

clean:
	rm -rf $(BINARIES)
