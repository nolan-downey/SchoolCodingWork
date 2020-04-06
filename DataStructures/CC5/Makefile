# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
CC5 := ~/DSInClass/CC5
CLASSES := $(CC5)/classes
PROG := $(CC5)/programs
OBJECTS := $(CC5)/objects
EXE := $(CC5)/executables



# Rotations
# Command: make CC5
CC5Objs :=  $(OBJECTS)/CC5.o

CC5: $(CC5Objs) 
	$(PP) $(CXXFLAGS) -o $(EXE)/CC5 $(CC5Objs)
	$(EXE)/./CC5

$(OBJECTS)/CC5.o: $(PROG)/CC5.cpp  $(CLASSES)/BSTNode.h
	$(PP) $(CXXFLAGS) -c $(PROG)/CC5.cpp -o $@	

	
	
#Make all
all: CC5


# Make clean
clean :
	rm -rf $(OBJECTS)/* $(EXE)/* 
