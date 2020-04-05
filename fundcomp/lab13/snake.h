//Nolan Downey
//Program: Let's Play Snake
//snake.h

#include <deque> //Learned from upperclassman CS major to help with debugging
#include <array>
using namespace std;

class Snake {
	public:
		Snake();
		~Snake();
		void advance();
		void die();
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		void add_body();
		void dir_change(int,int);
		bool edgeCase(int,int);
		bool bodyCase();
		bool check(int,int);
		friend void dir_director(char, bool &, Snake &);
	private:
		struct Body {
			int xt_pos;
			int yt_pos;
			int width;
			int height;
		};
		int x_pos, y_pos;
		int x_dir, y_dir;
		int length;

		deque <Body> body; //deque taught by upperclassman CS major to help

};

array <int, 2> mice_generator(int,Snake); 

		

