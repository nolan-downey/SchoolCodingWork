#G++ is for the GCC compiler for C++
PP := g++

# GCC is the compiler for C. Included for mallocBadC
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)
CFLAGS := -std=c11 $(FLAGS)



# Variables for Folders
Week3 := ~/DSInClass/Week3



# Compilation for swapping two elements in an array
# Command: make stringRem
stringRemObjs :=  $(Week3)/stringRem.o

stringRem: $(stringRemObjs)
	$(PP) $(CXXFLAGS) -o $(Week3)/stringRem $(stringRemObjs)

stringRem.o: $(Week3)/stringRem.cpp
	$(PP) $(CXXFLAGS) -c $(Week3)/stringRem.cpp




# Make all
all: stringRem

# Make clean
clean :
	rm -rf *.o stringRem

# Make reset - Command I use to reset the code after lecture
# Do not use

reset:
	cp ~/DSReset/06-Functions/stringRem.cpp .
	chmod 755 *
	chmod 755 $(Week3)/
