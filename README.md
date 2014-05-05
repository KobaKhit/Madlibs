# Madlibs
##User manual
This program plays the game of Madlibs with the user. First, it displays the instructions if user desires so. Then, it prompts user for a file name with a text. Every time the program finds appropriate places in the text it prompts user to supply a word of certain kind. At the end the program outputs the resulting text to the console and saves it to a text file called Madlibs_output.txt.

##System manual
First, the program displays the instructions if user desires so by calling the procedure `introduction()` which in turn is using simple if else statement and the function `promptForString(string prompt)` from `kk647_Library.h`. Then, the program prompts user for a file name of a file with a skeleton text in it. To prompt the user for a file name the program uses a function `promptForFilename(string prompt)` which in turns calls the function `promptForString(string prompt)`  from `kk647_Library.h`. Once the file name is supplied it is stored in the `filename` variable. The program then uses `ifstream(filename)` and a while loop to read the text in the file to a string variable `skeletonText`. The while loop reads each line and adds it to the string defined outside the loop `skeletonText`. Then, the program searches through the string looking for delimited descriptors by using the while loop. Every time the program finds a descriptor it removes the delimiters and stores the descriptor in the string `desc`. Then the program prompts the user for appropriate descriptor replacement using the cout statement “Enter a desc”, also deciding whether to use an article “a” or “an” depending on the first letter of the descriptor. Once the descriptor is supplied the program uses the replacement method to replace the descriptor and the delimiters with the user input. Then, the program updates the `nextnext` variable which acts as a counter for the while loop. Once, there are no more delimiters left the `nextnext` variable evaluates to -1 because this is the value the `find()` method produces if it cannot find the specified  characters in a string, and the loop stops. This process repeats until `nextnext` evaluates to -1. At the end the program outputs the resulting text to the console and saves it to the text file.

##Running the program 
I wrote and compiled this program in Microsoft Visual Studio 2010. I tested it in XCode and it runs there fine, albeit, in XCode the input of the skeleton text file name is a bit different. 

####Running Madlibs in MVS 2010
Make sure that all the files in the repo are located in the project folder on your computer. When the program prompts for the file name just enter `Madlibs.txt` without quoatation marks. You may suppply your own file with skeleton text, just be sure to include the descirptors in the right format which you find by looking at the Madlibs.txt contents.

####Running Madlibs in XCode
Make sure that all the files in the repo are located in the project folder on your computer. When the program prompts for the file name you will have to enter the full path. For example, on my computer the Madlibs files are located in the Madlibs folder on my desktop. Hence, the file name should be entered as `/Users/Koba/Desktop/Madlibs/Madlibs.txt`.

##Test Log
Below is the screenshot of what the program looks like in MVS 2010
[screen](/Users/Koba/Documents/Drexel/Courses/2014/Winter2014/CS171/Hw2/Hw2.xcodeproj)
