// ***********************************************************************
//  main6.cpp                                                            *
//  Bitarray Assignmnet test driver.                                     *
//  Original Code: Mr. Robert Myers.                                     *
//  Modified by Dr. David Gaitros on 4/2/13.                             *
//  Copyright (c) 2013 Florida State University. All rights reserved.    *
// ***********************************************************************
// *********************************************************************** 
#include "sieve.h"
#include "bitarray.h"
#include <iomanip> 
#include <iostream>
int GetPosInt(); 
void PrintPrimes(const BitArray & b, const int max); 

using namespace std;



int main(void)
{
    unsigned int  max,max2,counter=0;
    
    // ***********************************************************************
    // * Ask for a positive integer and create a bit array.                  *
    // * Preform the Sieve Algorithm on it.                                  *
    // *                                                                     *  
    // *********************************************************************** 
    max=GetPosInt(); 
    BitArray ba(max);
    Sieve(ba);                 
    // *********************************************************************
    // * Print out the bits using the overloaded << operator.              *
    // * and print out the prime numbers.                                  * 
    // *********************************************************************      
    cout << "The bit array looks like this: \n" << ba << endl; 
    // *********************************************************************
    // * Testing the == and != overload operators.                         *
    // *********************************************************************      
    
    PrintPrimes(ba,max); 
    cout << "\nNow...Lets see if your comparison operator works. \n ";
    cout << "We are going to have you enter another number to generate \n";
    cout << "Prime numbers" << endl; 
    max2 = GetPosInt(); 
    BitArray ba2(max2);
    Sieve(ba2);                    // find the primes (marking the bits)
    
    cout << "The bit array looks like this: \n"<< ba2 << endl; 
     
    cout << "PRINTING THE PRIME NUMBERS" <<endl; 
    PrintPrimes(ba2,max2); 
    cout << "\nChecking the overload == operator " <<endl; 
    if(ba==ba2) cout <<endl << "They are equal" << endl;
         else cout << endl<< "They are not equal" << endl;
    
    cout << "\nChecking the overload != operator " << endl; 
    if(ba!=ba2) cout << endl << "They are not equal" << endl;
    else cout << endl << "They are NOT not equal" << endl; 
     // *********************************************************************
    // * Check Unset, Set, Flip and Query                                   *
    // **********************************************************************         
    
    cout << "\nChecking the Unset member function by unsetting all bits" << endl;
    cout << "of the first array" << endl;
    cout << "NOTE: Only the bits up to and including the maximum value should be affected"<<endl; 
    for (int index=0; index<max; index++)
        ba.Unset(index); 
    cout << ba<< endl; 
    
    cout << "\nNow Checking the Set member function by setting all bits" << endl;
    cout << "of the first array" << endl;
    cout << "NOTE: Only the bits up to and including the maximum value should be affected"<<endl; 

    for (int index=0; index<max; index++)
        ba.Set(index); 
    cout << ba<< endl; 

    cout << "\nNow Checking the Flip member function by flipping every other bit" << endl;
    cout << "of the first array starting with bit 0 (zero)" << endl;
    cout << "NOTE: Only the bits up to and including the maximum value should be affected"<<endl; 
    
    for (int index=0; index<max; index=index+2)
        ba.Flip(index); 
    cout << ba<< endl; 
    
    cout << "\nNow Checking the Query member function" << endl;
    cout << "Printing out the number of the bits turned on.  Should be all odd numbers. " << endl;
    cout << "NOTE: Only the bits up to and including the maximum value should be affected"<<endl; 
    counter=0; 
    for (int index=0; index<max; index++)
        {
            if(ba.Query(index)) {
                counter++;    
               cout << setw(5) << index << ' ';}
            if(counter%5==0) {
                counter=0;  
               cout << endl;} 
        } 

    
    cout << "\nGoodbye!\n";
    return 0; 
    
}


// *****************************************************************************
// * Function Name: GetPosInt                                                  *
// * Description:  Asks the user to input a positive inteber.  Keeps asking    *
// *   until a correct value is entered and than returns the value.            *
// *                                                                           *
// * Date: April 1, 2013                                                       *
// * Author: Dr. David A. Gaitros                                              *
// *****************************************************************************

int GetPosInt() 
{
    int num; 
    cout << "Welcome to the PRIME NUMBER FINDER " << endl; 
    cout << "Enter a positive integer - The system will find all" << endl; 
    cout << "Prime numbers up to and including that number" << endl; 
    cout << "\nI N P U T->"; 
    cin >> num; 
    while (num <1 )
    {
        cout << "\nYou have enered an incorrect number, please re-enter" << endl; 
        cout << "I N P U T->";
        cin>>num;
    }
    return num; 
    
}
// *****************************************************************************
// * Function Name: PrintPrimes                                                *
// * Description:  Asks the user to input a positive inteber.  Keeps asking    *
// *   until a correct value is entered and than returns the value.            *
// *                                                                           *
// * Date: April 1, 2013                                                       *
// * Author: Dr. David A. Gaitros                                              *
// *****************************************************************************
void PrintPrimes(const BitArray & b, const int max)
{   int counter; 
    
    cout << "\nPrimes less than " << max << ':'<< '\n';
     for (int i = 0; i< max; i++)
     {   
       if (b.Query(i))
         {
           counter++;
           cout << i;
         
        if (counter % 8 == 0)
          {
            cout << '\n';
            counter = 0;
           }
          else
            cout << '\t';
      }
}
}