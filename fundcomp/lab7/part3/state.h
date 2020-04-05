//Nolan Downey
//states.h

#include <string>
using namespace std;

class States {
	public:
		States();
		States(string,string,string,int,int,int);
		~States();
		void setAbbrv(string);
		void setName(string);
		void setCap(string);
		void setPop(int);
		void setYear(int);
		void setReps(int);
		string getAbbrv();
		string getName();
		string getCap();
		int getPop();
		int getYear();
		int getReps();
	private:
		string abbrv;
		string name;
		string capitol;
		int pop;
		int year;
		int reps;
};

void m_display();
void choice_director(int,vector<States>&);
void s_display(vector<States>&);
void oldest(vector<States>&);
void c_display(vector<States>&);
void largest(vector<States>&);
void most_reps(vector<States>&);
		
