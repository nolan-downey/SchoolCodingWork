# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 25

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
25 := ~/DSInClass/25-BTree
CLASSES := $(25)/classes
PROG := $(25)/programs
EXE := $(25)/executables
OBJECTS := $(25)/objects


# Command: make BTreeTest
# Shows a successful BTree Tree Test
BTreeTestObjs := $(OBJECTS)/BTreeTest.o

BTreeTest: $(BTreeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BTreeTest $(BTreeTestObjs)
	$(EXE)/./BTreeTest

$(OBJECTS)/BTreeTest.o: $(PROG)/BTreeTest.cpp $(CLASSES)/BTree.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BTreeTest.cpp -o $@




# Make all
all: BTreeTest


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 25 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 25 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 25 In Class - Fix"
	git push
