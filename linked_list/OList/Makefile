main: main.o OList.o Node.o
	g++ -o main main.o OList.o Node.o

main.o: main.cpp OList.h
	g++ -c main.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o
