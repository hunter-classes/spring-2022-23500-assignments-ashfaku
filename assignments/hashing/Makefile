main: main.o OList.o Node.o Person.o
	g++ -o main main.o OList.o Node.o Person.o

tests: tests.o OList.o Node.o Person.o
	g++ -o tests tests.o OList.o Node.o Person.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp OList.h
	g++ -c main.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -c OList.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Node.o: Node.cpp Node.h Person.h
	g++ -c Node.cpp

clean:
	rm -f *.o
