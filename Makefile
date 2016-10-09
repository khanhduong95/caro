SRCS := caro_check.c caro_AI.c
OBJS := ${SRCS:.c=.o}
CFLAGS=-g -Wall -c
GTKFLAGS=-export-dynamic `pkg-config --cflags --libs gtk+-3.0`
CC=gcc

# top-level rule to create the program.
all: caro caro2

# compiling the source file.
caro: caro.o $(OBJS)
	$(CC) -g -o caro caro.o $(OBJS) $(GTKFLAGS)

caro2: caro2.o $(OBJS)
	$(CC) -g -o caro2 caro2.o $(OBJS) $(GTKFLAGS)

caro.o: caro.c
	$(CC) $(CFLAGS) caro.c $(GTKFLAGS)

caro2.o: caro2.c
	$(CC) $(CFLAGS) caro2.c $(GTKFLAGS)

caro_check.o: caro_check.c
	$(CC) $(CFLAGS) caro_check.c $(GTKFLAGS)

caro_AI.o: caro_AI.c
	$(CC) $(CFLAGS) caro_AI.c $(GTKFLAGS)

# cleaning everything that can be automatically recreated with "make".
BINARIES=caro caro2

.PHONY: clean

clean:
	rm -rf $(BINARIES) *.o
