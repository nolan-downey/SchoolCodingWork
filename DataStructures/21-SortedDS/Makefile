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
21 := ~/DSInClass/21-SortedDS
CLASSES := $(21)/classes
PROG := $(21)/programs
EXE := $(21)/executables
OBJECTS := $(21)/objects


# Command: make SortedDynArrTest
# Shows a successful Sorted Dynamic Array
SortedDynArrTestObjs := $(OBJECTS)/SortedDynArrTest.o

SortedDynArrTest: $(SortedDynArrTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SortedDynArrTest $(SortedDynArrTestObjs)
	$(EXE)/./SortedDynArrTest

$(OBJECTS)/SortedDynArrTest.o: $(PROG)/SortedDynArrTest.cpp $(CLASSES)/SorDynArr.h $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/SortedDynArrTest.cpp -o $@



# Command: make BadDynArrTest
# Shows Bad Sorted Dynamic Array with bad ++ use
# Contains a deliberate segmentation fault
BadDynArrTestObjs := $(OBJECTS)/BadDynArrTest.o

BadDynArrTest: $(BadDynArrTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BadDynArrTest $(BadDynArrTestObjs)
	$(EXE)/./BadDynArrTest

$(OBJECTS)/BadDynArrTest.o: $(PROG)/BadDynArrTest.cpp $(CLASSES)/SorDynArrBad.h $(CLASSES)/DynArrBad.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BadDynArrTest.cpp -o $@
	
	
	
	# Command: make SortedSLLTest
# Shows a successful Sorted Dynamic Array
SortedSLLTestObjs := $(OBJECTS)/SortedSLLTest.o

SortedSLLTest: $(SortedSLLTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SortedSLLTest $(SortedSLLTestObjs)
	$(EXE)/./SortedSLLTest

$(OBJECTS)/SortedSLLTest.o: $(PROG)/SortedSLLTest.cpp $(CLASSES)/SortedSLL.h $(CLASSES)/SLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/SortedSLLTest.cpp -o $@


	


# Command: make SortedComp
# Comparison of Sorted Singly Linked List and Sorted Dynamic Array
SortedCompObjs := $(OBJECTS)/SortedComp.o

SortedComp: $(SortedCompObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SortedComp $(SortedCompObjs)

$(OBJECTS)/SortedComp.o: $(PROG)/SortedComp.cpp $(CLASSES)/SortedSLL.h $(CLASSES)/SorDynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/SortedComp.cpp -o $@



# Command: make BucketSortDyn
# Example of BucketSort using our SorDynArr
BucketSortDynObjs := $(OBJECTS)/BucketSortDyn.o

BucketSortDyn: $(BucketSortDynObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BucketSortDyn $(BucketSortDynObjs)
	$(EXE)/./BucketSortDyn

$(OBJECTS)/BucketSortDyn.o: $(PROG)/BucketSortDyn.cpp $(CLASSES)/SortedSLL.h $(CLASSES)/SLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BucketSortDyn.cpp -o $@
	
	
	
	
	
# Command: make BucketSortSLL
# Example of BucketSort using our SortedSLL
BucketSortSLLObjs := $(OBJECTS)/BucketSortSLL.o

BucketSortSLL: $(BucketSortSLLObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BucketSortSLL $(BucketSortSLLObjs)
	$(EXE)/./BucketSortSLL

$(OBJECTS)/BucketSortSLL.o: $(PROG)/BucketSortSLL.cpp $(CLASSES)/SortedSLL.h $(CLASSES)/SLList.h
	$(PP) $(CXXFLAGS) -c $(PROG)/BucketSortSLL.cpp -o $@
	
	
	
	
# Testing Sorting Results using Shell Script
# Command: make testHello 
testSort:
	make SortedComp 
	chmod +x testSort.sh
	./testSort.sh


# Make all
all: SortedDynArrTest BadDynArrTest SortedSLLTest SortedComp BucketSortDyn BucketSortSLL


# Make gitPre
gitPre :
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 21 Preview Assignment"
	git push

	
# Make gitIn
gitIn :
	make clean
	git add Makefile $(CLASSES)/* $(PROG)/*
	git commit -m "Lecture 21 In Class"
	git push
	
	
# Make gitIn
gitFix :
	make clean
	git add --all
	git commit -m "Lecture 21 In Class - Fix"
	git push


# Make reset
reset :
	make clean
	# cp -rf ~/DSReset/18-SLList/classes .
	chmod go+rx $(CLASSES)/*
	chmod go+rx $(PROG)/*
	chmod go+rx $(21)/*
	chmod go+rx $(21)
	

# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
