/*
 * This program reads words from a file to build a dictionary and each line saves only one word. 
 * Based on the stem given in the command line argument, this program will look for the words in the dictionary with the same prefix as the stem,
 * and print out all matching words.
 */

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;


// put all function prototypes here
int build_dictionary(string);

// define some global variables
const unsigned dMax = 650722;   // maximum size of the dictionary
string dictionary[dMax];        // string array holds the dictionary
int index[60];                  // index up to 60 sections
int indexSeq = -1;              // remember how many indices has been built


/*
 * The main program reads the command line arguments, the second item is used as the STEM.
 * The main program then reads the file containing all dictionary words and calls the build_dictionary() 
 * function to generate the dictionary. At the same time, it builds an index system to ease the search.
 * Then, the program uses the first character in the STEM to locate the corresponding indexed section in 
 * the dictionary. And it starts to find all matched words in this indexed section until all matching
 * words are found or hit the end of the indexed section. 
 */
int main(int argc, char** argv)
{
	string fileName = "/users/abrick/resources/american-english-insane";	// dictionary file
	int numWord = 0;	// number of words in the dictionary
	string stem;		// record the stem string
	int stemLen = 0;	// how long is the stem
	int indexPos = 0;	// indexed position to start searching

	if (argc != 2) {
		cout << "Usage: stem <prefix string to be matched in dictionary>" << endl;
		return -1;
	} else if ((argv[1][0] >= 'a' && argv[1][0] <= 'z') || (argv[1][0] >= 'A' && argv[1][0] <= 'Z')) {
		// argv[1] is the 2nd string in the command line; argv[1][0] is the 1st character in this string.
		// valid stem to match the dictionary words, we only take letters (a-z and A-Z).
		stem = argv[1];		// keep the prefix string in this variable 
		cout << "The stem is \"" << stem << "\"." << endl;
		stemLen = stem.length();	// keep the length of the prefix string
	} else {
		// invalid stem
		cout << "The stem \"" << stem << "\" not a valid stem." << endl;
		return -1;
	}

	// we need to build the dictionary and create corresponding index system now
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
		cout << "There are total " << numWord << " words in the dictionary." << endl << endl;

	// look for the index matching the first character of the stem
	// note that indexSeq is the largest index number. It is a global variable keeping value from build_dictionary()
	for (indexPos = 0; indexPos <= indexSeq; indexPos++) { 
		if (dictionary[index[indexPos]][0] == stem[0]) {
			// found the indexed section
			break;
		}
	}

	if (indexPos > indexSeq) {
		// cannot find any matching indexed section
		cout << "Ths stem does not match any word." << endl;
	} else {	// we found a matching index section to search
		bool matchFound = false;	// no match found yet

		cout << "Look for matching words now." << endl;

		// start to loop through this indexed section to find matching words
		for (int i = index[indexPos]; i < index[indexPos+1]; i++) {
			if (dictionary[i].compare(0, stemLen, stem) == 0) {
				// the stem string is a prefix of the word
				if (!matchFound)
					matchFound = true;	// flag the finding
				cout << "Matching word:  " << dictionary[i] << endl;
			} else if (matchFound) {
				break;	// exhausted all matched words
			}	// if we have not found any matching word, continue
		}
		if (!matchFound)
			cout << "Cannot find a matching word for the stem \"" << stem << "\"" << endl;
	}

	return 0;
}


/*
 * Read all lines from an input file to build the dictionary.
 * Save all words in the string array: dictionary.
 * At the same time, build an index system saved in the index array.
 * The return value is the number of words actually in the dictionary.
 */
int build_dictionary(string fName)
{
	ifstream inFile;	
	int numWord = 0;
	string line;
	char currIndexChar;		// keep the indexed character for the indexed section
	
	// This is a global variable which equals to the number of indices - 1 at the end
	indexSeq = -1;		// -1 means that no index has been created yet. 

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

		// check whether we need to build a new index section
		if (indexSeq < 0) {
			// No index has been built yet
			indexSeq = 0;	// start to index the 1st item
			index[indexSeq] = numWord;
			currIndexChar = dictionary[numWord][0];	// remember this index character
		} else {
			// Check if encounter a new index section
			if (line[0] != currIndexChar) {
				indexSeq++;	// start to index a new section
				index[indexSeq] = numWord;
				currIndexChar = dictionary[numWord][0]; // remember this index character
			}
		}
	}

	inFile.close();			// close the file

	return numWord;
}










