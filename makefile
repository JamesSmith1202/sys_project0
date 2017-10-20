run: all
	./run

all: linkedlist.o song_arr.o main.o
	gcc -o run linkedlist.o song_arr.o main.o

main.o: main.c headers.h
	gcc -c main.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

song_arr.o: song_arr.c
	gcc -c song_arr.c

clean:
	rm -f *.o
	rm -f *~
	rm run
