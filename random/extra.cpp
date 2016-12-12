/*
 * This program reads words from a file to build a dictionary and each line saves only one word.
 * Based on a randomly generated number, the program searches the dictionary and prints out the corresponding word if it is six letters or longer.
 * Ten words will be printed and two random letters from each word will be omitted.
 * The user will be prompted to input the correct word, case sensitive. 
 * At the end the program will display the number of wrong words and will display the correct answer.
 */

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>


using namespace std;


// define some global variables
const unsigned dMax = 650722;	// maximum size of the dictionary
string dictionary[dMax];	// string array holds the dictionary


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
	}

	inFile.close();			// close the file

	return numWord;
}

/*
 * Based on a randomly generated number, the program searches the dictionary and prints out the corresponding word if it is six letters or longer.
 * Ten words will be printed and two random letters from each word will be omitted.
 * The user will be prompted to input the correct word, case sensitive.
 * At the end the program will display the number of wrong words and will display the correct answer.
 */
int main()
{
	string fileName;
	int numWord = 0;	// number of words in the dictionary
	int randX;		// random number
	int randX2;		// random number
	string contest[10];	// array to keep contest words
	int contestD[10];	// array to keep the reference to dictionary
	string answer[10];	// array to keep answers	
	int grade = 0;		// final contest grade

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

	// generate a random number ten times
	srand(time(NULL));	// to avoid generating the same random number every time
	
	// generate 10 contest questions
	for (int i = 0; i < 10; i++) {
		randX = rand() % numWord + 1;	// generated random number is between 1 and numWord
		contest[i] = dictionary[randX - 1];
		contestD[i] = randX - 1;	// remember the reference in dictionary
		// we must make sure that the string has 6 or more characters
		while (contest[i].length() < 6) {
			randX = rand() % numWord + 1;	// generated random number is between 1 and numWord
			contest[i] = dictionary[randX - 1];
			contestD[i] = randX - 1;	// remember the reference in dictionary
		}
	}
	
	cout << "Ten words will be printed and two random letters from each word will be omitted. Input the correct word, case sensitive." << endl;
	
	// loop the contest questions 1 by 1 to solicit answers
	for (int i = 0; i < 10; i++){
		// replace each of the two random letters of the string with an underscore 
		randX = rand() % contest[i].length() + 1;	// generated random number is between 1 and string length
		contest[i][randX - 1] = '_';	// replace the first letter with an underscore
		randX2 = rand() % contest[i].length() + 1;	// generated random number is between 1 and string length
		while (randX2 == randX)
			randX2 = rand() % contest[i].length() + 1;	// generated random number is between 1 and string length
		contest[i][randX2 - 1] = '_';	// replace the second letter with an underscore
		cout << "The No. " << i + 1 << " contest word is: " << contest[i] << endl;
		cout << "Please enter your word: " << endl;
		getline(cin, answer[i]);	// read the answer line
	}

	for (int i = 0; i < 10; i++) {
		if (dictionary[contestD[i]].compare(answer[i]) == 0) {
			grade++;
			cout << "Your No. " << i + 1 << " answer is correct." << endl;
		} else {
			cout << "Your No. " << i + 1 << " answer is incorrect. The correct answer is " << dictionary[contestD[i]] << "." << endl;
		}
	}
	cout << "Your final grade is " << grade << " out of 10." << endl; 

	return 0;
}










