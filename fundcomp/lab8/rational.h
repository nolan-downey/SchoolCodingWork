// rational.h

using namespace std;

class Rational {
		friend istream & operator>> (istream &, Rational &);
		friend ostream & operator<< (ostream &, Rational &);
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
		void setRational(int,int);
    Rational operator+ (Rational);
    Rational operator- (Rational);
    Rational operator* (Rational);
    Rational operator/ (Rational);
		void simplify(Rational&);
		void sign();
		int findGCD(int,int);
  private:
    int numer;
    int denom;
};

