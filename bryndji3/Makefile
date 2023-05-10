CXX=g++
CFLAGS=-Wall -pedantic

all: bryndji3

bryndji3: src/main.o src/GameMaster.o src/GameObject.o src/Wall.o src/Loader.o
	$(CXX) $(CFLAGS) -o  $@ $^

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
