CC = gcc
CFLAGS = -pedantic
CXX = g++
CXXFLAGS = -pedantic -std=c++14 -static-libgcc
DEPS = ./../../headers/containers.h

BIN = main.exe
OBJ = Oef_126.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all: $(OBJ)
	$(CXX) -o $(BIN) $^ $(CXXFLAGS)
