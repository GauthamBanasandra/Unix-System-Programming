a.out : 1_example.o MyComplex.o
	g++ 1_example.o MyComplex.o
1_example.o : 1_example.cpp MyComplex.h
	g++ -c -std=c++14 1_example.cpp

MyComplex.o : MyComplex.cpp MyComplex.h
	g++ -c -std=c++14 MyComplex.cpp

