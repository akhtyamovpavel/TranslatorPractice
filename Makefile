all: regex

regex: main.o IntWithInfinity.o
	g++ -std=c++11 main.o IntWithInfinity.o -o regex

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

IntWithInfinity.o: IntWithInfinity.cpp
	g++ -std=c++11 -c IntWithInfinity.cpp 

clean:
	rm -rf *.o regex