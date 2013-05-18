/* ========================================================================== */
/*	PROGRAM: Student Grade Class
	File: student.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Kelley
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 5
    DUE DATE: 03/22/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'student.cpp','student.h7' files. This class creates a simple student grade program 
that allows for storing of student's final grades in a large setting.

INPUT

This program will ask for two inputs: The name of the text file(.txt) that we will be reading, and the name of 
the text file(.txt) we will be outputting to.


OUTPUT

This class will show no terminal output besides asking the user for basic input, and a output at the end of the
program showing that the process is complete

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user. This class does protect
the integrity of the data with some bad data-checking but is not fully debugged
agaisnt all possible bad data entries. The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */


#include <iostream>
#include "student.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>


using namespace std;


//For Spacing. Changing will change formatting, be careful!
const int SPACE = 11;
const int INC = 3;
const int WIDTH = 31;

//precision length of final grade
const int GRADEPER = 2;
const int ZERO = 0;



char returnGrade(double FGrade);


// ***************************************************************************
// * Function Name: returnGrade
// * Description: Takes in the final grade the student received and returns 
// *				letter grade student got.
// *
// * Parameter Description: Double Final grade value
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
char returnGrade(double FGrade)
{
	if(FGrade > 89)
		return 'A';
	else if(FGrade > 79)
		return 'B';
	else if(FGrade > 69)
		return 'C';
	else if(FGrade > 59)
		return 'D';
	else
		return 'F';
}


int main(void)
{
	

	string iName ="", oName="";
	//ask the user for the input file name
	cout << "Please enter the name of the input file." << endl;
	cout << "Filename: "; 
	cin >> iName;
	//Ask the user for the output file name;
	cout << "Please enter the name of the output file." << endl;
	cout << "Filename: ";
	cin >> oName;

	//Open the file
	ifstream iFile;
	iFile.open(iName.c_str());
	//The file is now open
	//Read the number of students in the list (first number of file)
	int stuSize = 0;
	iFile >> stuSize;
	//Now get rid of that delim
	iFile.ignore(256, '\n');

	//Create the array that will hold our Student List
	int cur_size = 0, capSize = stuSize;
			Student ** StuPtr = new Student*[stuSize+1];
	

	//*****************************
	//* Begin Every Student Loop  *
	//*****************************
	//For Every Student
	for(int i = 0; i < stuSize; i++)
	{
			char cur;
			char* LN;
			LN = new char[1];
			int c = 0;

			//Read in the last name, stopping only once you hit the comma ','
			cur = iFile.get();
			while(cur != ',')
			{
				
				LN[c] = cur;
				c++;
				cur = iFile.get();
			}
		//The last name has now been read in.
			//Read in the first name
			char* FN;
			FN = new char[1];
			int d = 0;
			char cur2;
			
			//Ignore the white space
			iFile.ignore(1);
			//Reset the 'Cur' char holder
					
			cur2 = iFile.get();
			while(cur2 != '\n')
			{
				
				FN[d] = cur2;
				d++;
				cur2 = iFile.get();
				
			}


				//*********************Everything Above works, except the first, last name (bugs buny) **********
				//Read the subject that the student deals in
				string sub;
				iFile >> sub;
				
				//Depending on what the subject is, create a new student under that subject
				if(sub == "Math")				
					StuPtr[cur_size] = new Math(FN,LN);
				else if(sub == "History")
					StuPtr[cur_size] = new History(FN,LN);
				else if(sub == "English")
					StuPtr[cur_size] = new English(FN,LN);
				else
					cout << "ERROR: There was an error reading the file" << endl;

				//Save the Grade of that student
				StuPtr[cur_size]->SaveGrade(iFile);
				//We have read in the grades. Now skip to next line.
				iFile.ignore(256,'\n');

				//Move on to the next student
				cur_size++;
	}

	//We have now read in everything we need, so we will close the input file.
	iFile.close();


	
	//*************************************************************
	//Let's open up the output file
	ofstream oFile;
	oFile.open(oName.c_str());

	//Print the summary output
	oFile << "Student Grade Summary" << endl;
	oFile << "---------------------" << endl << endl;
	oFile << "ENGLISH CLASS" << endl << endl;
	oFile << "Student                       Final     Final     Letter" << endl;
	oFile << "Name                          Exam      Avg       Grade " << endl;
	oFile << "--------------------------------------------------------" << endl;
	for(int i = 0; i <stuSize; i++)
	{
		if(StuPtr[i]->getSUBJECT() == ENGLISH)
		{
			string NAME = StuPtr[i]->getFNAME() + ' ' + StuPtr[i]->getLNAME();

			oFile << setw(WIDTH) << left << NAME 
			<< setw(3) << right << StuPtr[i]->getFinal() 
			<< setw(SPACE) << right << fixed << setprecision(GRADEPER) 
			 << StuPtr[i]->CalcGrade() << setprecision(ZERO) 
			<< setw(SPACE-3) << right << returnGrade(StuPtr[i]->CalcGrade()) << endl;
		}
	}
	oFile << endl << endl;


	//----------------------------------------------------------------------------
	oFile << "HISTORY CLASS" << endl << endl;
	oFile << "Student                       Final     Final     Letter" << endl;
	oFile << "Name                          Exam      Avg       Grade " << endl;
	oFile << "--------------------------------------------------------" << endl;

	for(int i = 0; i <stuSize; i++)
	{
		if(StuPtr[i]->getSUBJECT() == HISTORY)
		{
			string NAME = StuPtr[i]->getFNAME() + ' ' + StuPtr[i]->getLNAME();

			oFile << setw(WIDTH) << left << NAME 
			<< setw(3) << right << StuPtr[i]->getFinal() 
			<< setw(SPACE) << right << fixed << setprecision(GRADEPER) 
			 << StuPtr[i]->CalcGrade() << setprecision(ZERO) 
			<< setw(SPACE-3) << right << returnGrade(StuPtr[i]->CalcGrade()) << endl;
		}
	}

	oFile<< endl << endl;
	//----------------------------------------------------------------------------
	oFile << "MATH CLASS" << endl << endl;
	oFile << "Student                       Final     Final     Letter" << endl;
	oFile << "Name                          Exam      Avg       Grade " << endl;
	oFile << "--------------------------------------------------------" << endl;
	for(int i = 0; i <stuSize; i++)
	{
		if(StuPtr[i]->getSUBJECT() == MATH)
		{
			string NAME = StuPtr[i]->getFNAME() + ' ' + StuPtr[i]->getLNAME();

			oFile << setw(WIDTH) << left << NAME 
			<< setw(3) << right << StuPtr[i]->getFinal() 
			<< setw(SPACE) << right << fixed << setprecision(GRADEPER) 
			 << StuPtr[i]->CalcGrade() << setprecision(ZERO) 
			<< setw(SPACE-3) << right << returnGrade(StuPtr[i]->CalcGrade()) << endl;
		}
	}

//Delete dynamic memory
	delete []StuPtr;
cout << "Processing Complete" << endl;





}