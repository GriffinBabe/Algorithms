CC = g++
LDFLAGS =
CFLAGS = -std=c++17 -Wall
EXEC = string_search.exe

main: string_search.o string_load.o my_string.o main.o
	$(CC) -o $(EXEC) main.o string_load.o string_search.o my_string.o $(LDFLAGS)

main.o: main.cpp
	$(CC) -o main.o -c main.cpp $(CFLAGS)

string_search.o: string_search.h
	$(CC) -o string_search.o -c string_search.cpp $(CFLAGS)

string_load.o: string_load.h
	$(CC) -o string_load.o -c string_load.cpp $(CFLAGS)

my_string.o: my_string.h
	$(CC) -o my_string.o -c my_string.cpp $(CFLAGS)

clean:
	del *.o $(EXEC)
