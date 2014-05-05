// This program reads user supplied skeleton text file for the game Madlibs. Once the file name is supplied 
// the proram stores the text from the file in a string variable. Then the program searches through the
// string looking for descriptors. Every time the program finds a descriptor it prompts the user for
// appropriate replacement. At the end the program outputs the resulting text to console and saves it to the 
// text file.

// Author: Koba Khitalishvili
// Date: 2/25/2014
// Version 1.0

#include <iostream>
#include <string>
#include <fstream>
#include "kk647_Library.h"

using namespace std;

//---------Prototypes----------------

void introduction();
string promptForFilename(string prompt);

//-----------------------------------

int main(void) 
{
	// Gives the user an option to read instructions
	introduction();

	//Prompts user for the file name of the file with the skeleton text
	string prompt= "\nPlese, enter the file name with the prepared text(e.g. filename.txt). "
		"\nIf you decide to quit leave the line blank: ";
	string filename = promptForFilename(prompt); // Prompts user for file name and returns "" if user decides
	if(filename == "") { cout << endl; return 0;}// to quit

	// Reads the file with the skeleton text and stores text in the skeletonText variable
	string skeletonText, temp;
	ifstream fin(filename);
	
	if(fin.is_open())
	{   // Reads the supplied text file until the end
		while(!fin.eof()) /* is true until the end of file*/
		{
			getline(fin,temp);
			skeletonText += temp; /* concatenates new line with the previous line(s)*/
		}
	} else 
	{ 
		cout << "File does not exist. Try again."<< endl;
		return 0;
	}
	fin.close();
	cout << endl;

	// Finds descriptors in the skeletonText string and replaces them with the user supplied inputs
	string DELIMITER = "**";
	int nextNext = 0; // acts as a counter for the while loop
	
	while(nextNext != -1)
	{ 
		// Determines the position of the descriptor
		int descPos1 = skeletonText.find(DELIMITER);// position of first delimiter
		int nextDescPos1 = skeletonText.find(DELIMITER, descPos1 + 1); // pos of second delimiter
		nextNext = skeletonText.find(DELIMITER, nextDescPos1 + 1); // updates counter
		string desc = skeletonText.substr(descPos1 + 2, nextDescPos1 - descPos1 - 2);// extracts descriptor
																					// name
		// Decides the right article 
		string article = "a";
		bool a = desc.substr(0,1) == "A" || desc.substr(0,1) == "E" || desc.substr(0,1) == "I"
			|| desc.substr(0,1) == "O" || desc.substr(0,1) == "Y" || desc.substr(0,1) == "U";
		if(a) {article = "an";}

		// Asks for user input to replace descriptor
		cout << "Enter " << article << " " << desc << ": ";
		string userInput;
		cin.clear();
		getline(cin,userInput);	

		skeletonText.replace(descPos1,nextDescPos1 - descPos1 + 2,userInput);// replaces descriptor
																			 // with user input
	}

	// Outputs the resulting text to the console and to the text file
	ofstream fout("Madlibs_output.txt");
	fout << skeletonText;
	fout.close();
	cout << "\nThe resulting text is: " << endl << skeletonText << endl;
	

	return 0;
}

//-----------Subprograms---------------------------------------------
/*Lets user see instructions if desired*/
void introduction()
{
	string prompt =
	"You are about to play Madlibs. If you need game instructions enter \"Y\".\nOtherwise, enter whatever: ";
	string userAns = promptForString(prompt);

	if(userAns == "Y" || userAns == "y") 
	{ 
		cout << "\nMadlibs is a word game. You are asked for words which will \nbe put into a prepared text "
			"into appropriate places."<< endl << endl;
	}

}
/*Prompts user for a file name
@param prompt is a prompt to be displayd before taking in the user supplied file name*/
string promptForFilename(string prompt) // promts user for a file name and returns "" if user decides to quit
{
	string userAns = promptForString(prompt);
    return userAns;
}