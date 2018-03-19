#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int PerfectSqre = 0;
	int FirstDig, SecDig;
	for(int i = 0; i <= 100; i++)
	{
		PerfectSqre = i * i;
		SecDig = PerfectSqre % 10;
		FirstDig = (PerfectSqre / 10) % 10;
		if(FirstDig % 2 == 1 && SecDig % 2 == 1) {
			cout << "Perfect square is " << PerfectSqre << endl;
		}else if(i == 100) cout << "No Solution";
	}
return 0;
}
