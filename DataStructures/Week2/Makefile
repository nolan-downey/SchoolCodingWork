# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 04

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
04 := ~/DSInClass/Week2

# Compilation for the "nothing" program
# Command: make nothing
nothingObjs :=  $(04)/nothing.o

nothing: $(04)/nothing.o 
	$(PP) $(CXXFLAGS) -o $(04)/nothing $(nothingObjs)

nothing.o: $(04)/nothing.cpp 
	$(PP) $(CXXFLAGS) -c $(04)/nothing.cpp



# C++ Hello, World Example
# Command: make hello
helloObjs :=  $(04)/hello.o

hello: $(04)/hello.o 
	$(PP) $(CXXFLAGS) -o $(04)/hello $(helloObjs)

hello.o: $(04)/hello.cpp 
	$(PP) $(CXXFLAGS) -c $(04)/hello.cpp
	
	
	
# Prints examples of ASCII char to terminal
# Command: make ascii
asciiObjects := $(04)/ascii.o

ascii: $(asciiObjects)
	$(PP) $(CXXFLAGS) -o $(04)/ascii $(asciiObjects)
	
ascii.o: $(04)/ascii.cpp
	$(PP) $(CXXFLAGS) -c $(04)/ascii.cpp
	
	
	
# Make all
all: nothing hello ascii

# Make clean
clean :
	rm -rf *.o nothing hello ascii
