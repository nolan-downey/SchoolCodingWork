//Nolan Downey
//implementation file for class States

#include <iostream>
#include <string>
#include <vector>
#include "state.h"

using namespace std;


//defines parts of the States class
//includes constructors, destructors, get/set methods, and utility methods

States::States() {}

States::States(string ab, string nm, string cp, int po, int yr, int rp)
{
	abbrv = ab;
	name = nm;
	capitol = cp;
	pop = po;
	year = yr;
	reps = rp;
}

States::~States() {}

void States::setAbbrv(string ab)
{
	abbrv = ab;
}

void States::setName(string nm)
{
	name = nm;
}

void States::setCap(string cp)
{
	capitol = cp;
}

void States::setPop(int po)
{
	pop = po;
}

void States::setYear(int yr)
{
	year = yr;
}

void States::setReps(int rp)
{
	reps = rp;
}

string States::getAbbrv()
{
	return abbrv;
}

string States::getName()
{
	return name;
}

string States::getCap()
{
	return capitol;
}

int States::getPop()
{
	return pop;
}

int States::getYear()
{
	return year;
}

int States::getReps()
{
	return reps;
}

void m_display() //the first function for the menu part of the file
{
	cout << "1: Display every State and its abbreviation in the United States" << endl;
	cout << "2: Display the oldest states in the US"  << endl;
	cout << "3: Display every capitol! I challenge you to match each capitol to its respective state" << endl;
	cout << "4: Display the largest population of a US state" << endl;
	cout << "5: Display all states with a double digit number of representatives" << endl;
	cout << "6: Exit this menu" << endl;
}

void choice_director(int i, vector<States>&s) //directs user input choice
{
	switch (i)
	{
		case 1:
			s_display(s);
			break;
		case 2:
			oldest(s);
			break;
		case 3:
			c_display(s);
			break;
		case 4:
			largest(s);
			break;
		case 5:
			most_reps(s);
			break;
		case 6:
			break;
		default:
			cout << "Wrong Number Dummy..." << endl;
			break;
		}
}

void s_display(vector<States>&s) //displays all states and their abbreviations through the use of an iterator
{
	for (auto itr = s.begin(); itr < s.end(); itr++)
		cout << itr->getName() << ", " << itr->getAbbrv() << endl;
}

void oldest(vector<States>&s) //displays the oldest states in America and which year they were established
{
	int yr = 10000;
	for (auto itr = s.begin(); itr < s.end(); itr++)
	{
		if (itr->getYear() < yr)
			yr = itr->getYear();

	}

	for (auto itr = s.begin(); itr < s.end(); itr++)
	{
		if (yr == itr->getYear())
			cout << "One of the oldest states in the US is: " << itr->getName() << endl;
	}
	

	cout << "These states was established in: " << yr << endl;
}

void c_display(vector<States>&s) //displays all capitols
{
	for (auto itr = s.begin(); itr < s.end(); itr++)
		cout << itr->getCap() << ", ";

	cout << endl;
}

void largest(vector<States>&s) //displays which state has the largest population and its population
{
	int pop = 0;
	for (auto itr = s.begin(); itr < s.end(); itr++)
	{
		if ( pop < itr->getPop())
	 		pop = itr->getPop();
	}

	for (auto itr = s.begin(); itr < s.end(); itr++)
	{
		if ( pop == itr->getPop())
			cout << "The state with the largest population is: " << itr->getName() << endl;
	}
	
	cout << "The largest population of this state is: " << pop<< endl;
}

void most_reps(vector<States>&s) //displays states with over ten representatives in the legislative branch
{
	for (auto itr = s.begin(); itr < s.end(); itr++)
	{
		if (itr->getReps() >= 10)
			cout << itr->getName() << " - " << itr->getReps() << ", ";
	}
	
	cout << endl;
}
	
