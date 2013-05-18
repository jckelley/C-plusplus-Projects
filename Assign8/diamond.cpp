/*
Code Author: Joseph C Kelley

Purpose: This is the class declaration file for the corresponding file 'diamond.h' that be kept
along with it. This class is meant to create a Diamond using ASCII characters and then be able to
manipulate it using functions such as 'Grow','Shrink' and resetting the border.

Adapted from: Dr. Gaitros 
Portions of this code were inspired/adapted by code samples from Dr. David Gaitros at
Florida State University. 

*/


#include "diamond.h"
#include <iostream>
#include <cmath>


using namespace std;

#define SPACE " "
//================================================================
//NON-CLASS FUNCTIONS OR LOCAL FUNCTIONS
//================================================================
/**************************
This function will accept a char and run it through the parameters set forth in the class
definition file. It will return a true or false value depending on if the char falls
in the range of the allowed input.

************************* */
bool validchar(const char inchar)
{
	if(inchar >= LOWERBOUND && inchar <= UPPERBOUND)
		return true;
	else
		return false;
}
/**************************
validSize function:
This function will receive a number and check to see if that number is within the allowed range that
is given to us in the class header file. If the number is in the range, it will return said number.
if the number is out of range, it will round it down/up to the nearest acceptable number.

************************* */
int validSize(const int givenSize)
{
	if(givenSize >=MINSIZE && givenSize <= MAXSIZE)
		return givenSize;
	else if (givenSize < 1)
	{
		return 1;
		cout << "ERROR: Too low of a number entered. Number set to 1" << endl;
	}
	else
	{
		return 39;
		cout << "ERROR: Too high of a number entered. Number set to 39" << endl;
	}
}
/**************************
Draw1 function:
This function is used in the special circumstance that only the length is 1, thus only 1 
border is needed.

************************* */
void Draw1(const char B)
{
	cout << B << endl;
}
/**************************
Draw2 function:
This function is used in the special circumstance that only the length is 2, thus only 2
border char are needed.

************************* */
void Draw2(const char B)
{
	cout << SPACE << B << SPACE << endl;
	cout << B << SPACE << B << endl;
	cout << SPACE << B << SPACE << endl;
}
/**************************
Space function:
This function is used to output multiple spaces at one time. A number is inputted as to how many spaces
there are, and the computer outputs them in a for loop.

************************* */
void Space(int n)
{
	for(int i = 0; i < n; i++)
		cout << SPACE;
}
/**************************
DrawRest function:
This acts as our primary draw function for the diamond image. This function will draw the entire diamond and is called
when we have diamonds longer than 2. The function is heavily commented to help follow along with the algorithm in place.

************************* */
void DrawRest(const int S,const char B, const char F)
{
	Space(S-1);
	cout << B << endl;
	int radius = (S*2)-2;
	int totDots = (S-2);
	int curDots = 0;
	for(int s = (S-2); s >= 0; s--) //For each line, minus a space
	{
		Space(s);//Go to where the RIGHT border should be
		cout << B; //Write the RIGHT border
			
			Space(1); //Write a Space. there is always at least 1 space.
			int a = curDots;
				while(a>0)
				{
					cout << F; 
					Space(1);
					a--;
				}
			cout << B << endl; //Write the LEFT border, and endline
			
			if(curDots < totDots)
				curDots++;
	} //------------------------------- After this, you have completed the top half of the diamond
	curDots=(totDots-1);
	for(int s = 1;s <=(S-2);s++)//for Every Line underneath
	{
		Space(s); //Go to where the RIGHT border should be
		cout << B; //Write the RIGHT border
		Space(1);
		int a = curDots;
		while(a>0)
		{
			cout <<F;
			Space(1);
			a--;
		}
			cout << B << endl;

			if(curDots > 0)
				curDots--;
	}
	//Write the final dot underneath
	Space(S-1);
	cout << B << endl;
}
/**************************
Diamond function:
This constructor is used to create a new Diamond. It goes through a simple integrity test to ensure the data
entered is valid among the set parameters.

************************* */

Diamond::Diamond(const int S, const char F, const char B)
{
	Dsize = validSize(S);

	if(validchar(F))
		Dborder=F;

	if(validchar(B))
		Dfill=B;
}
/**************************
GetSize function:
Returns the size of the function

************************* */
int Diamond::GetSize()
{
	return Dsize;
}
/**************************
Perimeter function:
Calculates and returns the Perimeter of the diamond

************************* */
int Diamond::Perimeter()
{
	int a = Dsize * 4;
	return a;
}/**************************
Area function:
Calculates and returns the Area of the diamond

************************* */

double Diamond::Area()
{
	
	
	double a = (2 * Dsize * Dsize * sqrt(3.0)/4);
	return a;
}
/**************************
Grow function:
Increases the border length of the diamond by 1

************************* */
void Diamond::Grow()
{
	if(Dsize+1 < 40)
		Dsize++;

}
/**************************
Shrink function:
Decreases the border length of the diamond by 1

************************* */
void Diamond::Shrink()
{
	if(Dsize-1 > 0)
		Dsize--;
		
}
/**************************
Setborder function:
Changes the border of the diamond. It goes through a data check first in order to ensure
the integrity of the border.

************************* */
void Diamond::SetBorder(char border)
{
	if(validchar(border))
		Dborder = border;
	else
		Dborder = DEFAULTBORDER;
}
/**************************
SetFill function:
Changes the fill of the diamond. It goes through a data check first in order to ensure
the integrity of the fill.

************************* */
void Diamond::SetFill(char fill)
{
	if(validchar(fill))
		Dfill = fill;
	else
		Dfill = DEFAULTFILL;
}
/**************************
Draw function:
Draws the image to the terminal. It goes through a switch, as there are special cases for a single and double sided diamond.
Everything else is routed through the DrawRest() function.

************************* */
void Diamond::Draw()
{
	
	switch(GetSize())
	{
		case 1:
			Draw1(Dborder);
		break;
		case 2:
			Draw2(Dborder);	
		break;
		default:
		DrawRest(Dsize,Dborder,Dfill);



	}





}
/**************************
Summary function:
Prints a summary of the dimaond include Size, Perimeter, Area, and prints image of diamond.

************************* */
void Diamond::Summary()
{
	cout << "Size of dimaond's side = " << Dsize << " units." << endl;
	cout << "Perimeter of diamond = " << Perimeter() << " units." << endl;
	cout << "Area of diamond = " << Area() << " units." << endl;
	cout << "The Diamond looks like: " << endl;
	Draw();

}
