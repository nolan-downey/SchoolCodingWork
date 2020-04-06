# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 12

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
12 := ~/DSInClass/12-Hashing
CLASSES := $(12)/classes
PROG := $(12)/programs
OBJECTS := $(12)/objects
EXE := $(12)/executables


# Command: make fibOld
# Fibonacci Recursive from Lecture 07
fibOldObjs :=  $(OBJECTS)/fibOld.o

fibOld: $(fibOldObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/fibOld $(fibOldObjs)
	$(EXE)/./fibOld 5

$(OBJECTS)/fibOld.o: $(PROG)/fibOld.cpp 
	$(PP) $(CXXFLAGS) -c $(PROG)/fibOld.cpp -o $@
	
	
	
# Command: make fibMemo
# Fibonacci Recursive using Memoization
fibMemoObjs :=  $(OBJECTS)/fibMemo.o

fibMemo: $(fibMemoObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/fibMemo $(fibMemoObjs)
	$(EXE)/./fibMemo 5

$(OBJECTS)/fibMemo.o: $(PROG)/fibMemo.cpp 
	$(PP) $(CXXFLAGS) -c $(PROG)/fibMemo.cpp -o $@
	
	
	
# Command: make childStepsOld
# Creativity Challenge 1 Solution
childStepsOldObjs :=  $(OBJECTS)/childStepsOld.o

childStepsOld: $(childStepsOldObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/childStepsOld $(childStepsOldObjs)
	$(EXE)/./childStepsOld 10

$(OBJECTS)/childStepsOld.o: $(PROG)/childStepsOld.cpp 
	$(PP) $(CXXFLAGS) -c $(PROG)/childStepsOld.cpp -o $@
	
	
	
# Command: make childStepsMemo
# Creativity Challenge 1 Solution with Memoization
childStepsMemoObjs :=  $(OBJECTS)/childStepsMemo.o

childStepsMemo: $(childStepsMemoObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/childStepsMemo $(childStepsMemoObjs)
	$(EXE)/./childStepsMemo 10
	$(EXE)/./childStepsMemo 100

$(OBJECTS)/childStepsMemo.o: $(PROG)/childStepsMemo.cpp 
	$(PP) $(CXXFLAGS) -c $(PROG)/childStepsMemo.cpp -o $@
	
	
	
	
# Command: make csMemoDouble
# Creativity Challenge 1 Solution with Memoization and Double
csMemoDoubleObjs :=  $(OBJECTS)/csMemoDouble.o

csMemoDouble: $(csMemoDoubleObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/csMemoDouble $(csMemoDoubleObjs)
	$(EXE)/./csMemoDouble 10

$(OBJECTS)/csMemoDouble.o: $(PROG)/csMemoDouble.cpp 
	$(PP) $(CXXFLAGS) -c $(PROG)/csMemoDouble.cpp -o $@
	
	
	
# Command: make strSort
# Sort a std::string using a Counting Sort Algorithm
strSortObjs :=  $(OBJECTS)/strSort.o

strSort: $(strSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/strSort $(strSortObjs)
	$(EXE)/./strSort supercalifragilisticexpialidocious
	$(EXE)/./strSort ^$#I-+[ad]]d_Djj6?824-LDHLH]\DHf-26ed=vb[n[57GsSgD]l-LFZz=+?

$(OBJECTS)/strSort.o: $(PROG)/strSort.cpp 
	$(PP) $(CXXFLAGS) -c $(PROG)/strSort.cpp -o $@

	

# Make all
all: fibOld fibMemo childStepsOld childStepsMemo csMemoDouble strSort


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Used to reset after each lecture by Dr. Morrison
reset:
	make clean
	chmod a+rx $(12)
