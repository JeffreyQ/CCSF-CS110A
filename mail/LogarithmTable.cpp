#include <iostream>
#include <cmath>
using namespace std;

double logTable (double n){
	double x = 1.0;
	while (x < 10.0) {
		cout << x << "\t" << log(x) << "\n";
		x = x + 1.0;
	}

	return x;
}

int main(){
	cout <<	logTable(10.0);
	
	return 0;
}

