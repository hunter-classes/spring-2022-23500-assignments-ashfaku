
main: main.o Node.o bstree.o
	g++ -o main main.o Node.o bstree.o

tests: tests.o Node.o
	g++ -o tests tests.o Node.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp Node.h
	g++ -c main.cpp

bstree.o: bstree.cpp bstree.h
	g++ -c bstree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o
