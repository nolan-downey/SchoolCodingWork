# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 19

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
19 := ~/DSInClass/19-DLList
CLASSES := $(19)/classes
PROG := $(19)/programs
EXE := $(19)/executables
OBJECTS := $(19)/objects


# Command: make DLLTest
# Doubly Linked List Class Example with int
DLLTestObjs :=  $(OBJECTS)/DLLTest.o

DLLTest: $(DLLTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLTest $(DLLTestObjs)
	$(EXE)/./DLLTest 10 25 12 10 44 88

$(OBJECTS)/DLLTest.o: $(PROG)/DLLTest.cpp $(CLASSES)/DLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/DLLTest.cpp -o $@
	
	
	
# Command: make DLLTest2
# Doubly Linked List Class Example with std::string
DLLTest2Objs :=  $(OBJECTS)/DLLTest2.o

DLLTest2: $(DLLTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLTest2 $(DLLTest2Objs)
	$(EXE)/./DLLTest2

$(OBJECTS)/DLLTest2.o: $(PROG)/DLLTest2.cpp $(CLASSES)/DLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/DLLTest2.cpp -o $@



# Make all
all: DLLTest DLLTest2

# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
	
# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	

# Make gitPre
gitPre :
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 19 Preview Assignment"
	git push

	
# Make gitIn
gitIn :
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 19 In Class"
	git push



# Make startClass
startClass :
	make clean
	cp ~/DSSols/19-DLList/DLList_class.h $(CLASSES)/DLList.h
	chmod go+rx $(CLASSES)/*

# Make reset
reset :
	make clean
	cp -rf ~/DSReset/19-DLList/classes .
	chmod go+rx $(CLASSES)/*
	chmod go+rx $(PROG)/*
	chmod go+rx $(19)/*
	chmod go+rx $(19)
