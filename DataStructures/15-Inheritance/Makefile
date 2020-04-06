# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 15

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
15 := ~/DSInClass/15-Inheritance
CLASSES := $(15)/classes
PROG := $(15)/programs
OBJECTS := $(15)/objects
EXE := $(15)/executables



# Command: make DoubleTest
# Test of making a Double Hashing Table which inherits Linear Probe
DoubleTestObjs := $(OBJECTS)/DoubleTest.o 

DoubleTest: $(DoubleTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DoubleTest $(DoubleTestObjs)
	$(EXE)/./DoubleTest
	
$(OBJECTS)/DoubleTest.o: $(PROG)/DoubleTest.cpp $(CLASSES)/DoubleHash.h $(CLASSES)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(PROG)/DoubleTest.cpp -o $@
	


# Make all
all: DoubleTest

# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make git
git :
	make clean
	git add $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 15 In Class"
	git push


# Make reset
reset :
	make clean
	cp -rf ~/DSReset/15-Inheritance/classes .
	chmod go+rx $(CLASSES)/*
	chmod go+rx $(PROG)/*
	chmod go+rx $(15)/*