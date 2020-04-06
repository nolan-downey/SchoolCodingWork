# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 09

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
09 := ~/DSInClass/09-Classes



# Template Specialization - from HackerRank
# Command: make tempSpec
tempSpecObjs :=  $(09)/tempSpec.o

tempSpec: $(tempSpecObjs) 
	$(PP) $(CXXFLAGS) -o $(09)/tempSpec $(tempSpecObjs)

tempSpec.o: $(09)/tempSpec.cpp $(09)/AddElements.h
	$(PP) $(CXXFLAGS) -c $(09)/tempSpec.cpp	



# Testing Shell Executable for tempSpec 
# Command: make testTempSpec 
testTempSpec:
	make tempSpec 
	chmod +x tempSpec.sh
	./tempSpec.sh



	
# Make all
all: tempSpec


# Make clean
clean :
	rm -rf *.o tempSpec
	
	
# A command I am using in lecture to deliberate break the templated class	
breakCode :
	make clean
	cp ~/DSSols/09-Classes/AddElements_bad.h AddElements.h
	cp ~/DSSols/09-Classes/tempSpec_bad.cpp tempSpec.cpp
	make tempSpec


# Will fix and update the code after breaking the code 
fixCode :
	make clean
	cp ~/DSSols/09-Classes/AddElements.h AddElements.h
	cp ~/DSSols/09-Classes/tempSpec.cpp tempSpec.cpp
	make testTempSpec


reset:
	make clean
	cp ~/DSReset/09-Classes/AddElements.h .
	cp ~/DSReset/09-Classes/tempSpec.cpp .
	chmod 777 *
	chmod 777 $(09)
