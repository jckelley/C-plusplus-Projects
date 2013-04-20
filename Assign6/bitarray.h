/* ========================================================================== */
/* PROGRAM: Assignment 6
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

#ifndef _BITARRAY_H
#define _BITARRAY_H
 
#include <iostream>
using namespace std;

const int BYTE = 8;

class BitArray
{
   friend ostream& operator<< (ostream& os, const BitArray& a);
   friend bool operator== (const BitArray&, const BitArray&);
   friend bool operator!= (const BitArray&, const BitArray&);

public:
   BitArray(unsigned int n);    // Construct an array that can handle n bits
   BitArray(const BitArray&);   // copy constructor
   ~BitArray();                 // destructor

   BitArray& operator= (const BitArray& a);  // assignment operator

   unsigned int Length() const;            // return number of bits in bitarray

   void Set   (unsigned int index);        // set bit with given index to 1
   void Unset (unsigned int index);        // set bit with given index to 0
   void Flip  (unsigned int index);        // change bit (with given index)
   bool Query (unsigned int index) const;  // return true if the given bit
					   //  is set to 1, false otherwise

private:
   unsigned char* barray;		   // pointer to the bit array
   int arraySize;
};

#endif
