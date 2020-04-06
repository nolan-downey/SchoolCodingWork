# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 08

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
08 := ~/DSInClass/08-Templates



# Template Specialization - from HackerRank
# Command: make matrix
matrixObjs :=  $(08)/matrix.o

matrix: $(matrixObjs) 
	$(PP) $(CXXFLAGS) -o $(08)/matrix $(matrixObjs)

matrix.o: $(08)/matrix.cpp $(08)/AddElements.h
	$(PP) $(CXXFLAGS) -c $(08)/matrix.cpp	



# Testing Shell Executable for matrix 
# Command: make testMatrix 
testMatrix:
	make matrix 
	chmod +x matrix.sh
	./matrix.sh


	
# Make all
all: matrix

# Make clean
clean :
	rm -rf *.o matrix

reset:
	make clean
	cp ~/DSReset/08-Templates/matrix.cpp .
	chmod 777 *
	chmod 777 $(08)
