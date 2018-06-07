all: student

clean:
	rm *.o student

main.o: main.cpp  student_info.hpp
	g++ -c main.cpp

grade.o: grade.cpp grade.h
	g++ -c grade.cpp

core.o: core.cpp core.h grade.h
	g++ -c core.cpp

student: main.o grade.o core.o
	g++ main.o grade.o core.o -o student
