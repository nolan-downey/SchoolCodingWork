# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 07
# 
# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)



# Variables for Folders
07 := ~/DSInClass/07-Recursion

# Calculating the sin of a value
# Command: make sine
sineObjs := $(07)/sine.o

sine: $(sineObjs)
	$(PP) $(CXXFLAGS) -o sine $(sineObjs)

sine.o: $(07)/sine.cpp
	$(PP) $(CXXFLAGS) -c $(07)/sine.cpp


# Sorting using recursion
# Teaching the students MergeSort
# Command: make sort
sortObjs := $(07)/sort.o

sort: $(sortObjs)
	$(PP) $(CXXFLAGS) -o sort $(sortObjs)

sort.o: $(07)/sort.cpp
	$(PP) $(CXXFLAGS) -c $(07)/sort.cpp


# Make all
all: sort sine

# Make clean
clean :
	rm -rf *.o sine sort
	
	
# Make reset to reset for next lecture
# Do not use
reset:
	make clean
	cp ~/DSReset/07-Recursion/sine.cpp .
	cp ~/DSReset/07-Recursion/sort.cpp .
	cp ~/DSReset/07-Recursion/Answers07.txt .
	chmod 777 *
	chmod 777 ../07-Recursion
