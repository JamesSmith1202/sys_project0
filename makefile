run: all
	./run

all: linkedlist.o songarr.o main.o
	gcc -o run linkedlist.o songarr.o main.o

main.o: main.c headers.h
	gcc -c main.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

songarr.o: linkedlist.o songarr.c
	gcc -c songarr.c

clean:
	rm -f *.o
	rm -f *~
