all : 5-1

clean : 
	rm *.o 5-1

main.o : main.cpp str.h rotate.h
	g++ -c main.cpp

rotate.o : rotate.cpp rotate.h str.h
	g++ -c rotate.cpp

str.o : str.cpp str.h
	g++ -c str.cpp

5-1 : main.o rotate.o str.o
	g++ main.o rotate.o str.o -o 5-1
