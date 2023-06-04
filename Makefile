HEADERS =

default: main

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Werror -Wpedantic

main: main.o
	gcc main.o -o main -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Werror -Wpedantic

clean:
	-rm -f main.o
	-rm -f main
