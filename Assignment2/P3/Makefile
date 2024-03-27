random.o: random.h random.cpp
	g++ -c random.cpp -o random.o

main3.o: random.h main3.cpp
	g++ -c main3.cpp -o main3.o

main3: random.o main3.o
	g++ random.o main3.o -o main3

test: main3
	./main3

clean: 
	rm random.o main3.o main3

.PHONY: test clean
