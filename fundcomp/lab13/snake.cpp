//Nolan Downey
//Program: Let's Play Snake!
//snake.cpp

#include "gfx2.h"
#include "snake.h"

#include <iostream>

using namespace std;

const int SZ = 400; //sized used for spacing throughout program

Snake::Snake() { //constructor for class Snake
	x_pos = SZ/2;
	y_pos = SZ/2;

	x_dir = 0; //snake starts out not moving
	y_dir = 0;

	length = 1;

	Body tail;

	tail.width = 10;
	tail.height = 10;
	tail.xt_pos = x_pos;
	tail.yt_pos = y_pos;

	body.push_back(tail);
}

Snake::~Snake() {} //destructor for class Snake

void Snake::advance() { //allows for animation of a moving snake
	int x1 = body.at(0).xt_pos + x_dir;
	int y1 = body.at(0).yt_pos + y_dir;

	Body addBody;

	addBody = {x1,y1,body.at(0).width,body.at(0).height};

	body.push_front(addBody);
	body.pop_back();

	for (int i = 0; i < length; i++) {
		gfx_rectangle(body.at(i).xt_pos, body.at(i).yt_pos, body.at(i).width, body.at(i).height);
	}

}

void Snake::die() { //method to reset the game ('kill' the snake)
	body.clear();
	x_pos = SZ/2;
	y_pos = SZ/2;

	x_dir = 0;
	y_dir = 0;

	length = 1;

	Body tail;
	tail.xt_pos = x_pos;
	tail.yt_pos = y_pos;
	tail.width = 10;
	tail.height = 10;

	body.push_back(tail);
}

void Snake::moveLeft() { //four methods to control movement of the snake
	x_dir = -10;
	y_dir = 0;
}

void Snake::moveRight() {
	x_dir = 10;
	y_dir = 0;
}

void Snake::moveUp() {
	x_dir = 0;
	y_dir = -10;
}

void Snake::moveDown() {
	x_dir = 0;
	y_dir = 10;
}

void Snake::add_body() { //method add when the snake eats food

	Body newBody;

	newBody.xt_pos = body.at(length-1).xt_pos;
	newBody.yt_pos = body.at(length-1).yt_pos;
	newBody.width = body.at(length-1).width;
	newBody.height = body.at(length-1).height;

	gfx_rectangle(newBody.xt_pos,newBody.yt_pos,newBody.width,newBody.height);

	body.push_back(newBody);
	length += 1;

}

void Snake::dir_change(int x, int y) { //changes direction of the snake
	x_dir = x;
	y_dir = y;
}

bool Snake::edgeCase(int x, int y) { //checks if the snake hits the edge
	if (body.at(0).xt_pos < 0 or body.at(0).yt_pos < 0 ) {
		return true;
	}
	else if (body.at(0).xt_pos > x or body.at(0).yt_pos > y) {
		return true;
	} 

	return false;
}

bool Snake::bodyCase() { //checks if the snake hits itself
	for (int i = 1; i < length; i++) {
		if (body.at(0).xt_pos == body.at(i).xt_pos and body.at(0).yt_pos == body.at(i).yt_pos) {
		return true;
		}
	}
	
	return false;
}

bool Snake::check(int a, int b) { //checks a certain position related to the snake
	for (int i = 0; i < length; i++) {
		if (body.at(i).xt_pos == a and body.at(i).yt_pos == b) {
			return true;
		}
	}

	return false;
}

void dir_director(char input, bool & loop, Snake & snake) { //friend function takes in inputs from the user to control the snake
	
	switch(input) {
		case 'Q':
			if (snake.x_dir == 10)
				return;
			snake.moveLeft();
			break;
		case 'S':
			if (snake.x_dir == -10)
				return;
			snake.moveRight();
			break;
		case 'R':
			if (snake.y_dir == 10)
				return;
			snake.moveUp();
			break;
		case 'T':
			if (snake.y_dir == -10)
				return;
			snake.moveDown();
			break;
		case 27:
			loop = false;
			break;
		default:
			break;
		}
}

array <int, 2> mice_generator(int size, Snake snake) { //function to generate mice for the snake to eat
	int x_pos, y_pos;

	srand(time(0));
	x_pos = rand()%((SZ-9)/10)*10;
	y_pos = rand()%((SZ-9)/10)*10;

	while (snake.check(x_pos, y_pos)) {
		x_pos = rand()%((SZ-9)/10)*10;
		y_pos = rand()%((SZ-9)/10)*10;
	}

	gfx_color(255,255,255);
	gfx_rectangle(x_pos,y_pos,5,5);
	array <int, 2> newArray = {x_pos,y_pos};
	return newArray;
}
