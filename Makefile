CXX=g++ 
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++11 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all: tsp

tsp: cities.o tsp.o
	$(CXX) -o $@ $^

%.o: %.cc %.hh
	$(CXX) -c -o $@ $<

clean:
	rm -rf *.o tsp

