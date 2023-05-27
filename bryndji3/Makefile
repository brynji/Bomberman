CXX=g++
CFLAGS=-Wall -pedantic

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

all: bryndji3

bryndji3: $(OBJS)
	$(CXX) $(CFLAGS) -o  $@ $(OBJS)  -fsanitize=address -lncurses

run: bryndji3
	./bryndji3

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o  $@ $<

clean:
	rm -rf src/*.o
	rm -rf bryndji3

deps:
	$(CXX) -MM src/*.cpp > Makefile.d


-include Makefile.d
