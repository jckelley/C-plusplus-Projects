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

// ***************************************************************************
// * Function Name:  Draw1 function:
// * Description: This function is used in the special circumstance that only the length is 1, thus only 1 
// * 				border is needed.
// *
// * Parameter Description: The border char
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Draw1(const char B)
{
	cout << B << endl;
}
// ***************************************************************************
// * Function Name:  Draw2 function:
// * Description: This function is used in the special circumstance that only the length is 2, thus only 2
// * 				border char are needed.
// *
// * Parameter Description: The border char
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Draw2(const char B)
{
	cout << SPACE << B << SPACE << endl;
	cout << B << SPACE << B << endl;
	cout << SPACE << B << SPACE << endl;
}
// ***************************************************************************
// * Function Name:  Space function:
// * Description: This function is used to output multiple spaces at one time. A number is inputted as to how many spaces
// * 				there are, and the computer outputs them in a for loop.
// *
// * Parameter Description: an int N that says how many spaces we need
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Space(const int n)
{
	for(int i = 0; i < n; i++)
		cout << SPACE;
}
// ***************************************************************************
// * Function Name:  DrawRest function:
// * Description: This acts as our primary draw function for the diamond image. This function will draw the entire diamond and is called
// * 				when we have diamonds longer than 2. The function is heavily commented to help follow along with the algorithm in place.

// * Parameter Description: The size of the diamond (S), border char(B) and fill char (F)
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void DrawRest(const int S,const char B, const char F)
{
	Space(S-1);
	cout << B << endl;
	int radius = (S*2)-2;
	int totDots = (S-2);
	int curDots = 0;
	//For each line, minus a space
	for(int s = (S-2); s >= 0; s--) 
	{
		//Go to where the RIGHT border should be
		Space(s);
		//Write the RIGHT border
		cout << B; 
			
			//Write a Space. there is always at least 1 space.
			Space(1); 
			int a = curDots;
				while(a>0)
				{
					cout << F; 
					Space(1);
					a--;
				}
				//Write the LEFT border, and endline
			cout << B << endl; 
			
			if(curDots < totDots)
				curDots++;
	} //------------------------------- After this, you have completed the top half of the diamond
	curDots=(totDots-1);
	//for Every Line underneath
	for(int s = 1;s <=(S-2);s++)
	{
		//Go to where the RIGHT border should be
		Space(s); 
		 //Write the RIGHT border
		cout << B;
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
// ***************************************************************************
// * Function Name:  SetSize function:
// * Description: This function changes the size of the diamond
// *
// * Parameter Description: an int S that is the proposed new size
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Diamond::SetSize(const int S)
{
	//Exception Handler to see if int S is valid
	try{
		if(S < MINSIZE || S > MAXSIZE)
			throw S;
		else
			Dsize = S;
	}
	catch(int e)
	{
		cout << "ERROR: Size of Diamond is out of bounds. Resetting to " << MINSIZE << endl;
	 	Dsize = MINSIZE;
	}
}
// ***************************************************************************
// * Function Name:  Diamond Constructor function:
// * Description: This constructor is used to create a new Diamond. It goes through a simple integrity test to ensure the data
// * 				entered is valid among the set parameters.
// *
// * Parameter Description: The size of the diamond (S), border char(B) and fill char (F)
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
Diamond::Diamond(const int S, const char F, const char B)
{
	//Exception Handler to see if int S is valid
	try{
		if(S < MINSIZE || S > MAXSIZE)
			throw S;
		else
			Dsize = S;
	}
	catch(int e)
	{
		cout << "ERROR: Size of Diamond is out of bounds. Resetting to " << MINSIZE << endl;
	 	Dsize = MINSIZE;
	}

	//Exception Handler to check if the char F is valid
	try{
	if(F < LOWERBOUND || F > UPPERBOUND)
		throw F;
	else
		Dborder = F;
	}
	catch(char e)
	{
		Dborder = '*';
		cout << "ERROR: Entered Char is out of bounds. Resetting to \'*\'" << endl;
	}
	
	//Exception handler to see if char B is valid
	try{
	if(B < LOWERBOUND || B > UPPERBOUND)
		throw B;
	else
		Dfill = B;
	}
	catch(char e)
	{
		Dfill = '*';
		cout << "ERROR: Entered Char is out of bounds. Resetting to \'#\'" << endl;
	}

	
}
// ***************************************************************************
// * Function Name:  GetSize function:
// * Description: Returns the size of the function
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
int Diamond::GetSize()
{
	return Dsize;
}
// ***************************************************************************
// * Function Name:  Perimeter function:
// * Description: Calculates and returns the Perimeter of the diamond
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
int Diamond::Perimeter()
{
	int a = Dsize * 4;
	return a;
}
// ***************************************************************************
// * Function Name:  Area function:
// * Description: Calculates and returns the Area of the diamond
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************

double Diamond::Area()
{
	double a = (2 * Dsize * Dsize * sqrt(3.0)/4);
	return a;
}
// ***************************************************************************
// * Function Name:  Grow function:
// * Description: Increases size by 1, except if it goes over the MAXSIZE variable
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Diamond::Grow()
{
	try{
	if(Dsize > MAXSIZE) throw Dsize;
	else
		Dsize++;
	}
	catch(int e)
	{
		Dsize = MAXSIZE;
		cout << "\'Grow\' Function caused out of bounds exception. Size reset to " << MAXSIZE << endl;
	}

}
// ***************************************************************************
// * Function Name:  Shrink function:
// * Description: Decreases size of diamond by 1, except if it goes under MINSIZE
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Diamond::Shrink()
{
	try{
		if(Dsize-1 > MINSIZE) throw Dsize;
		else
			 Dsize--;

		}
	catch(int e)
	{
		Dsize = MINSIZE;
		cout << "\'Shrink\' Function caused out of bounds exception. Size reset to "<<MINSIZE<< endl;
	}
		
}
// ***************************************************************************
// * Function Name:  SetBorder function:
// * Description: Sets the border of the function, ensures agaisnt bad bound checking
// *
// * Parameter Description: the char 'border' if of the new border char we want
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Diamond::SetBorder(const char border)
{
	//Exception handler to see if char B is valid
	try{
		if(border < LOWERBOUND || border > UPPERBOUND)
			throw border;
		else
			Dborder = border;
	}
	catch(char e)
	{
		Dborder = '*';
		cout << "ERROR: Entered Char is out of bounds. Resetting to \'*\'" << endl;
	}
}

// ***************************************************************************
// * Function Name:  Setfill function:
// * Description: Changes the fill of the diamond. It goes through a data check first in order to ensure
// * 				the integrity of the fill.
// *
// * Parameter Description: char 'fill' of the new char we want to set as our fill.
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Diamond::SetFill(const char fill)
{
	//Exception handler to see if char B is valid
	try{
		if(fill < LOWERBOUND || fill > UPPERBOUND)
			throw fill;
		else
			Dfill = fill;
	}
	catch(char e)
	{
		Dfill = '#';
		cout << "ERROR: Entered Char is out of bounds. Resetting to \'#\'" << endl;
	}
}
// ***************************************************************************
// * Function Name:  Draw function:
// * Description: Draws the image to the terminal. It goes through a switch, as there are special cases for a single and double sided diamond.
// * 				Everything else is routed through the DrawRest() function.
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
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
// ***************************************************************************
// * Function Name:  Summary function:
// * Description: Prints a summary of the dimaond include Size, Perimeter, Area, and prints image of diamond..
// *
// * Parameter Description: None
// *
// * Date: 04/23/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Diamond::Summary()
{
	cout << "Size of dimaond's side = " << Dsize << " units." << endl;
	cout << "Perimeter of diamond = " << Perimeter() << " units." << endl;
	cout << "Area of diamond = " << Area() << " units." << endl;
	cout << "The Diamond looks like: " << endl;
	Draw();

}
