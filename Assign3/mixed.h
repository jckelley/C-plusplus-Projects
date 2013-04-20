/* ========================================================================== */
/*	PROGRAM: Mixed Class
	File: mixed.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Springer
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 3
    DUE DATE: 02/15/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'mixed.h' file. This class will allow for minipulation of mixed
numbers such as ' 1 3/4' or 'One and Three Fourths'. This class will allow for input and ouput
of mixed numbers as well. 


INPUT

The iostream has been overloaded so the << operator can take in a mixed number object. The object
must be declared ahead of time as a Mixed number type. If the mixed number entered has a 0 denominator
( 1 1/0) or a double negative (-1, -1/1) the mixed number will be converted to the default, 0 0/1

OUTPUT

The class allows for output via an overloaded ostream << operator. The object will be printed as a regular 
fraction ('3/4') if no whole number is present. Otherwise it will output the entire mixed number as
'1 3/4'.

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user. This class does protect
the integrity of the data with some bad data-checking such as with the mixed number, but is not fully debugged
agaisnt all possible bad data entries. The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */



#include <iostream>

using namespace std;

//DEFAULT CONSTANTS
const int DEFAULT_VALUE = 0;
const int DEFAULT_D = 1;

class Mixed
{
	
public:
	//Mixed with 1 parameter, default is 0
	Mixed(int VAL = DEFAULT_VALUE);
	//Mixed with all 3 parameters 
	Mixed(int VAL, int NUM, int DEM);
	double Evaluate();
	void Simplify();
	void ToFraction();


	//Overload of >> operator for reading mixed numbers from istream
	friend istream &operator>>(istream &, Mixed &);
	//Overload of << operator for displaying mixed numbers from ostream
	friend ostream &operator<<(ostream &, const Mixed &);
	//Overload of < operator for comparing mixed numbers
	friend bool operator<(const Mixed &, const Mixed &);
	//Overload of <= operator for comparing mixed numbers
	friend bool operator<=(const Mixed &, const Mixed &);
	//Overload of > operator for comparing mixed numbers
	friend bool operator>(const Mixed &, const Mixed &);
	//Overload of >= operator for comparing mixed numbers
	friend bool operator>=(const Mixed &, const Mixed &);
	//Overload of == operator for comparing mixed numbers
	friend bool operator==(const Mixed &, const Mixed &);
	//Overload of != operator for comparing mixed numberss
	friend bool operator!=(const Mixed &, const Mixed &);

	//Overload of + operator for minipulating mixed numbers
	friend  Mixed operator +(const Mixed &, const Mixed &);
	//Overload of - operator for minipulating mixed numbers
	friend  Mixed operator -(const Mixed &, const Mixed &);
	//Overload of * operator for minipulating mixed numbers
	friend  Mixed operator *(const Mixed &, const Mixed &);
	//Overload of / operator for miniuplating mixed numbers
	friend  Mixed operator /(const Mixed &, const Mixed &);

	//Overload for ++ operator for incrementing mixed numbers
	 Mixed operator++();
	 Mixed operator++(int);
	//Overload for -- operator for decrementing mixed numbers
	 Mixed operator--();
	 Mixed operator--(int);





private:
	int whole, num, dem;



};