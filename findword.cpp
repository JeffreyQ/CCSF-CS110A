/*
 * This program reads a file to build a dictionary. 
 * The words are saved in a file, each line saves one word.
 * Based on a randomly generated number, the program searches the dictionary and prints out the corresponding word.
 */

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>


using namespace std;


// define some global variables
const unsigned dMax = 650722;	// maximum size of the dictionary
string dictionary[dMax];	// the string array holds the dictionary


/*
 * Read all lines from an input file to build the dictionary.
 * Save all words in the string arrary: dictionary.
 * It return the number of words actually in the dictionary.
 */
int build_dictionary(string fName)
{
	ifstream inFile;	
	int numWord = 0;
	string line;
	
	if (!fName.empty()) {
		inFile.open(fName.c_str());	// open the file	
		if (!inFile.is_open()) {
			cout << "File cannot be opened for reading." << endl;
			return -1;	// if the file does not exist, quit
		}
	} else {
		cout << "File name is empty." << endl;
		return -1;		// if the file name is empty, quit
	}

	for (numWord = 0; numWord < dMax; numWord++) {
		getline(inFile, line);	// read one line
		if (inFile.eof()) {
			cout << "End of file prematurely." << endl;	
			break;		// break the loop
		}
	
	}	dictionary[numWord] = line;	// write the word into dictionary

	inFile.close();			// close the file

	return numWord;
}


/*
 * Testing program to print out all words in the dictionary.
 */
void print_dictionary(int iMax)
{
	cout << "The dictionary is as following:" << endl;
	for (int i=0; i<iMax; i++) {
		cout << "No. " << i+1 << " word is \"" << dictionary[i] << "\"." << endl;
	}
	cout << endl;
}


/*
 * The main program read a filename which contains the dictionary words.
 * It calls the build_dictionary function to create the dictionary.
 * It then generates a random number and find the corresponding word to print.
 */
int main()
{
	string fileName;
	string choice = "N";	// ask whether enter a file name
	int numWord = 0;	// number of words in the dictionary
	int randX = 0;		// random number

	cout << "Do you want to enter a file name other than the default? (Y/N)" << endl;
        cin >> choice;
        if (choice == "Y" or choice == "y") {
                cin.ignore(80, '\n');   	// clear input buffer, becase cin already reads previous input
		cout << "Please enter the file name: " << endl;
                getline(cin, fileName);         // read a line for analysis instead of the default string
        } else
		fileName = "/users/abrick/resources/american-english-insane";

	numWord = build_dictionary(fileName);
	if (numWord == 0) {
		cout << "The dictionary is empty." << endl;
		return -1;	// no word in the dictionary
	}
	else if (numWord < 0) {
		cout << "Input file has a problem for reading." << endl;
		return -1;
	}
	else
		cout << "There are total " << numWord << " words in the dictionary." << endl;

	// generate a random number
	srand(time(NULL));	// to avoid generating the same random number every time
	randX = rand() % numWord + 1;	// generated random number is between 1 and numWord

	// print out the random number and corresponding word
	cout << "The random number is " << randX << "." << endl;
	cout << "The corresponding word is \"" << dictionary[randX - 1] << "\"." << endl;

	return 0;
}










