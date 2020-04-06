# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 13 In Class

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
13 := ~/DSInClass/13-HashIntro
CLASSES := $(13)/classes
PROG := $(13)/programs
OBJECTS := $(13)/objects
EXE := $(13)/executables


# Command: make LPTest
# First test of Linear Probe Hashing
LPTestObjs := $(OBJECTS)/LPTest.o

LPTest: $(LPTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest $(LPTestObjs)
	$(EXE)/./LPTest

$(OBJECTS)/LPTest.o: $(PROG)/LPTest.cpp $(CLASSES)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(PROG)/LPTest.cpp -o $@
	
	

# Command: make ageHash
# Compilation which shows issues with std::unordered_map
ageHashObjs := $(OBJECTS)/ageHash.o

ageHash: $(ageHashObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ageHash $(ageHashObjs)
	$(EXE)/./ageHash

$(OBJECTS)/ageHash.o: $(PROG)/ageHash.cpp
	$(PP) $(CXXFLAGS) -c $(PROG)/ageHash.cpp -o $@



# Command: make sepChain
# Compilation which shows issues with std::unordered_map and operator[]
# Contains a deliberate compiler error
sepChainObjs := $(OBJECTS)/sepChain.o

sepChain: $(sepChainObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sepChain $(sepChainObjs)
	$(EXE)/./sepChain

$(OBJECTS)/sepChain.o: $(PROG)/sepChain.cpp
	$(PP) $(CXXFLAGS) -c $(PROG)/sepChain.cpp -o $@	
	

# Make all
all: LPTest ageHash


# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*


# Resets the program for Lectures. Requires access to ND Machines
# Do not use this command unless you know exactly what you are doing
reset:
	chmod go+x $(13)
