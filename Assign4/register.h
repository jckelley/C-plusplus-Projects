/* ========================================================================== */
/*	PROGRAM: Register Class
	File: register.h
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

#include "sale.h"


class Register
{

public:
	Register();
	~Register();
	Register(const int id, const double int_amt);

	int GetID() const;
	double GetAmount() const;
	void RingUpSale(const ItemType goods, const double item_price);
	void ShowLast() const;
	void ShowAll() const;
	void Cancel();
	double SalesTax(const int n) const;

private:

int id_num;
double cur_amt;

Sale * saleListPtr; //Pointer to array that holds sale List
int cur_Size, capacity; //The current size of the array (how many it holds)
						//The capacity of the array, how many it CAN hold

void Shrink();
void Grow();





};