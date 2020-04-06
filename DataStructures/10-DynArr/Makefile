# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 10

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
10 := ~/DSInClass/10-DynArr
OBJECTS := ~/DSInClass/10-DynArr/objects
CLASSES := ~/DSInClass/10-DynArr/classes
PROG := ~/DSInClass/10-DynArr/programs
EXE := ~/DSInClass/10-DynArr/executables

	


# Command: make DynArrTest
# Initial Abstract Data Type class

DynArrTestObjs := $(OBJECTS)/DynArrTest.o

DynArrTest: $(DynArrTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DynArrTest $(DynArrTestObjs)
	$(EXE)/./DynArrTest

$(OBJECTS)/DynArrTest.o: $(PROG)/DynArrTest.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/DynArrTest.cpp -o $@



# Make all
all: DynArrTest

# Make clean
clean :
	rm -rf objects/* executables/*
	

# Used to reset after each lecture by Dr. Morrison
reset:
	make clean
	cp -rf ~/DSReset/10-DynArr/* .
	chmod 777 *
	chmod 777 $(PROG)/*
	chmod 777 $(CLASSES)/*
	chmod 777 $(10)
