# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
CC3 := ~/DSInClass/CC3
CLASSES := $(CC3)/classes
PROG := $(CC3)/programs
OBJECTS := $(CC3)/objects
EXE := $(CC3)/executables



# Rotations
# Command: make CC3
CC3Objs :=  $(OBJECTS)/CC3.o

CC3: $(CC3Objs) 
	$(PP) $(CXXFLAGS) -o $(EXE)/CC3 $(CC3Objs)
	$(EXE)/./CC3

$(OBJECTS)/CC3.o: $(PROG)/CC3.cpp $(CLASSES)/SLList.h 
	$(PP) $(CXXFLAGS) -c $(PROG)/CC3.cpp -o $@	

	
	
#Make all
all: CC3


# Make clean
clean :
	rm -rf $(OBJECTS)/* $(EXE)/* 
