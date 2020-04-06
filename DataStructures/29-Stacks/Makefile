# This is the Makefile for the CSE 20312 course Lecture 29

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
29 := ~/DSInClass/29-Stacks
CLASSES := $(29)/classes
PROG := $(29)/programs
EXE := $(29)/executables
OBJECTS := $(29)/objects


# Command: make wrapper
# Tests the wrapper class
wrapperObjs := $(OBJECTS)/wrapper.o

wrapper: $(wrapperObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/wrapper $(wrapperObjs)
	$(EXE)/./wrapper

$(OBJECTS)/wrapper.o: $(PROG)/wrapper.cpp $(CLASSES)/stack.h
	$(PP) $(CXXFLAGS) -c $(PROG)/wrapper.cpp -o $@


# Command: make Stanislaus
# Tests the Stanislaus simulator
StanislausObjs := $(OBJECTS)/Stanislaus.o

Stanislaus: $(StanislausObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Stanislaus $(StanislausObjs)
	$(EXE)/./Stanislaus

$(OBJECTS)/Stanislaus.o: $(PROG)/Stanislaus.cpp $(CLASSES)/Stanislaus.h
	$(PP) $(CXXFLAGS) -c $(PROG)/Stanislaus.cpp -o $@



# Command: make hanoi
# Towers of Hanoi solution using 
# std::stack and recursion
hanoiObjs :=  $(OBJECTS)/hanoi.o

hanoi: $(hanoiObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/hanoi $(hanoiObjs)
	$(EXE)/./hanoi 3
	$(EXE)/./hanoi 4

$(OBJECTS)/hanoi.o: $(PROG)/hanoi.cpp $(CLASSES)/Tower.h
	$(PP) $(CXXFLAGS) -c $(PROG)/hanoi.cpp -o $@	
	

# Make all
all: wrapper Stanislaus hanoi


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 29 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 29 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 29 In Class - Fix"
	git push
