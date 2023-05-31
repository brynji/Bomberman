CXX=g++
CFLAGS=-Wall -pedantic -o2 -std=c++17 

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=build/%.o)

all: compile
compile: bryndji3

bryndji3: $(OBJS)
	$(CXX) $(CFLAGS) -o  $@ $(OBJS) -fsanitize=address -lncurses

run: bryndji3
	./bryndji3

build/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o  $@ $<

clean:
	rm -rf build
	rm -rf bryndji3

doc:
	doxygen Doxyfile

deps:
	$(CXX) -MM src/*.cpp > Makefile.d


-include Makefile.d
