#include <iostream>
using namespace std;

long sigma (long n) {
	long S = 0;	// holds the result number

	if (n == 1) {
		S = S + n;	// base of the recursion is 1
	} else { 
		S = sigma(n-1) + n;	// recursive call
	}

	return S;
}

int main () {
	long n = 0;

	cout << "Please enter a number: ";
	cin >> n;
	if (n >= 0) {
		cout << "Sigma(" << n << ") = " << sigma (n) << endl;
	} else {
		cout << "No negative number is allowed." << endl;
	}

	return 0;
}
