CC=gcc
OBJ=-c
CC_FLAGS=-Wall

TARGET=main

SOURCES=main.c \
		src/list.c \
		src/str.c

OBJECTS=main.o \
		list.o \
		str.o

target: $(SOURCES)
	$(CC) $(OBJ) $(SOURCES) $(CC_FLAGS)
	$(CC) $(OBJECTS) -o $(TARGET)

clean:
	rm $(OBJECTS)
	rm $(TARGET)
