// MarcoLoPiccolo_Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>    
#include <fstream>     //Allows to use the ifstream and ofstream commands and functions
#include <cstdlib>    //Allows us to use the exit command
using namespace std;  //Used so that std:: isn't needed for the stream commands

void addToOutputFile(ifstream& inStreamFile1, ifstream& inStreamFile2, ofstream& outStream);    //Function Header

int main()
{
	ifstream inStreamFile1;     //Calls two input streams representing the two files with values in them given to us
	ifstream inStreamFile2;
	ofstream outStream;        //Calls an output stream which represents the file that the values will be combined into

	inStreamFile1.open("C:/testFiles/input-1.txt");      //Opens the file from the computer and then checks to see if the file was opened properly and if it wasn't 
	if (inStreamFile1.fail()) {                          //then it ouputs an error message then exits the program
		cout << "Input File 1 Opening failed" << endl;   
		exit(1);
	}

	inStreamFile2.open("C:/testFiles/input-2.txt");     //Opens the file from the computer and then checks to see if the file was opened properly and if it wasn't 
	if (inStreamFile2.fail()) {                         //then it ouputs an error message then exits the program
		cout << "Input File 2 Opening failed" << endl;
		exit(1);
	}

	outStream.open("C:/testFiles/output.txt");         //Opens the file from the computer and then checks to see if the file was opened properly and if it wasn't 
	if (outStream.fail()) {                            //then it ouputs an error message then exits the program
		cout << "Output File Opening failed" << endl;
		exit(1);
	}

	addToOutputFile(inStreamFile1, inStreamFile2, outStream);    //Calls the function described below
																 //we aren't using the appending option on the output file as the output file is empty and since it is staying open for both values of 
	                                                             //the input files, then it won't rewrite over either of the files when they are added to the output file
	inStreamFile1.close();
	inStreamFile2.close();                                       //Closes all three files before ending the program and outputs a message saying end of editing files
	outStream.close();

	cout << "End of editing files" << endl;

	system("Pause");
	return 0;
}

//Function is void so that it doesn't need to return any values to main with the three input parameters being the input stream files that will have values in them already
//which will then be saved in an integer variable which can then be output to the third parameter of the ofstream which is the third file that saves both input files values to it
//All three are pass by reference to save memory and makes sure the values are saved correctly
void addToOutputFile(ifstream& inStreamFile1, ifstream& inStreamFile2, ofstream& outStream) {
	int inputFileNumber;             //integer variable used to save each value from the input files

	inStreamFile1 >> inputFileNumber;  //takes the first integer from the inputted file and saves it in the variable
	while (!inStreamFile1.eof()) {      //while loop command used to check for the end of the file
		outStream << inputFileNumber << endl;   //adds the saved integer to the output file and then makes a newline so each number is on its own line
		inStreamFile1 >> inputFileNumber;  //then takes the next integer from the input file and saves it in the integer and this process repeats until the end of the file
	}

	inStreamFile2 >> inputFileNumber;   //The same process is done as above except with the second input file given to us
	while (!inStreamFile2.eof()) {
		outStream << inputFileNumber << endl;
		inStreamFile2 >> inputFileNumber;
	}
}
