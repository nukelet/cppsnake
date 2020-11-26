CXXFLAGS = -std=c++14
LDFLAGS = -lncurses

.PHONY: all clean

all: cppsnake

cppsnake:
	g++ $(CXXFLAGS) src/Snake.cpp src/Environment.cpp src/main.cpp -o cppsnake $(LDFLAGS)

clean:
	rm -f cppsnake
	rm -f src/*.o