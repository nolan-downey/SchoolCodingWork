#G++ is for the GCC compiler for C++
PP := g++

# GCC is the compiler for C. Included for mallocBadC
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 
CFLAGS := -std=c11 $(FLAGS)



# Variables for Folders
06 := ~/DSInClass/06-Functions



# Compilation for swapping two elements in an array
# Command: make swapArray
swapArrayObjs :=  $(06)/swapArray.o

swapArray: $(swapArrayObjs) 
	$(PP) $(CXXFLAGS) -o $(06)/swapArray $(swapArrayObjs)

swapArray.o: $(06)/swapArray.cpp 
	$(PP) $(CXXFLAGS) -c $(06)/swapArray.cpp	


	
	
# Make all
all: swapArray

# Make clean
clean :
	rm -rf *.o swapArray

# Make reset - Command I use to reset the code after lecture
# Do not use

reset:
	cp ~/DSReset/06-Functions/swapArray.cpp .
	chmod 755 *
	chmod 755 $(06)/
