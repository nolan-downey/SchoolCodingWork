# Author: Matthew Morrison
# Email: matt.morrison@nd.edu
# File Name - testSort.sh
#
# File runs SortedComp.cpp for every input
# from 10 to 25,000 in increments of 10
# and prints them to a csv file which 
# can be opened using Microsodr Excel
#
# Also teaches while loops in C Shell Scripting

# Set count equal to 100
# Must be count=100, count = 100 gives an error
count=100

echo "Inputs,Sorted Dynamic Array,Sorted Linked List,Ratio" >> comp.csv

# While count is less than 100000
while [ $count -lt 65535 ]
do
	# >> concatenates onto the end of the file
	./SortedComp $count >> comp.csv
	
	# Increment
	count=$(( $count+100 ))
done