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


#include "bitarray.h"
#include <cmath>



// ***************************************************************************
// * Function Name: Sieve
// * Description: The Sieve function uses the Sieve of Eratosthenes method of locating primes.
// * 				The method will divide each number by all of the other possible numbers in order 
// * 				to locate all of the prime numbers.
// *
// *
// * Parameter Description: BitArray Object to check Primes for.
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// ***************************************************************************
 void Sieve(BitArray &BA)
 {
 	//Find out how many numbers we are dealing with
 	int numTotal = (BA.Length()+1) * BYTE;

 	//Set all bits to 1
 	for(int i = 0; i <= numTotal; i++)
 		BA.Set(i);

 	//Turn off 0 and 1, they are special non-cases
 	BA.Unset(0);
 	BA.Unset(1);

 	//Make
 	//Go through each number, starting at 2 (we took care of 0 and 1 already!)

 	//Our dividing factor
 	for(int i = 2; i < sqrt(numTotal); i++)
 	{
 			//Our actual number
 		for(int b = 2; b <= numTotal; b++)
 		{
 			//If divisable by a number, than NOT
 			if(b%i == 0 && (b != i))
 				BA.Unset(b);
 		}

 	}




 }