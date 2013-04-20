/* ========================================================================== */
/*	PROGRAM: Register Class
	File: register.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Springer
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




#include "register.h"
#include <iostream>
using namespace std;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//									GLOBAL CONSTANTS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#define NO_SALE_ERROR cout << "ERROR: NO SALES HAVE BEEN ENTERED" << endl;

const int INC = 5;


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//									CLASS FUNCTIONS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ***************************************************************************
// * Function Name: Register
// * Description: Creates a new Register object. Set's current size to 0, 
//*					capactiy to the increment number, and create a new array
//*					of Sales
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
Register::Register()
{

	cur_Size = 0;
	capacity = INC;
	//Every Register will have it's own Sale List
	saleListPtr = new Sale[capacity];
}
// ***************************************************************************
// * Function Name: Register Deconstructor 
// * Description: Deconstruct's the Register Object, deletes dynamically 
// * 				created memory during run-time.
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
Register::~Register()
{
	delete []saleListPtr; 
}
// ***************************************************************************
// * Function Name: Register Constructor
// * Description: Creates a Register object, set's Register ID and intial
// * 				amount to corresponding private variables.
// *
// * Parameter Description: Register id and intial amount in Reisger
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
Register::Register(const int id, const double int_amt)
{
	id_num = id;
	cur_amt = int_amt;

	cur_Size = 0;
	capacity = INC;
	//Every Register will have it's own Sale List
	saleListPtr = new Sale[capacity];
}
// ***************************************************************************
// * Function Name: GetID
// * Description: Returns ID of Register Object
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
int Register::GetID() const
{
	return id_num;
}
// ***************************************************************************
// * Function Name: GetAmount	
// * Description: Returns current amount of Money in Register
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
double Register::GetAmount() const
{
	return cur_amt;
}
// ***************************************************************************
// * Function Name: RingUpSale
// * Description: Creates a new sale object in our Array of sales for this 
// * 				Register object. Stores the item and price in this sales
// * 				object. 
// *
// * Parameter Description: Item being rung up, Price of Item
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
void Register::RingUpSale(const ItemType item_type, const double item_price)
{
	
	if(cur_Size == capacity) //If we are out of sale slots, make more!
		Grow();

	saleListPtr[cur_Size].MakeSale(item_type,item_price); //Make the Sale

		cur_amt += saleListPtr[cur_Size++].Total(); //Subtract the sale total from our register!


}
// ***************************************************************************
// * Function Name: ShowLast
// * Description: Displays the Last Sale in the Sale Array. If there is no 
// * 				Sale (0 sales) then display an error
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
void Register::ShowLast() const
{
	if(cur_Size != 0)
	saleListPtr[(cur_Size - 1)].Display();
	else
	cout << "Error: No Sales Have Been Made Yet! " << endl;

}
// ***************************************************************************
// * Function Name: ShowAll
// * Description: Displays all Sales in sale array. If no sales, Display Error
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
void Register::ShowAll() const
{
	if(cur_Size != 0)
		for(int i = 0; i < cur_Size; i++)
			saleListPtr[i].Display();
	else
		NO_SALE_ERROR;

}
// ***************************************************************************
// * Function Name: Cancel
// * Description: Deletes the last sale in the Sale Array
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
void Register::Cancel()
{
	if(cur_Size != 0)
	{
		cur_amt -= saleListPtr[--cur_Size].Total();

		if(cur_Size < (capacity - INC))
		Shrink();
	}

	else
			NO_SALE_ERROR;


}
// ***************************************************************************
// * Function Name: SalesTax
// * Description: Displays the Sales Taxtotal of the last 'n' amount of Sales
// *
// * Parameter Description: The amount of Sales you wish to find total SalesTax
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
double Register::SalesTax(const int n) const
{
	double TotTax = 0.00;

	if(cur_Size != 0)
		for(int i = 0; i < cur_Size; i++)
			TotTax += saleListPtr[i].Tax();
	else
		NO_SALE_ERROR;


	return TotTax;
}
// ***************************************************************************
// * Function Name: Shrink
// * Description: Shrinks the SalesArray by 'INC' variable
// *
// * Parameter Description: NONE
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
void Register::Shrink()
{

	static Sale * temparray; // Our temp bucket for transfer of array
	temparray = new Sale [capacity - INC];

	for(int i = 0; i < cur_Size; i++) // We transfer everything over to new array
		temparray[i] = saleListPtr[i];


	delete [] saleListPtr; // Deletes the ADDRESS, not data per say
	saleListPtr = temparray;
	capacity -= INC;
	cout << "Decreasing Size by " << INC << endl;

}
// ***************************************************************************
// * Function Name: Grow
// * Description: Increases Sales Array by 'INC' Variable
// *
// * Parameter Description: None
// *
// * Date: 02/24/2013
// * Author: Joseph Springer
// ***************************************************************************
void Register::Grow()
{
	static Sale * temparray; // Our temp bucket for transfer of array
	temparray = new Sale [INC + cur_Size];

	for(int i = 0; i < cur_Size; i++) // We transfer everything over to new array
		temparray[i] = saleListPtr[i];


	delete [] saleListPtr; // Deletes the ADDRESS, not data per say
	saleListPtr = temparray;
	capacity += INC;
	cout << "Increasing Size by " << INC << endl;



}