CXX=g++
CPPFLAGS=--std=c++17

all: testSorting
	./testSorting

testSorting: testSorting.o tdd.o sorting.o
	$(CXX) $(CPPFLAGS) -o testSorting testSorting.o tdd.o sorting.o

clean:
	/bin/rm -f testSorting sorting *.o