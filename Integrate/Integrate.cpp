#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef double (*FUNCTION)(double);

double Integrate(FUNCTION fx, double x, double y){
	double sum = 0;
	for (double i = x; i <= y; i+= 0.0001){
		sum += (fx(i) * 0.0001);
	}
	 return sum;
}
// ** test cases for FUNCTION **
	double line(double x){
		return x;
		}// integrate line fx

	double square(double x){
		return x * x;
		}// integrate square fx

	double cube(double x){
		return x * x * x;
		}//integrate cube fx

int main(int argc, char** argv) {

	cout << "The integral of f(x)=x between 1 and 5 is: " << Integrate(line, 1, 5) << endl;
	cout << "The integral of f(x)=x^2 between 1 and 5 is: " << Integrate(square, 1, 5) << endl;
	cout << "The integral of f(x)=x^3 between 1 and 5 is: " << Integrate(cube, 1, 5) << endl;
	return 0;
}

