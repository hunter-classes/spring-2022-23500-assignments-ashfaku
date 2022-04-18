
main: main.o stack.o OList.o Node.o
	g++ -o main main.o stack.o OList.o Node.o

main.o: main.cpp stack.h
	g++ -c main.cpp

stack.o: stack.cpp stack.h
	g++ -c stack.cpp

OList.o: OList.cpp OList.h
	g++ -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f main.o stack.o
