/* ========================================================================== */
/*	PROGRAM: Assignment 6
	File: sieve.h,bitarray.h,bitarray.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Springer
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 6
    DUE DATE: 04/05/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'sieve.h','bitarray.h', and 'bitarray.cpp' files. This class creates an
array of 8-bit chars. The program then manipulates these bits using Sieve's header to find the
prime numbers

INPUT

The program will the number that the user wishes to count up too. If they wish to find all the
prime numbers beneath 45, they will enter '45'

OUTPUT

This class will allow for output of data stored, such as what the prime numbers are under the input number

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user. This program is not fully debugged
agaisnt all possible bad data entries. The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */

#include <iostream>
#include "bitarray.h"


// ***************************************************************************
// * Function Name: Mask
// * Description: Creates a char mask that we can use for manipulating bits
// *
// *
// * Parameter Description: Index of bit we wish to check inside Byte
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
const unsigned Mask(unsigned int num)
{
return (1 << num);
}

// ***************************************************************************
// * Function Name: BitArray
// * Description: BitArray constructor that creates a BitArray object. IT sets
// * 				all bits to 0, and stores it in barray pointer array
// *
// *
// * Parameter Description: Int, min numbers of bit you wish to count too
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
BitArray::BitArray(unsigned int n)
{

	//We start at 0, so we must add 1
	n++;
	int charz = 0;

	//If it does not "perfectly" fit
	if( (n % BYTE) != 0)
		charz =(n / BYTE);
	else
		charz = (n / BYTE) + 1;

	//Tell the program our array size
	arraySize = n;

	//Now dynamically create the array with full byte size
	barray = new unsigned char[charz];

	//Now intialize bytes to 0
	for(int i = 0; i < charz; i++)
	{
		barray[i] = (int) 0;
	}

}
// ***************************************************************************
// * Function Name: BitArray Copy
// * Description: This is the Copy Constructor for the BitArray object. It will 
// * 				create a new bitArray object that is a duplicate of the one 
// * 				given
// *
// *
// * Parameter Description: BitArray Object we wish to copy from
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
BitArray::BitArray(const BitArray &BA)
{
	BitArray(BA.arraySize);

}
// ***************************************************************************
// * Function Name: BitArray Deconstructor
// * Description: Deconstructrs the BitArray object at endtime. Deletes barray pointer array
// *
// *
// * Parameter Description: None
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
BitArray::~BitArray()
{
	delete []barray;
}
// ***************************************************************************
// * Function Name: Length
// * Description: Returns the length of the BitArray object, or how far we wanted to count too
// *
// *
// * Parameter Description: None
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
unsigned int BitArray::Length() const
{

	return (int)(arraySize/8);
}
// ***************************************************************************
// * Function Name: Set
// * Description: Sets the 'Bit' of the given index to 1
// *
// *
// * Parameter Description: Index of Bit we wish to set
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
void BitArray::Set(unsigned int index)
{
		//Set the Indexed Bit to ON
		barray[index/BYTE] |= 0x01 << (index%BYTE);

}
// ***************************************************************************
// * Function Name: Unset
// * Description: changes the indexed bit back to 0
// *
// *
// * Parameter Description: Indexed bit number we wish to change
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
void BitArray::Unset(unsigned int index)
{
	barray[index/BYTE] &= ~(1 << (index%BYTE) );

}
// ***************************************************************************
// * Function Name: Flip
// * Description: Changes the bit to the opposite value
// *
// *
// * Parameter Description: Indexed bit we wish to switch
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
void BitArray::Flip(unsigned int index)
{
	Query(index) ? Unset(index) : Set(index);

}
// ***************************************************************************
// * Function Name: Query
// * Description: Returns true if bit is turned 'on' (1) or else false (0)
// *
// *
// * Parameter Description: Indexed bit we wish to query
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
bool BitArray::Query(unsigned int index) const
{
    	bool result;
    	if (barray[(index/BYTE)] & Mask(index%8))
        		result = true;
        else
        		result = false;

        	return result;
}
// ***************************************************************************
// * Function Name: << Overloader
// * Description: Displays all of the bytes in order, displaying each bit
// *
// *
// * Parameter Description: Ostream operator, BitArray Object we wish to display
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
ostream &operator<<(ostream& os, const BitArray& a)
{
		 for (int i = 1; i <= a.Length(); i++)
        {
                char char_to_print = a.barray[i];

                for (int bit = 0; bit < 8; bit++)
                {
                	//Make sure we are in bounds!
                	if(( (i*BYTE) + bit <= a.arraySize))
                	{
                        os << (char_to_print & 0X01);
                        char_to_print >>= 1;
                    }
                    else
                    	cout << 0;
                }
                
        }
	return os;

}
// ***************************************************************************
// * Function Name: == Overloader
// * Description: checks to see if the arraysize variable of the two BitArray objects are equal
// *
// *
// * Parameter Description: Two BitArray objects we wish to compare
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
bool operator==(const BitArray &BA1, const BitArray &BA2)
{
		//Just make sure the array size is equal

	if(BA1.arraySize == BA2.arraySize)
		return true;
	else
		return false;

}
// ***************************************************************************
// * Function Name: != overloader
// * Description: Checks to see if the two arraysize variables are NOT equal
// *
// *
// * Parameter Description: Two BitArray objects we are comparing
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
bool operator!=(const BitArray &BA1, const BitArray &BA2)
{
	if(BA1.arraySize == BA2.arraySize)
		return false;
	else
		return true;

}
// ***************************************************************************
// * Function Name: Assignment Overloader
// * Description: Assigns arraysize variable of one BitArray object to Another
// *
// *
// * Parameter Description: Bitarray Object we wish to assign
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************

void operator=(const BitArray &BA)
{
	arraySize = BA.arraySize;

}
