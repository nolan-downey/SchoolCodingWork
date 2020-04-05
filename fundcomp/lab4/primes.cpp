#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	int primes[999];
	int count=0;

	for (int n=2; n<1000; ++n){
		primes[n]=1;
		}

	for (int p=2; p*p <= 1000; ++p){
		for (int i = p*p; i<=1000; i+=p){
			primes[i]=0;
		}
	}

	for (int j=2;j<1000;++j){ 
		continue;
		}
/* for some strange reason, the for loop written above this comment is essential to the structure of my code. I attempted commenting it out and deleting it entirely, and when I do so, the entire code simply enters an infinite state and cannot run. If someone knows why this is, please help
 */

	for (int z = 2;z<=1000; ++z){
		if (count <= 9) {
			if (primes[z] == 1){
				cout << setw(4) <<  z << " ";
				count=count+1;
				}
			}
			else {
			if (primes[z]==1){
			cout << endl;
				cout << setw(4) << z << " ";
				count = 1;
				}			
			}
		}
	cout << endl;
return 0;
}
