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

This file is to act with the 'student.h','driver.cpp' files. This class creates a simple student grade program 
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
#include <string>
#include <iomanip>
#include <cctype>
#include "student.h"
#include <fstream>


using namespace std;

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % STUDENT CLASS FUNCTIONS
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// ***************************************************************************
// * Function Name: Student 
// * Description: The default student constructor for a Student object. This 
// * 				function should never be called for the program to work
// * 				correctly.
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
Student::Student()
{
	FNAME=" ";
	LNAME=" ";

}

// ***************************************************************************
// * Function Name: Student
// * Description: The student constructor that should be used with corresponding
// *				class. Will create a student object and assign 'F' and 'L' 
// * 				to the first and last name, respectively. 
// *
// * Parameter Description: Two strings that carry the first and last name of 
// * 						student
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
Student::Student(const string F,const string L)
{

	FNAME = F;
	LNAME = L;

}
// ***************************************************************************
// * Function Name: getLNAME()
// * Description: Returns the last name of the student
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
string Student::getLNAME() const
{
	return LNAME;
}
// ***************************************************************************
// * Function Name: getFNAME()
// * Description: Returns the first name of the student.
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
string Student::getFNAME() const
{
	return FNAME;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % ENGLISH CLASS FUNCTIONS
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// ***************************************************************************
// * Function Name: English
// * Description: Creates English Student object extended from student class.
// * 				sets core values to 0 to intialize. 
// *
// * Parameter Description: First name, Last Name (Passed to Student Constructor)
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
English::English(const string FN,const string LN):Student(FN,LN)
{
	attendance = 0;
	project = 0;
	midterm = 0;
	final = 0;

}
// ***************************************************************************
// * Function Name: CalcGrade
// * Description: Calculates the grade for the English Student using the formula
// *				Attendence 10%, Project 30%, Midterm 30%, and Final 30% 
// * 				Returns the calculated final grade.
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
double English::CalcGrade()
{
	double finalgrade = 0;
	finalgrade = (attendance * 0.10) + (project * 0.30) + (midterm * 0.30) + (final * 0.30);
	return finalgrade;
}
// ***************************************************************************
// * Function Name: SaveGrade
// * Description: Will be passed a reference to a input file. Said file will 
// * 				then read in the appropiate amount of grades, saving them
// * 				to their respective variables.
// *
// * Parameter Description: Reference Inputfile
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
void English::SaveGrade(istream &refFile)
{
	double A = 0, P = 0, M = 0, F = 0;
	//You must read in attendance, project, midterm, and final
	refFile >> A >> P >> M >> F;
	//Now Save that to the class
	attendance = A;
	project = P;
	midterm = M;
	final = F;
}
// ***************************************************************************
// * Function Name: getSubject
// * Description: Returns the subject of the English student (English)
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
subject English::getSUBJECT() const
{
	return ENGLISH;
}
// ***************************************************************************
// * Function Name: getfinal
// * Description: Returns the final of the English student (private variable)
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
double English::getFinal()
{
	return final;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % HISTORY CLASS FUNCTIONS
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



// ***************************************************************************
// * Function Name: History
// * Description: Constructs History Student object (Extended from Student object)
// * 				Intializes private vars. to 0
// *
// * Parameter Description: First Name, Last name (Stored with Student Class)
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
History::History(const string FN,const string LN):Student(FN,LN)
{
	termpaper = 0;
	midterm = 0;
	final = 0;

}
// ***************************************************************************
// * Function Name: CalcGrade
// * Description: Calculates the grade of the History Student using the formula
// * 				TermPaper 25%, MidTerm 35%, Final 40%. Then returns final grade
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
double History::CalcGrade()
{
	double finalgrade = 0;
	finalgrade = (termpaper * 0.25) + (midterm * 0.35) + (final * 0.40);
	return finalgrade;
}
// ***************************************************************************
// * Function Name: SaveGrade
// * Description: Will be passed a reference to a input file. Said file will 
// * 				then read in the appropiate amount of grades, saving them
// * 				to their respective variables.
// *
// * Parameter Description: Reference Inputfile
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
void History::SaveGrade(istream &refFile)
{
	double T = 0, M = 0, F = 0;
	refFile >> T >> M >> F;
	termpaper = T;
	midterm = M;
	final = F;
}
// ***************************************************************************
// * Function Name: getSubject
// * Description: Returns the subject of History Student (History)
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
subject History::getSUBJECT() const
{
	return HISTORY;
}
// ***************************************************************************
// * Function Name: getFinal
// * Description: Returns numeric grade of final that student achieved
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
double History::getFinal()
{
	return final;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// % MATH CLASS FUNCTIONS
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// ***************************************************************************
// * Function Name: 
// * Description: 
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
Math::Math(string FN, string LN):Student(FN,LN)
{

}
// ***************************************************************************
// * Function Name: 
// * Description: 
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
double Math::CalcGrade()
{
	double finalgrade = 0;
	finalgrade = ( ((q1+q2+q3+q4+q5) /5) * 0.15) + (t1 * 0.25) + (t2 * 0.25) + (final * 0.35);
	return finalgrade;
}
// ***************************************************************************
// * Function Name: SaveGrade
// * Description: Will be passed a reference to a input file. Said file will 
// * 				then read in the appropiate amount of grades, saving them
// * 				to their respective variables.
// *
// * Parameter Description: Reference Inputfile
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Math::SaveGrade(istream &refFile)
{
	double quiz1 = 0, quiz2 = 0, quiz3 = 0, quiz4 = 0, quiz5 = 0, test1 = 0, test2 = 0, f = 0;
	refFile >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5 >> test1 >> test2 >> f;
	q1 = quiz1;
	q2 = quiz2;
	q3 = quiz3;
	q4 = quiz4;
	q5 = quiz5;
	t1 = test1;
	t2 = test2;
	final = f;
}
// ***************************************************************************
// * Function Name: getSubject
// * Description: Returns the Subject of the Math Major (Math)
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
subject Math::getSUBJECT() const
{
	return MATH;
}
// ***************************************************************************
// * Function Name: Get Final
// * Description: Returns the grade the student got on the Final exam for Math
// *
// * Parameter Description: None
// *
// * Date: 03/21/2013
// * Author: Joseph Kelley
// ***************************************************************************
double Math::getFinal()
{
	return final;
}


