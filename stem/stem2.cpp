/*
 * This program reads words from a file to build a dictionary and each line saves only one word. The words are pre-sorted in the file.
 * Based on the stem given in the command line argument, this program will look for the words in the dictionary with the same prefix as the stem,
 * and print out all matching words.
 */

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>


using namespace std;


// define some global variables
const unsigned dMax = 650722;	// maximum size of the dictionary
string dictionary[dMax];	// string array holds the dictionary
char * indexPtr[26];		// index pointers for the dictionary from "A" to "Z"


/*
 * Read all lines from an input file to build the dictionary.
 * Save all words in the string arrary: dictionary.
 * The return value is the number of words actually in the dictionary.
 */
int build_dictionary(string fName)
{
	ifstream inFile;	
	int numWord = 0;
	string line;
	int indexSeq = -1;	// index initial value is -1. Index starts from 0. 
	char currIndex = 'a';	// "a" - "A" section
	char currIndexUpper = 'A';	// "A" - "A" section
	
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
		dictionary[numWord] = line;	// write the word into dictionary
		if (indexSeq < 0) {
			// No index has been built yet. Check if prefix is "a" or "A"
			if ((line[0] == currIndex) || (line[0] == currIndexUpper)) {
				indexSeq = 0;	// start to index
				indexPtr[indexSeq] = &(dictionary[numWord]);
			}
		} else {
			// Check if encounter a new index section
			if ((line[0] != currIndex) && (line[0] != currIndexUpper)) {
				indexSeq++;	// start to index a new section
				indexPtr[indexSeq] = &(dictionary[numWord]);
				currIndex = currIndex++;	// prefix changes to the next section
				currIndexUpper = currIndexUpper++;	// prefix changes to the next section
			}
		}
	}

	// test the index system
	cout << "Testing the index system by printing out the first word in each section." << endl;
	for (int i=0; i<26; i++) {
		cout << (char)(indexPtr[i][0]) << " section: " << indexPtr[i] << endl;
	}

	inFile.close();			// close the file

	return numWord;
}

/*
 * The main program asks the user whether to enter a file name or it uses the dafault file.
 * Then it calls the build_dictionary() function to generate the dictionary.
 * It then generates a random number and finds the corresponding word to print.
 */
int main(int argc, char** argv)
{
	string fileName;
	int numWord = 0;	// number of words in the dictionary
	int randX = 0;		// random number

	if (argc < 2) {
		cout << "Please enter the stem for matching words." << endl;
		return -1;
	}

	// all sorted dictionary words are stored in the following file
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

	// look for the first word matching the stem

	// print out the random number and corresponding word

	return 0;
}










