//Nolan Downey
//Program: Symbolic Typewriter
//symbol.cpp

#include <iostream>
#include <cmath>

#include "gfx.h" //includes a header file for graphic functions using X11

using namespace std;

//function prototypes
//
void square();
void circle();
void triangle();
void polygon(char);

//constant global variables that are used in the functions for the sizes of the shapes
const int SZ = 50;
const int SZ2 = SZ/2;


//main function
//
int main() {

	char input;

	gfx_open(9000,700,"Nolan's Window"); //opens a 900*700 window using X11/XLaunch

	while(input!='q') { //while loop until the user inputs 'q' to exit the program
		input = gfx_wait();

		switch(input)
		{
			case 1: //if the user left clicks, the computer reads it as an integer with the value of 1
				square(); //creates a square at the location of the mouse
				break;
			case 'c': //if the user presses 'c' on the keyboard
				circle(); //creates a circle at the location of the mouse
				break;
			case 't': //if the user presses 't' on the keyboard
				triangle(); //creates a triangle at the location of the mouse
				break;
			case '3': //the following cases draw a polygon with the respective number of sides at the location of the mouse
			case '4': 
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				polygon(input); //polygon function takes in a character as the input, then draws a polygon based on that character
				break;
			case 27: //ascii value for the esc key on the keyboard (clears screen)
				gfx_clear();
				break;
		}
	}

	return 0;

}


void square() {
	int x_pos = gfx_xpos();
	int y_pos = gfx_ypos();
	
	gfx_color(0,0,225); //changes the color to blue

	gfx_line(x_pos-(SZ2),y_pos-(SZ2),x_pos+(SZ2),y_pos-(SZ2)); //four lines to make a square at the location of the mouse
	gfx_line(x_pos-(SZ2),y_pos-(SZ2),x_pos-(SZ2),y_pos+(SZ2));
	gfx_line(x_pos-(SZ2),y_pos+(SZ2),x_pos+(SZ2),y_pos+(SZ2));
	gfx_line(x_pos+(SZ2),y_pos+(SZ2),x_pos+(SZ2),y_pos-(SZ2));
}

void circle() {

	gfx_color(225,225,225); //changes the color to white
	gfx_circle(gfx_xpos(),gfx_ypos(),SZ2); //gfx function to draw a circle

}

void triangle() {

	int x_pos = gfx_xpos();
	int y_pos = gfx_ypos();
	
	gfx_color(0,225,0); //makes the triangle green

	gfx_line(x_pos-SZ2,y_pos+SZ2,x_pos+SZ2,y_pos+SZ2); //three lines to draw an isoceles triangle at the location of the mouse
	gfx_line(x_pos-SZ2,y_pos+SZ2,x_pos,y_pos-SZ2);
	gfx_line(x_pos+SZ2,y_pos+SZ2,x_pos,y_pos-SZ2);

}
	

void polygon(char input) {

	int sides = side - '0'; //polygon function takes in a character and changes it to an integer to draw the shape
	
	int x_pos = gfx_xpos();
	int y_pos = gfx_ypos();
	float angle = (2*M_PI)/sides; //handles the angle between the lines, allows the function to draw the correct number of lines
	double i = 0.; //i is declared as a double to handle the addition of the angle
	gfx_color(160,32,255); //changes the color of the shape to purple

	while (i < 2*M_PI){
		float x1 = x_pos + (cos(i) * (SZ2)); //uses polar coordinates in a for loop to draw the lines of the polygon
		float y1 = y_pos + (sin(i) * (SZ2));
		float x2 = x_pos + (cos(i + angle) * (SZ2));
		float y2 = y_pos + (sin(i + angle) * (SZ2));
		gfx_line(x1,y1,x2,y2);
		i += angle;
	}
}
