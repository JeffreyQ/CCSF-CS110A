#include <iostream>
using namespace std;

double factorial (long n) {
	double F = 1.0;
	
	if (n == 0L) {
		F = 1.0;
	} else if (n == 1L) { 
		F = F *(double)n; 
	} else {
		F = factorial (n-1) * n; 
	}
	
	return F;
}

int main () {
	long n = 0L;

	cout << "Please input a number: ";
	cin >> n; 
	if (n >= 0) {
		cout << n << "! = " << factorial (n) << endl;
	} else {
		cout << "No negative number allowed!" << endl;
	}

	return 0;
}
