//Nolan Downey
//Program: Fun Animation
//funanim.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cmath>
#include "gfx.h"

using namespace std;

int main()
{
	char input = 0;

	int width = 500;
	int height = 500;
	int start = 250;

	int SZ = 30;

	int xt, yt, xc, yc;

	float angle = 0;

	gfx_open(width,height,"Fun Animation"); //opens a graphics window

	while (input != 'q') {
	
		angle += 0.1; //iterating angle to create circular movement

		xt = start + (-cos(angle) * 100); //x position of the triangle
		yt = start + (-sin(angle) * 100); //y position of the triangle

		xc = start +  (cos(angle) * 100); //x position of the circle
		yc = start + (sin(angle) * 100); //y position of the circle
		
		gfx_color(54,120,150); //color of the triangle (blue) 

		gfx_line(xt+SZ,yt-SZ,xt,yt+SZ); //three lines to create a triangle
		gfx_line(xt,yt+SZ,xt-SZ,yt-SZ);
		gfx_line(xt-SZ,yt-SZ,xt+SZ,yt-SZ);

		gfx_color(255,150,30); //color of the circle (orange)

		gfx_circle(xc,yc,SZ);

		srand(time(0));

		gfx_color(0,255,0); //color of the text (green)

		gfx_text(200,10,"What a Fun Animation!!"); //creates a header for the graphics window

		gfx_text(rand()%(width-SZ),rand()%(height-SZ),"CLICK ME!"); //randomly prints text around the window


		if (gfx_event_waiting()) { //waits to see if the user clicks
			input = gfx_wait();

			if (input == 1) { //draws a similey face if the user clicks
				gfx_color(60,150,250);
				gfx_line(233,233,245,227);
				gfx_line(253,227,265,233);
				gfx_circle(240,240,5);
				gfx_circle(260,240,5);
				gfx_line(220,250,230,260);
				gfx_line(230,260,245,265);
				gfx_line(245,265,255,265);
				gfx_line(255,265,270,260);
				gfx_line(270,260,280,250);
				
				gfx_flush();
				
				usleep(10000000);
			}

		}
		usleep(50000); //pauses the screen and clears it to create smooth animation
		gfx_clear();
	}

	return 0;
}
