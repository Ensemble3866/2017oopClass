all: hw4

hw4: mainTest.o atom.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainTest.o atom.o list.o -lgtest
else
	g++ -o hw4 mainTest.o atom.o list.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp
mainTest.o: mainTest.cpp atom.h variable.h struct.h list.h utTerm.h utVariable.h utStruct.h utList.h
	g++ -std=gnu++0x -c mainTest.cpp
list.o: list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
utScanner: mainScanner.o scanner.h utScanner.h
	g++ -o utScanner mainScanner.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h
		g++ -std=c++11 -c mainScanner.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif
stat:
	wc *.h *.cpp