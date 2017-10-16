linkedlist: linkedlist.c
	gcc -o run linkedlist.c

clean:
	rm -f *.o
	rm -f *~

run: linkedlist
	./run
