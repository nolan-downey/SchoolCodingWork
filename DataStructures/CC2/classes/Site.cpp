/**********************************************
* File: Site.cpp
* Author: Nolan Downey
* Email: ndowney@nd.edu
* 
* Implementation File for the class Site
**********************************************/


#include "Site.h"
	
	/********************************************
	* Function Name  : Site::Site
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Default constructor for the class Site
	********************************************/
	Site::Site() : URL(), webHeader(), Time(), Date() {}

	/********************************************
	* Function Name  : Site::Site
	* Pre-conditions : std::string Url, std::string webTitle, std::string time, std::string date
	* Post-conditions: none
	* 
	* Constructor to add elements to the private elements of the class
	********************************************/
	Site::Site(std::string Url, std::string webTitle, std::string time, std::string date) : URL(Url), webHeader(webTitle), Time(time), Date(date) {}

	/********************************************
	* Function Name  : operator<<
	* Pre-conditions : std::ostream& out, const Site& website
	* Post-conditions: std::ostream&
	* 
	* Overloaded output operator to print the Class
	********************************************/
	std::ostream& operator<< (std::ostream& out, const Site& website) {
		
		out << std::endl;
		out << "URL: " << website.URL << std::endl;
		out << "Website Title: " << website.webHeader << std::endl;
		out << "Time Accessed: " << website.Time << std::endl;
		out << "Date Accessed: " << website.Date << std::endl;

		return out;
	}

