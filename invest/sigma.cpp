#include <iostream>
using namespace std;

int sigma (int n) {
	int S = 0; 	// S is the variable to hold the sigma value

	for (int i = 1; i <= n; i++) {
		S = S + i;	// add the new value into the previous sum 
	}

	return S;	// return the sigma(n) value
}

int main () {
	int n = 0;	// n is the variable to hold the input value

	cout << "Please enter n = ";
	cin >> n;	// read n from input stream
	cout << "Sigma(" << n << ") is ";
	cout << sigma (n);
	cout << endl;

	return 0;
}

