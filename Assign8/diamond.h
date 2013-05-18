/*
Code Author: Joseph C Kelley

Purpose: This is the class header file for the corresponding file 'diamond.cpp' that is to be kept
along with it. This class is meant to create a Diamond using ASCII characters and then be able to
manipulate it using functions such as 'Grow','Shrink' and resetting the border.

Adapted from: Dr. Gaitros 
Portions of this code were inspired/adapted by code samples from Dr. David Gaitros at
Florida State University. 

*/




#include <iostream>
using namespace std;


//Constant Definitions:
const char LOWERBOUND='!';
const char UPPERBOUND='~';
const int PADDNIGSIZE=80;
const int SIZE1=1;
const int SIZE2=2;
const int MINSIZE=1;
const int MAXSIZE=39;
const char DEFAULTBORDER='#';
const char DEFAULTFILL='*';


class Diamond
{
public: 
	Diamond();
	Diamond(const int, const char = '#', const char = '*');
	int GetSize();
	int Perimeter();
	double Area();
	void Grow();
	void Shrink();
	void SetBorder(char border);
	void SetFill(char fill);
	void Draw();
	void Summary();

private:
	int Dsize;
	char Dborder;
	char Dfill;

};

