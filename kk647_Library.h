// This is my library.

// Author: Koba Khitalishvili
// Date: 2/24/2014

#include <iostream>
#include <string>

using namespace std;

//--------------Prototype-----------
static string promptForString(string prompt);

//-----------Subprogram----------. 
/*This function outputs a string to the console, accepts and returns user supplied string input. 
Argument prompt is displayed in the console. User supplied string input is stored in the
userInput variable.
@param prompt is a prompt to be displayed on the console before taking in user input. 
Version 1.0 */

static string promptForString(string prompt)
{
	cout << prompt;
	string userInput;
	getline(cin,userInput);
	cin.clear();

	return userInput;
}

