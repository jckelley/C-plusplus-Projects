/* ========================================================================== */
/*	PROGRAM: Student Grade Class
	File: student.h
	Purpose: Class Constructor File

    AUTHOR: Joseph  Kelley
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 5
    DUE DATE: 03/22/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'student.cpp','driver.cpp' files. This class creates a simple student grade program 
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

using namespace std;
enum subject
{
	ENGLISH,
	HISTORY,
	MATH
};


class Student
{
public:
	Student();
	~Student();
	Student(const string,const string);
	virtual double CalcGrade()=0;
	virtual void SaveGrade(istream &)=0;
	virtual double getFinal()=0;
	virtual subject getSUBJECT() const { };
	string getLNAME() const;
	string getFNAME() const;
	string getSubject();

private:
	string FNAME;
	string LNAME;
	subject STUDENTSUBJECT;
	
};
// **************************************************************
// * Class English has Attendance, Project, Midterm, and Final
// **************************************************************
class English: public Student
{
public:
	English(const string,const string);
	double CalcGrade();
	void SaveGrade(istream &);
	subject getSUBJECT() const;
	double getFinal();
private:
	double attendance, project, midterm, final;
	

};
// **************************************************************
// * Class History has Term Paper, Midterm, and Final
// **************************************************************
class History: public Student
{
public:
	History(const string,const string);
	double CalcGrade();
	void SaveGrade(istream &);
	subject getSUBJECT() const;
	double getFinal();
private:
	double termpaper,midterm, final;

};
// **************************************************************
// * Class Math has 5 Quizzes, 2 tests, and 1 Final
// **************************************************************
class Math: public Student
{
public:
	Math(const string,const string);
	double CalcGrade();
	void SaveGrade(istream &);
	subject getSUBJECT() const;
	double getFinal();
private:
	double q1,q2,q3,q4,q5,t1,t2,final;
};