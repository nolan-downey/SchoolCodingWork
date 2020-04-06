# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Variables for Folders
CC1 := ~/DSInClass/CC1



# Compiling the palindrome function - CC1 Problem 3
# Command: make palindrome
palindromeObjs :=  $(CC1)/palindrome.o

palindrome: $(palindromeObjs) 
	$(PP) $(CXXFLAGS) -o $(CC1)/palindrome $(palindromeObjs)

palindrome.o: $(CC1)/palindrome.cpp
	$(PP) $(CXXFLAGS) -c $(CC1)/palindrome.cpp	



# Make all
all: palindrome


# make test
test:
	make palindrome
	chmod +x test.sh
	./test.sh 


# Make clean
clean :
	rm -rf *.o palindrome
