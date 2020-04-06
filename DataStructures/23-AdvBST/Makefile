# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 21

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
23 := ~/DSInClass/23-AdvBST
CLASSES := $(23)/classes
PROG := $(23)/programs
EXE := $(23)/executables
OBJECTS := $(23)/objects


# Command: make BSTTest
# Shows a successful Binary Search Tree
BSTTestObjs := $(OBJECTS)/BSTTest.o

BSTTest: $(BSTTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BSTTest $(BSTTestObjs)
	$(EXE)/./BSTTest

$(OBJECTS)/BSTTest.o: $(PROG)/BSTTest.cpp $(CLASSES)/BST.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BSTTest.cpp -o $@



# Command: make BSTTrav
# Shows a successful Binary Search Tree Traversals
BSTTravObjs := $(OBJECTS)/BSTTrav.o

BSTTrav: $(BSTTravObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BSTTrav $(BSTTravObjs)
	$(EXE)/./BSTTrav

$(OBJECTS)/BSTTrav.o: $(PROG)/BSTTrav.cpp $(CLASSES)/BST.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BSTTrav.cpp -o $@
	
	
	
# Command: make BSTHeight
# Finds the Height of the Tree
BSTHeightObjs := $(OBJECTS)/BSTHeight.o

BSTHeight: $(BSTHeightObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BSTHeight $(BSTHeightObjs)
	$(EXE)/./BSTHeight

$(OBJECTS)/BSTHeight.o: $(PROG)/BSTHeight.cpp $(CLASSES)/BST.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BSTHeight.cpp -o $@
	
	
	
# Command: make BSTDiam
# Finds the Diameter of the Tree
BSTDiamObjs := $(OBJECTS)/BSTDiam.o

BSTDiam: $(BSTDiamObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BSTDiam $(BSTDiamObjs)
	$(EXE)/./BSTDiam

$(OBJECTS)/BSTDiam.o: $(PROG)/BSTDiam.cpp $(CLASSES)/BST.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BSTDiam.cpp -o $@


# Make all
all: BSTTest BSTTrav BSTHeight BSTDiam


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 23 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 23 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 23 In Class - Fix"
	git push
