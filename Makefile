# CC=gcc
CC=musl-gcc
CFLAGS=-c -Wall -O0 -g
LDFLAGS=-lm -lpthread
SOURCES=object.c bool.c vm.c ctx.c frame.c compiler.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=lambda

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)
