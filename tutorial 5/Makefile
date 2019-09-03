.default: all

all: testCopy

clean:
	rm -f testCopy *.o

testCopy: testCopy.o VideoCharacter.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
