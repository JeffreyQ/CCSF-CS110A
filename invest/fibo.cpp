#include <iostream>
using namespace std;

int fibo (int n) {
	int Fi = 0; 	// S is the variable to hold the sigma value

	if (n == 0) {	
		Fi = 0;
	} else if (n == 1) {
		Fi = 1;
	} else { 
		Fi = fibo (n - 1) + fibo (n - 2); 
	}

	return Fi;	// return the fibonacci(n) value
}

int main () {
	int n = 0;	// n is the variable to hold the input value

	cout << "Please enter n = ";
	cin >> n;	// read n from input stream
	if (n >= 0) {
		cout << "Fibonacci(" << n << ") is ";
		cout << fibo (n);
		cout << endl;
	} else { 
		cout << "No negative number allowed." << endl;
	}

	return 0;
}

