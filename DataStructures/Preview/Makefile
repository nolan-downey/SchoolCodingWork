# Author: Nolan Downey
# E-mail: ndowney@nd.edu
#
# This is the Makefile for the Preview Assignment 15

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
15 := ~/cse20312/15-Inheritance
CLASSES := $(15)/classes
PROG := $(15)/programs
OBJECTS := $(15)/objects
EXE := $(15)/executables


# Command: make AnimalTest
# Base class for First Inheritance Example
AnimalTestObjs := $(OBJECTS)/AnimalTest.o $(OBJECTS)/Animal.o

AnimalTest: $(AnimalTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/AnimalTest $(AnimalTestObjs)
	$(EXE)/./AnimalTest

$(OBJECTS)/AnimalTest.o: $(PROG)/AnimalTest.cpp $(CLASSES)/Animal.h
	$(PP) $(CXXFLAGS) -c $(PROG)/AnimalTest.cpp -o $@

$(OBJECTS)/Animal.o: $(CLASSES)/Animal.cpp $(CLASSES)/Animal.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Animal.cpp -o $@



# Command: make Inherit
# Derived Classes for First Inheritance Example
InheritObjs := $(OBJECTS)/Inherit.o $(OBJECTS)/Cat.o $(OBJECTS)Dog.o $(OBJECTS)/Rhino.o $(OBJECTS)Walrus.o $(OBJECTS)/Wild.o $(OBJECTS)/Pet.o $(OBJECTS)/Animal.o

Inherit: $(InheritObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Inherit $(InheritObjs)
	$(EXE)/./Inherit

# Inherit.cpp class both derived classes
$(OBJECTS)/Inherit.o: $(PROG)/Inherit.cpp $(CLASSES)/Pet.h $(CLASSES)/Wild.h $(CLASSES)/Cat.h $(CLASSES) Dog.h $(CLASSES)/Rhino.h $(CLASSES)/Walrus.h
	$(PP) $(CXXFLAGS) -c $(PROG)/Inherit.cpp -o $@

# Wild inherits Animal
$(OBJECTS)/Wild.o: $(CLASSES)/Wild.cpp $(CLASSES)/Wild.h $(CLASSES)/Animal.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Wild.cpp -o $@

# Pet inherits Animal
$(OBJECTS)/Pet.o: $(CLASSES)/Pet.cpp $(CLASSES)/Pet.h $(CLASSES)/Animal.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Pet.cpp -o $@

# Cat Inherits Pet
$(OBJECTS)/Cat.o: $(CLASSES)/Cat.cpp $(CLASSES)/Cat.h $(CLASSES)/Pet.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Cat.cpp -o $@

# Dog Inherits Pet
$(OBJECTS)/Dog.o: $(CLASSES)/Dog.cpp $(CLASSES)/Dog.h $(CLASSES)/Pet.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Dog.cpp -o $@

# Rhino Inherits Wild
$(OBJECTS)/Rhino.o: $(CLASSES)/Rhino.cpp $(CLASSES)/Rhino.h $(CLASSES)/Wild.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Rhino.cpp -o $@

# Walrus Inherits Wild
$(OBJECTS)/Walrus.o: $(CLASSES)/Walrus.cpp $(CLASSES)/Walrus.h $(CLASSES)/Wild.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Walrus.cpp -o $@



# Make all
all: AnimalTest Inherit

# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
