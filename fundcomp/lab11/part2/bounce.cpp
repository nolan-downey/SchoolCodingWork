//Nolan Downey
//Program: Bouncing Ball
//bounce.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "gfx.h"

using namespace std;

int main()
{
	char input = 0;

	int window_w = 900; //declares window size
	int window_h = 500;
	int x_cd = 50, y_cd = 50, rad = 30; //declares location and size of the circle to be placed
	int dir_x = 1; //x and y direction and speed of the ball
	int dir_y = 1;
	int pausetime = 5000; //pauses the screen to create a smooth animation
	int direction = 0; //variable to help randomize direction during the click phase


	gfx_open(window_w, window_h, "Nolan's Bouncing Ball"); //opens a graphic window using X11
	gfx_color(54,120,150); //sets the color of the ball to light blue

	while(input != 'q') { //window stays open until the user presses q from the keyboard
		
		gfx_circle(x_cd,y_cd,rad); //creates a circle at the specified point at size rad

		x_cd += dir_x; //increments the x and y coordinates so the ball travels across the window
		y_cd += dir_y;

		if (x_cd >= window_w - rad) //handles the ball bouncing off of the walls
			dir_x = -dir_x;
		if (x_cd <= rad)
			dir_x = -dir_x;
		if (y_cd >= window_h - rad)
			dir_y = -dir_y;
		if (y_cd <= rad)
			dir_y = -dir_y;

		if (gfx_event_waiting()) { //program runs until the user inputs a command from the keyboard (left click or 'q')
			input = gfx_wait();
		
			if (input == 1) { //if the user left clicks then it creates a ball going a random speed at a random direction
				int xpos = gfx_xpos();
				int ypos = gfx_ypos();

				if (xpos < rad or window_w - xpos < rad) //checks if the user clicks too close to any of the walls
					continue;
				else if (ypos < rad or window_h - ypos < rad)
					continue; //if too close to the wall, then no ball is created and existing ball continues
				else { 
					
					gfx_flush();

					x_cd = xpos;
					y_cd = ypos;

					srand(time(0)); //helps to create more seemingly random speed and direction

					dir_x = rand()%5 + 1; //randomizes the speed of the new ball
					dir_y = rand()%5 + 1;

					direction = rand() % 10 +1; //randomizes the direction of the new ball

					if ((direction % 2) == 0) {
						dir_x *= -1;
						dir_y *= -1;
					}
				}
			}
		}

		usleep(pausetime); //pauses the screen to help for smooth animation

		gfx_clear(); //clears the screen so there is only one circle on the screen at once
	}

return 0;

}
