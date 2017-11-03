all: hw5

hw5: mainTest.o term.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainTest.o term.o list.o -lgtest
else
	g++ -o hw5 mainTest.o term.o list.o -lgtest -lpthread
endif

term.o: term.cpp term.h
	g++ -std=c++11 -c term.cpp
mainTest.o: mainTest.cpp atom.h number.h variable.h struct.h list.h term.h parser.h scanner.h utTerm.h utVariable.h utStruct.h utList.h utParser.h
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
	rm -f *.o hw5
endif
stat:
	wc *.h *.cpp