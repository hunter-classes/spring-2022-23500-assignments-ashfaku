main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o

main.o: main.cpp List.h
	g++ -c main.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o
