#G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
CC2 := ~/DSInClass/CC2
CLASSES := $(CC2)/classes
PROG := $(CC2)/programs
OBJECTS := $(CC2)/objects
EXE := $(CC2)/executables



# Making the Playlist - CC2 Problem 1
# Command: make browser
browserObjs :=  $(OBJECTS)/browser.o $(OBJECTS)/Site.o

browser: $(browserObjs) 
	$(PP) $(CXXFLAGS) -o $(EXE)/browser $(browserObjs)

$(OBJECTS)/browser.o: $(PROG)/browser.cpp $(CLASSES)/Site.h
	$(PP) $(CXXFLAGS) -c $(PROG)/browser.cpp -o $@	

$(OBJECTS)/Site.o: $(CLASSES)/Site.cpp $(CLASSES)/Site.h
	$(PP) $(CXXFLAGS) -c $(CLASSES)/Site.cpp -o $@	
	
	
#Make all
all: browser


# make test
test:
	make browser
	$(EXE)/./browser $(PROG)/browser.txt


# Make clean
clean :
	rm -rf $(OBJECTS)/* $(EXE)/* 
