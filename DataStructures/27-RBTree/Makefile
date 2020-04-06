# This is the Makefile for the CSE 20312 course Lecture 27

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
27 := ~/DSInClass/27-RBTree
CLASSES := $(27)/classes
PROG := $(27)/programs
EXE := $(27)/executables
OBJECTS := $(27)/objects


# Command: make RBTreeTest
# Shows a successful RBTree Tree Test
RBTreeTestObjs := $(OBJECTS)/RBTreeTest.o

RBTreeTest: $(RBTreeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RBTreeTest $(RBTreeTestObjs)
	$(EXE)/./RBTreeTest

$(OBJECTS)/RBTreeTest.o: $(PROG)/RBTreeTest.cpp $(CLASSES)/RBTree.h
	$(PP) $(CXXFLAGS) -c $(PROG)/RBTreeTest.cpp -o $@


# Make all
all: RBTreeTest


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 27 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 27 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 27 In Class - Fix"
	git push
