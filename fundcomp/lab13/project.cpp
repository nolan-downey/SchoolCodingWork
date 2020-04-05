//Nolan Downey
//Program: Let's Play Snake
//snakemain.cpp

#include "gfx2.h"
#include "snake.h"

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <array>

using namespace std;

const int SZ = 400; //constant size used throughout program for spacing

int main() {
	bool loop = true; //loop to control if program continues to run
	int count = 0;
	int waiting;

	char input;
	Snake mainSnake;
	array<int, 2> mice;

	gfx_open(SZ,SZ,"Let's Play Snake!"); //opens graphics window
	
	while (loop == true) {
		gfx_clear(); //clears screen at beginning of every iteration

		if (count == 0) {
			mice = mice_generator(SZ,mainSnake); //generates mice for the snake
			count++;
		}

		gfx_color(255,255,255); //makes the mice white
		gfx_rectangle(mice.at(0),mice.at(1),10,10);

		
		gfx_color(0,60,255); //makes the snake blue
		gfx_line(0,SZ-5,SZ,SZ-5);
		gfx_text(150, SZ-10, "Press ESC to quit."); //tells user how to quit

		if (mainSnake.check(mice.at(0),mice.at(1))) {
			mainSnake.add_body();
			mice = mice_generator(SZ,mainSnake);
			continue;
		}

		mainSnake.advance(); //allows for movement of the snake

		if (mainSnake.bodyCase() or mainSnake.edgeCase(SZ,SZ)) {
			//end game screen if user kills the snake
			gfx_clear();
			gfx_color(255,0,0);
			gfx_text(175,SZ/2,"Game Over");
			gfx_text(100,SZ-10,"Press ESC to quit. Press R to restart.");
			while (input != 'r' and input != 27) {
				input = gfx_wait();
			}
			if (input == 27) {
				loop = false;
			}
			else if (input == 'r') {
				mainSnake.die(); //kills the snake and restarts the game
			}
		} 

		gfx_flush();

		if ((waiting = gfx_event_waiting())) { //waits for user to input something on the keyboard
			input = gfx_wait();
			dir_director(input, loop, mainSnake);
		}

		while (gfx_event_waiting()) {
			gfx_wait();
		}
		usleep(60000); //pauses the screen for smooth animation
	}

	return 0;
}

