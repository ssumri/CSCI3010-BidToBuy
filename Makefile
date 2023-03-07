CXX = g++  # the compiler
CXXFLAGS = -std=c++20 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!
#includes all the build files when compiling 

all: main

clean:
    rm -f main *.o

main: main.cpp
    $(CXX) $(CXXFLAGS) main.cpp -o main