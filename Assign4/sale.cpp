/* ========================================================================== */
/*	PROGRAM: Register Class
	File: sale.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Kelley
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 4
    DUE DATE: 03/01/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'register.h','sale.h', and 'sale.cpp' files. This class creates a simple register program 
that allows for storing of sales and sale data. This class will have both input and output values,
entered by the user.

INPUT

The program will input price and sale data, storing these values in a dynamically created array.
This input will be stored until the program terminates.


OUTPUT

This class will allow for output of data stored, such as sale type values as price, item, and tax.

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user. This class does protect
the integrity of the data with some bad data-checking such as with the itemType, but is not fully debugged
agaisnt all possible bad data entries. The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */

#include <iostream>
#include "sale.h"
#include <string>
#include <iomanip>

using namespace std;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//							Constant Global Variables
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

const double SALES_TAX = .07;
const string TAB = "     ";
const char SP = ' ';


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//							Manual Function Protypes
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


string ItemString(ItemType x);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//								Manual Functions
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ***************************************************************************
// * Function Name: ItemString
// * Description: This item returns a string with the name of the Item
// *
// * Parameter Description: Passes an Item Type
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
string ItemString(ItemType x)
{
	string item = "";
	switch(x)
		{
			case BOOK:
				item = "Book";
				break;
			case DVD:
				item = "DVD";
				break;
			case SOFTWARE:
				item = "Software";
				break;
		}
		return item;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//									CLASS FUNCTIONS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// ***************************************************************************
// * Function Name: Sale Constructor
// * Description: This Sale Constructor creates a Sale object and sets the core
// * 				 variables to 0.00;
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
Sale::Sale()
{
	price = 0.00;
	tax = 0.00;
	total = 0.00;
}
// ***************************************************************************
// * Function Name: MakeSale
// * Description: This function enters data into a Sale object, allowing it to 
// * 				store the ItemType and Price
// *
// * Parameter Description: Item being rung up, and Amount of item
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Sale::MakeSale(ItemType x, double amt)
{
	item = x;
	if(x == CREDIT)
	{
		tax = 0;
		price = (-1) * amt;
		total = price;
	}
	else
	{
		tax = SALES_TAX * amt;

	price = amt;
	total = price + tax;
	}

}
// ***************************************************************************
// * Function Name: Item
// * Description: Returns the Item of the Sale Object
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
ItemType Sale::Item()
{
	return item;
}
// ***************************************************************************
// * Function Name: Price
// * Description: Returns the Price of the Sale Object
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
double Sale::Price()
{
	return price;
}
// ***************************************************************************
// * Function Name: Tax
// * Description: Returns the tax calculated from the Price of the item
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
double Sale::Tax()
{
	return tax;
}
// ***************************************************************************
// * Function Name: Total
// * Description: Returns the Total (Price + Tax) of the Sale Object
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
double Sale::Total()
{
	return total;
}
// ***************************************************************************
// * Function Name: Display
// * Description: Writes out the Item, Price, Tax, and Total of the sale object
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Kelley
// ***************************************************************************
void Sale::Display()
{
	
	if(item != CREDIT)
	{
		cout.unsetf(ios::fixed);
		cout << ItemString(item) << TAB << '$' << SP << price << "  Tax:  $ " << fixed << setprecision(2)  << tax << "   Total:  $ " << total << endl;
		

	}
	else
		cout << "CREDIT" << TAB << "<$ " << price << ">     Tax:   $ " << tax << "    Total: <$ " << price << '>' << endl;
}