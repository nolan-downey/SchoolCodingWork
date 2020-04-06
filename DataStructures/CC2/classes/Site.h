/**********************************************
* File: Site.h
* Author: Nolan Downey
* Email: ndowney@nd.edu
* 
* Header file for the class Site
**********************************************/

#ifndef SITE_H
#define SITE_H

#include <iostream>
#include <string>

class Site {

	private:

			std::string URL;
			std::string webHeader;
			std::string Time;
			std::string Date;

	public:
		
		Site();
		
		Site(std::string, std::string, std::string, std::string);

		friend std::ostream& operator<<(std::ostream&, const Site&);
};


#endif
