#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

int main () {
	ofstream outFile;
	string fileName, name, date, description, parameters, title;
	int numComments = 1;
	char keepGoing = 'Y';
	cout << "============================================" << endl
		 << "===== Welcome to the Comment Generator =====" << endl
		 << "============================================" << endl
		 << "by BucketBoss" << endl
		 << endl
		 << "Name the file you want to save your comments to: ";
	getline(cin, fileName);
	outFile.open(fileName);
	cout << endl
		 << "Enter your NAME: ";
	getline(cin, name);
	cout << endl
		 << "Enter the DATE: ";
	getline(cin, date);
	while (keepGoing != 'N' && keepGoing != 'n') {
		cout << endl
			 << ""
			 << "Enter the TITLE of function " << numComments << "." << endl
			 << "----------------- Maximum Length ----------------" << endl
			 << ">: ";
		getline(cin, title);
		cout << endl
			 << ""
			 << "Write a DESCRIPTION of function " << numComments << "." << endl
			 << "------------------ Maximum Length -----------------" << endl
			 << ">: ";
		getline(cin, description);
		cout << endl
			 << ""
			 << "List the PARAMETERS of function " << numComments << "." << endl
			 << "------------------ Maximum Length ------------------" << endl
			 << ">: ";
		getline(cin, parameters);
		outFile << "// *****************************************************************" << endl
			    << "// * Function Name: " << left << setw(47) << title << "*" << endl
				<< "// * Description: " << left << setw(49) << description << "*" << endl
				<< "// * Parameters: " << left << setw(50) << parameters << "*" << endl
				<< "// * Date: " << left << setw(56) << date << "*" << endl
				<< "// * Author: " << left << setw(54) << name << "*" << endl
				<< "// *****************************************************************" << endl
				<< endl;
		cout << endl
			 << "Wrote comment for function " << numComments << " to file." << endl;
		numComments++;
		cout << endl
			 << "Do you want to continue adding comments? (Y/n): ";
		keepGoing = getch();
		cout << endl;
	}
	return 0;
}