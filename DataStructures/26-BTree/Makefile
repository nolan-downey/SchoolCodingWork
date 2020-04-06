# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
26 := ~/DSInClass/26-BTree
CLASSES := $(26)/classes
PROG := $(26)/programs
EXE := $(26)/executables
OBJECTS := $(26)/objects


# Command: make BTreeInClass
# Shows a successful BTree Tree Test
BTreeInClassObjs := $(OBJECTS)/BTreeInClass.o

BTreeInClass: $(BTreeInClassObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BTreeInClass $(BTreeInClassObjs)
	$(EXE)/./BTreeInClass

$(OBJECTS)/BTreeInClass.o: $(PROG)/BTreeInClass.cpp $(CLASSES)/BTree.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BTreeInClass.cpp -o $@
	

# Command: make BTreeTest
# Shows a successful BTree Tree Test
BTreeTestObjs := $(OBJECTS)/BTreeTest.o

BTreeTest: $(BTreeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BTreeTest $(BTreeTestObjs)
	$(EXE)/./BTreeTest

$(OBJECTS)/BTreeTest.o: $(PROG)/BTreeTest.cpp $(CLASSES)/BTree.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BTreeTest.cpp -o $@



# Command: make StudentDB
# Simple Student Database Example
StudentDBObjs := $(OBJECTS)/StudentDB.o $(OBJECTS)/Student.o

StudentDB: $(StudentDBObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/StudentDB $(StudentDBObjs)
	$(EXE)/./StudentDB $(26)/Students.csv

$(OBJECTS)/StudentDB.o: $(PROG)/StudentDB.cpp $(CLASSES)/BTree.h $(CLASSES)/Student.h
	$(PP) $(CXXFLAGS) -c $(PROG)/StudentDB.cpp -o $@
	
$(OBJECTS)/Student.o: $(CLASSES)/Student.cpp $(CLASSES)/Student.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Student.cpp -o $@


# Make all
all: BTreeTest


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 26 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 26 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 26 In Class - Fix"
	git push
