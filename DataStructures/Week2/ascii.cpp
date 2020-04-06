/**********************************************
* File: ascii.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* A program to show students how ASCII is used 
* to structure character data in the computing device
**********************************************/
#include <iostream>

int main(void){
	
	/* C Procedural Language tranlates \n to ASCII 10 */
	std::cout << "Welcome to Data Structures\n";
	
	/* Casting 10 t0 (char) prints ASCII 10 to output */
	std::cout << (char)78; 		/* N in ASCII is 78 in decimal */
	std::cout << (char)0x6f; 	/* o in ASCII is 0x6f in hexadecimal */
	std::cout << 't';			/* 't' is translated to 116 in ASCII */
	std::cout << (char)0162;	/* r in ASCII is 0162 in octal */
	std::cout << (char)0x65; 	/* e in ASCII is 0x65 in hexadecimal */
	std::cout << (char)32;		/* Space char is 32 in ASCII */
	std::cout << 'D';			/* 'D' is translated to 116 in ASCII */
	std::cout << (char)97;		/* a in ASCII is 97 in decimal */
	std::cout << (char)0x6d; 	/* m in ASCII is 0x6d in hexadecimal */
	std::cout << (char)0145;	/* e in ASCII is 0145 in octal */
	std::cout << (char)10; 		/* New Line is 10 in ASCII */
	
	/* Next, we will print the int, hex, and oct values of Irish from char */
	std::cout << (unsigned int)'I' << " ";						/* Will print 73 */
	std::cout << "0x" << std::hex << (unsigned int)'r' << " ";	/* Will print 0x72 */
	std::cout << (unsigned int)'i' << " ";						/* Will print 105 */
	std::cout << "0" << std::oct << (unsigned int)'s' << " ";	/* Will print 0x72 */
	std::cout << (unsigned int)'h' << " ";						/* Will print 104 */
	std::cout << std::endl;
	
	/* To finish, print a char value outside of 0-127 */
	std::cout << (char)123; 	/* Will print '{' */
	std::cout << (char)213; 	/* Will print gibberish */
	std::cout << (char)125; 	/* Will print '}' */
	std::cout << (char)0x0A; 		/* New Line is 0x0A in ASCII hex */
	return 0;
}
