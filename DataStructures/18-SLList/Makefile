# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 18

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
18 := ~/DSInClass/18-SLList
CLASSES := $(18)/classes
PROG := $(18)/programs
OBJECTS := $(18)/objects
EXE := $(18)/executables


# Command: make SLLTest
# A singly linked list test with ints
SLLTestObjs :=  $(OBJECTS)/SLLTest.o

SLLTest: $(SLLTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SLLTest $(SLLTestObjs)
	$(EXE)/./SLLTest 10 25 12 46 72 4 101 99

$(OBJECTS)/SLLTest.o: $(PROG)/SLLTest.cpp $(CLASSES)/SLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/SLLTest.cpp -o $@



# Command: make SLLTest2
# A singly linked list test with floats
SLLTest2Objs :=  $(OBJECTS)/SLLTest2.o

SLLTest2: $(SLLTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SLLTest2 $(SLLTest2Objs)
	$(EXE)/./SLLTest2

$(OBJECTS)/SLLTest2.o: $(PROG)/SLLTest2.cpp $(CLASSES)/SLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/SLLTest2.cpp -o $@
	


# Make all
all: SLLTest SLLTest2

# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre :
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 18 Preview Assignment"
	git push

	
# Make gitIn
gitIn :
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 18 In Class"
	git push
	
	
# Make startClass
startClass :
	make clean
	cp ~/DSSols/18-SLList/classes/.SLList.h $(CLASSES)/SLList.h
	chmod go+rx $(CLASSES)/*


# Make reset
reset :
	make clean
	cp -rf ~/DSReset/18-SLList/classes .
	chmod go+rx $(CLASSES)/*
	chmod go+rx $(PROG)/*
	chmod go+rx $(18)/*
	chmod go+rx $(18)
