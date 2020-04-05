//Nolan Downey
//Program: Fractal Puzzles
//fractals.cpp


//READ ME
//Apologies for some of the long animations
//I wanted to make it colorful for you

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "gfx.h"
using namespace std;

// function prototypes
void sierpinski(int,int,int,int,int,int);
void drawTriangle(int,int,int,int,int,int);
void shrinking_squares(int,int,float);
void drawSquare(int,int,int);
void spiralSquares(float,float,float,float);
void circularLace(int,int,int);
void snowflake(int,int,float);
void tree(int,int,float,float);
void fern(float, float, float, float);
void spiralSpiral(float,float,float,float);

int main() {
	int size = 700;
	int margin = 15;

  int d = 400;
	char c;
 
  bool loop = true;

  gfx_open(size,size,"Fractals on Fractals");
	gfx_color(255,255,255);

	while (loop) {
    c = gfx_wait();
    gfx_clear();
    switch (c) {
      case '1': // Sierpinski Triangle   
        sierpinski(margin,margin,size-margin,margin,size/2,size-margin);
        break;
      case '2': // Shrinking Squares  
				shrinking_squares (size/2, size/2,300);          
        break;
			case '3': //Spiral Squares
				spiralSquares(1,size/2,size/2,0);
				break;
			case '4': //Circular Lace
				circularLace(size/2,size/2,250);
				break;
			case '5': //Snowflake
				snowflake(size/2,size/2,250);
				break;
			case '6': //Tree
				tree(size/2,size,250,3*M_PI/2);
				break;
			case '7': //Fern
				fern(size/2, size, 2*size/3,3*M_PI/2);
				break;
			case '8': // Spiral of Spirals
				spiralSpiral(size/2,size/2,2*size/3,M_PI/2);
        break;
      case 'q':
        loop = false;
      default:
				gfx_text(rand()%size+1,rand()%size+1,"Hey,Press Something Else..");
        break;
    }
  }

  return 0;
}


void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  // Base case. 
	if( abs(x2-x1) < 5 ) return;
	
	// Draw the triangle
	drawTriangle(x1, y1, x2, y2, x3, y3);

	//Randomize Color
	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);
	
	// Recursive calls
	sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
	sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
	sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
	//Draws Three Lines to Make a Triangle
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);
	gfx_flush();
	usleep(2000);
}

void shrinking_squares(int x, int y, float len)
{
	//Base Case
	if (len < 2) return;

	//Draw Square
	drawSquare(len, x, y);

	//Randomize Color
	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);

	//Recursive Calls
	shrinking_squares(x + len/2, y + len/2, len/2.3);	
	shrinking_squares(x - len/2, y + len/2, len/2.3);
	shrinking_squares(x + len/2, y - len/2, len/2.3);
	shrinking_squares(x - len/2, y - len/2, len/2.3);
}

void drawSquare(int len, int x, int y)
{
	//Draws Four Lines to Make a Square
	gfx_line(x - len/2, y - len/2, x + len/2, y - len/2);
	gfx_line(x + len/2, y - len/2, x + len/2, y + len/2);
	gfx_line(x + len/2, y + len/2, x - len/2, y + len/2);
	gfx_line(x - len/2, y + len/2, x - len/2, y - len/2);
	gfx_flush();
	usleep(2000);
}

void spiralSquares(float sz, float x, float y, float angle)
{
	//Base Case
	if (sz > x*2) return;

	//Draw square
	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);

	drawSquare(sz/3,x+sz*cos(angle),y+sz*sin(angle));

	//Recursive
	spiralSquares(sz*5/4,x,y,angle-(M_PI/3.5));
}

void circularLace(int x, int y, int rad)
{
	//Base Case
	if (rad < 1) return;

	//Draw Circle
	gfx_circle(x, y, rad);

	//Pause Screen
	gfx_flush();
	usleep(500);

	//Randomize Color
	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);

	//Recursive
	for (int i = 0; i >= -10; i -= 2) {
		circularLace(x + rad*cos(i*(M_PI / 6)), y + rad * sin(i * (M_PI/ 6)), rad/3);
	}
}

void snowflake(int x, int y, float len)
{
	//Base Case
	if (len < 1) return;

	//Pause Screen
	gfx_flush();
	usleep(2000);

	//Randomize Color
	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);

	//Draw Lines
	for (int i = -2; i >= -10; i-= 2) {
		gfx_line(x, y, x + len * cos(i * M_PI / 5), y + len * sin(i * M_PI / 5));
	//Recursive
		snowflake(x + len * cos(i * M_PI / 5), y + len * sin(i * M_PI / 5), len / 3);
	}
}

void tree(int x, int y, float len, float angle)
{
	//Base Case
	if (len < 1) return;
	
	//Draw Line
	float x1,y1;
	x1 = x + len*cos(angle);
	y1 = y + len*sin(angle);
	
	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);

	gfx_line(x,y,x1,y1);

  //Pause Screen
	gfx_flush();
	usleep(10);	
	
	//Recursive
	tree(x1, y1, len*0.65, angle - M_PI/5.75);
	tree(x1, y1, len*0.65, angle + M_PI/5.75);
}

void fern(float x, float y, float len, float angle)
{
	//Base Case
	if ( len < 2 ) return;

	//Draw Lines
	float x1 = x + len * cos(angle);
	float y1 = y + len * sin(angle);

	srand(time(0));
	gfx_color(rand()%255,rand()%255,rand()%255);

	gfx_line(x,y,x1,y1);

	//Recursive
	fern(x1,y1,len/3,angle-(M_PI/5));
	fern(x1,y1,len/3,angle+(M_PI/5));

	fern(x+((x1-x)/4),y+((y1-y)/4),len/3,angle-(M_PI/5));
	fern(x+((x1-x)/4),y+((y1-y)/4),len/3,angle+(M_PI/5));

	fern(x+((x1-x)/2),y+((y1-y)/2),len/3,angle-(M_PI/5));
	fern(x+((x1-x)/2),y+((y1-y)/2),len/3,angle+(M_PI/5));

	fern(x+(3*(x1-x)/2),y+(3*(y1-y)/2),len/3,angle-(M_PI/5));
	fern(x+(3*(x1-x)/2),y+(3*(y1-y)/2),len/3,angle+(M_PI/5));
	
}

void spiralSpiral(float x, float y, float rad, float angle)
{
	//Base Case
	if (rad < 2) return;
	
	//Draw Point
	//srand(time(0)); I like this one rainbow instead of random
	gfx_color(rand()%255,rand()%255,rand()%255);

	gfx_point(x-rad*cos(angle), y+rad*sin(angle));

	//Recursion
	spiralSpiral(x,y,rad*0.9,angle-M_PI/6);
	spiralSpiral(x-rad*cos(angle),y+rad*sin(angle),0.4*rad,angle-M_PI/6);
}
	
