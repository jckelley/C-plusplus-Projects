
// driver.cpp -- 

#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

// *********************************************************************
// * Filename: driver.cpp 
// *                                                                   *
// * Description:  Proram designed to minimally test the  Date class:  *
// *   Creates constructors, increments, shows dates, sets formats,    *
// *   exercises the input functions and compares dates.               *
// *   Comment out code that has not been implemented yet to           *
// *   gradually test your class.                                      *
// *                                                                   *
// * Date:        May 29th, 2012                                       *
// * Programmer:  Dr.David Gaitros                                     *
// *                                                                   *
// * Disclaimer:  This code was written as part of the solution        *
// *              to programming problems assigned in Object Oriented  *
// *              Programming Course (COP 3330) as taught in the       *
// *              Computer Science Department at Florida State         *
// *              University.  The selling, sharing, distribution, or  *
// *              use of this code not authorized by the faculty of    *
// *              the Computer Science Department is explicitly        *
// *              forbidden and is considered a violation of the       *
// *              academic honor code.                                 *
// *********************************************************************
// *********************************************************************


int main() 
{
  int J; 
  Date d1;                      // Default Date
  Date d2(12);                  // One Parameter, day=1 , Year=2000
  Date d3(1,1,2000);            // Leap Year and also to test decrement
  Date d4(2,29,1900);           // Invalid Date
  Date d5(12,31,2011);          // End of Year to test increment
  
      cout << "******  Testing Constructors ********  " << endl;
      cout << " Showing d1 - Should be default date: ";
      d1.Show();
      cout << " Showing d2 - Should have month at 12 and rest default: ";
      d2.Show();
      cout << " Showing d3 - Should show January 1, 2000: ";
      d3.Show();
      cout << " Showing d4 - Should show default date: ";
      d4.Show();
      cout << " Showing d5 - Should show December 31, 2011: ";
      d5.Show();
  
    
      cout << "***** Test Input ******" << endl; 
      d1.Input(); 
      cout << "Input a number to increment the date by (Positive please): " << endl;
      cin >> J ;
      cin.ignore(80,'\n'); 
      cout << "Incrementing by " << J << endl; 
      d1.Increment(J);
      d1.SetFormat('D');
      cout << " *** Show the Increment worked - Format in D ** " << endl; 
      d1.Show();

      cout << "*** Set Format to T  and Display the results *** " << endl; 
      d1.SetFormat('T');
      d1.Show();
      cout << "** Set Format to L and Display the results *** " <<  endl; 
      d1.SetFormat('L');
      d1.Show();
      
      
       cout << "*** Setting Format back to T *** "<< endl;
       d1.SetFormat('T');
       d2.SetFormat('T');
       d3.SetFormat('T');
       d4.SetFormat('T');
       d5.SetFormat('T');
      
       cout << "*** d5 is current set at : " ;
       d5.Show(); 
       cout << "*** Increment d5 by 1 and Display the results ***" << endl; 
      
       d5.Increment(); 
       d5.Show();
       cout << "*** Increment d5 by 31 and Display the results ***" << endl; 
       d5.Increment(31);
       d5.Show();
       
       cout << "*** Shows that GetMonth,GetDay, and GetYear worked *** " << endl;
       cout << "The d4 Date is: " << d4.GetMonth() << '/'<<d4.GetDay()<<'/'<<d4.GetYear() << endl; 

       cout << endl;
       cout << "*** Showing the compares work by comparing a series of dates: *** " << endl; 
       cout << "d1 is = "; d1.Show();  cout << endl;
       cout << "d2 is = "; d2.Show(); cout << endl;
       cout << "d3 is = "; d3.Show();  cout << endl;
       cout << "d4 is = "; d4.Show();  cout << endl;
       cout << "d5 is = "; d5.Show();  cout << endl;
       if(d3.Compare(d4)==-1) cout << "d3" << " Is less then " << "d4" << endl; //False
       if(d4.Compare(d3)==1) cout << "d4" << " Is Grtr then " << "d3" << endl; //False
       if(d4.Compare(d5)==0) cout << "d4" << " Is Equal to  " << "d5" << endl; //False
       if(d1.Compare(d3)==-1) cout << "d1" << " Is Less then " << "d3" <<endl; //Pending User in
       else if (d1.Compare(d3)==1) cout << "d1" << " Is Greater than " << "d3" << endl;
       else if (d1.Compare(d3)==0) cout << "d1" << " Is equal to " << "d3" << endl;

     
      
        
   
  return 0;
}
