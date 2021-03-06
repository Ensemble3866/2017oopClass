all: hw8 shell

hw8: mainTest.o term.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainTest.o term.o list.o struct.o -lgtest
else
	g++ -o hw8 mainTest.o term.o list.o struct.o -lgtest -lpthread
endif

shell: shell.o term.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o term.o list.o struct.o -lgtest
else
	g++ -o shell shell.o term.o list.o struct.o -lgtest -lpthread
endif

shell.o: shell.cpp parser.h scanner.h
	g++ -std=gnu++0x -c shell.cpp
mainTest.o: mainTest.cpp atom.h exp.h iterator.h list.h parser.h scanner.h struct.h term.h variable.h utAtom.h utIterator.h utList.h utParser.h utScanner.h utStruct.h utVariable.h expression.h exception.h
	g++ -std=gnu++0x -c mainTest.cpp
	
term.o: term.cpp term.h variable.h
	g++ -std=c++11 -c term.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=c++11 -c struct.cpp
clean:
	rm -f *.o hw8 shell
stat:
	wc *.h *.