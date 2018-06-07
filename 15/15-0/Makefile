all: picture

clean: 
	rm *.o picture

main.o: main.cpp	pic.h student_info.hpp
	g++ -c main.cpp

core.o: core.cpp 	core.h grade.h
	g++ -c core.cpp

grade.o: grade.cpp	grade.h
	g++ -c grade.cpp

pic.o: pic.cpp		pic.h
	g++ -c  pic.cpp

#student_info.o: student_info.hpp	ptr.hppa
#	g++ -c -o student_info.o student_info.hpp
# g++ -c -o pic.o pic.cpp      
# -o pic.o is not neccesary
picture: main.o core.o grade.o pic.o
	g++ main.o core.o grade.o pic.o  -o picture
# here with out -o the result will be a.out
