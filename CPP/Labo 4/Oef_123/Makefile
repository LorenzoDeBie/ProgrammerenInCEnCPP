CXX = g++
CXXFLAGS = -pedantic -std=c++14 -static-libgcc

BIN = main.exe
OBJ = Oef_123.o
DEPS = ./../../headers/containers.h

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all: $(OBJ)
	$(CXX) -o $(BIN) $^ $(CXXFLAGS)