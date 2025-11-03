CXX=g++
CXX_VERSION=-std=c++17

TARGET=kruskal

SRC=$(TARGET).cpp
BIN=$(TARGET).bin

all: build

build: $(SRC)
	$(CXX) $(CXX_VERSION) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)