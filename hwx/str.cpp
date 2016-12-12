/* 
 * ask user whether he/she wants to input a text string for analysis 
 * if Y (yes), then read a line of string, else if N (no), there is a default string for analysis
 * count the percentage of 'x' in the string 
 * count the percentage of 'X' in the string
 * e.g.
 *     in string "Xerox is excellent.",  there are 2 'x', total length of this string is 19 characters, so percentage of 'x' in the string is 2/19 = 0.10526 
 *     in string "Xerox is excellent.",  there are 1 'X', total length of this string is 19 characters, so percentage of 'X' in the string is 1/19 = 0.05263 
 */
#include <iostream>
#include <string>

using namespace std;

/*
 * For a given string input we use loops to calculate the percentage of 'X' and 'x' in the string.
 */
int count_perc_ofXorx(string inputStr)
{
	int totalLen = 0;	// total length of the string
	int totalX = 0;		// total length of 'X'
	int totalx = 0;		// total length of 'x'
	int i = 0;		// loop control variable

	if (inputStr.empty()) {
		cout << "The input string is empty." << endl;
		return -1;
	}

	while (inputStr[i] != '\0') {	// check if null terminator 
		totalLen++;	// increase count of characters by 1
		if (inputStr[i] == 'X')
			totalX++;	// increase count of 'X' by 1 
		if (inputStr[i] == 'x')
			totalx++;	// increase count of 'x' by 1 
		i++;
	}

	cout << "\tThe length of the string (i.e. total # of characters) is " << totalLen << endl;
	cout << "\tThe # of character 'X' is " << totalX << endl;
	cout << "\tThe percentage of 'X' in the string is " << double(totalX) / double(totalLen) << endl;
	cout << "\tThe # of character 'x' is " << totalx << endl;
	cout << "\tThe percentage of 'x' in the string is " << double(totalx) / double(totalLen) << endl;

	return 0;
}

int main()
{
	bool yesNo = false;	// check enter new string or not
	string choice = "N";
	string inputStr = "Exxon mobil is excellent; but Xerox is extremely innovative.";	// hold the input string

	cout << "Would you like to enter a string for analysis (Y/N)? ";
	cin >> choice;
	if (choice == "Y" or choice == "y") {
		cin.ignore(80, '\n');	// clear input buffer, becase cin already reads previous input  
		getline(cin, inputStr);		// read a line for analysis instead of the default string
	}

	cout << inputStr << endl;
	count_perc_ofXorx(inputStr);

	return 0;
}

