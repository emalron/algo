CC=g++
OBJS=town.o person.o
TARGET=app.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

town.o: person.hpp town.cpp
person.o: person.hpp person.cpp