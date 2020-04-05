//Nolan Downey
//board.h

#include <vector>
#include <string>
using namespace std;


const bool ACROSS = 1;
const bool DOWN = 0;
const int SZ = 15;
const string END = ".";

struct Word {
	string a_word;
	string s_word;
	int down;
	int across;
	bool orientation;
	bool placed;
};

class Board {
	public:
		Board();
		~Board();
		ostream & printClues(ostream &);
		ostream & printBoard(ostream &);
		ostream & printPuzzle(ostream &);
		void setWord(string);
		string toUpper(string);
		string scramble(string);
		void placeFirst();
		void displayClue();
		void display();
		void followingWord();
		bool placeWord();
		bool checkPlace(int, int, int);
		int wordsLeft();

	private:
		bool bboard[SZ][SZ];
		char mainboard[SZ][SZ];
		int oboard[SZ][SZ];
		vector<Word> words;
		Word nextWord;
		int nextWordPos;
		vector<string> awords;
		vector<string> swords;
};



	
	
		
