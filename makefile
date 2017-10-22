all: hw4

hw4: mainTest.o number.o variable.o constant.o atom.o term.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainTest.o number.o atom.o constant.o variable.o term.o struct.o list.o -lgtest
else
	g++ -o hw4 mainTest.o number.o atom.o constant.o variable.o term.o struct.o list.o -lgtest -lpthread
endif

mainTest.o: mainTest.cpp number.h atom.h constant.h variable.h term.h struct.h list.h utTerm.h utVariable.h utStruct.h utList.h
	g++ -std=gnu++0x -c mainTest.cpp
list.o: list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o: struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp
term.o: term.cpp term.h
	g++ -std=gnu++0x -c term.cpp
variable.o: variable.cpp variable.h
	g++ -std=gnu++0x -c variable.cpp
constant.o: constant.cpp constant.h
	g++ -std=gnu++0x -c constant.cpp
number.o: number.cpp number.h
	g++ -std=gnu++0x -c number.cpp
atom.o: atom.cpp atom.h
	g++ -std=gnu++0x -c atom.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif
stat:
	wc *.h *.cpp