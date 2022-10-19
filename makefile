CC := g++
CFLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: main

entity: attack
	$(CC) $(CFLAGS) -o build/entity.o src/entity.cpp

attack: effect
	$(CC) $(CFLAGS) -o build/attack.o src/attack.cpp

effect: 
	$(CC) $(CFLAGS) -o build/effect.o src/effect.cpp

main:
	$(CC) $(CFLAGS) -o build/main.o src/main.cpp

	
clean:
	$(RM) -r $(BUILD)/* $(TARGET)