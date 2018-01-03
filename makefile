all: hw8

hw8: mainTest.o atom.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainTest.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 mainTest.o atom.o list.o struct.o -lgtest -lpthread
endif

mainTest.o: mainTest.cpp atom.h exp.h iterator.h list.h parser.h scanner.h struct.h variable.h utAtom.h utIterator.h utList.h utParser.h utScanner.h utStruct.h utVariable.h expression.h exception.h
	g++ -std=gnu++0x -c mainTest.cpp
	
atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=c++11 -c struct.cpp
clean:
	rm -f *.o hw8
stat:
	wc *.h *.