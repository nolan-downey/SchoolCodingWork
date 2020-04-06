# This is the Makefile for the CSE 20312 course Lecture 28

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
28 := ~/DSInClass/28-RBTree
CLASSES := $(28)/classes
PROG := $(28)/programs
EXE := $(28)/executables
OBJECTS := $(28)/objects


# Command: make RBDelTest
# Shows a successful RBTree Tree Test
RBDelTestObjs := $(OBJECTS)/RBDelTest.o

RBDelTest: $(RBDelTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RBDelTest $(RBDelTestObjs)
	$(EXE)/./RBDelTest

$(OBJECTS)/RBDelTest.o: $(PROG)/RBDelTest.cpp $(CLASSES)/RBTree.h
	$(PP) $(CXXFLAGS) -c $(PROG)/RBDelTest.cpp -o $@


# Command: make treeTest
# Shows a successful RBTree Tree Test
treeTestObjs := $(OBJECTS)/treeTest.o

treeTest: $(treeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/treeTest $(treeTestObjs)
	$(EXE)/./treeTest

$(OBJECTS)/treeTest.o: $(PROG)/treeTest.cpp
	$(PP) $(CXXFLAGS) -c $(PROG)/treeTest.cpp -o $@



# Command: make multiSet
# Shows a successful RBTree Tree Test
multiSetObjs := $(OBJECTS)/multiSet.o

multiSet: $(multiSetObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/multiSet $(multiSetObjs)
	$(EXE)/./multiSet

$(OBJECTS)/multiSet.o: $(PROG)/multiSet.cpp
	$(PP) $(CXXFLAGS) -c $(PROG)/multiSet.cpp -o $@
	

# Make all
all: RBDelTest treeTest multiSet


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 28 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 28 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 28 In Class - Fix"
	git push
