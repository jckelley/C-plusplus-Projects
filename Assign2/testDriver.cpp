#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

int main(void)
{
  Date MyBirthday(2,18,1955);

  cout << MyBirthday << endl;
  /*
	int j;
	Date d1; 
	Date d3(1,1,2000);            // Leap Year and also to test decrement
  	Date d4(2,29,1900);           // Invalid Date
  	Date d5(12,31,2011);
  	Date d6(2,29,1999);
  	Date d7(2,29,2000);

  	cout << "******  Testing Constructors ********  " << endl;
      cout << " Showing d1 - Should be default date: ";
      d1.Show();
      cout << " Showing d3 - Should show January 1, 2000: ";
      d3.Show();
      cout << " Showing d4 - Should show default date: ";
      d4.Show();
      cout << " Showing d5 - Should show December 31, 2011: ";
      d5.Show();
      cout << "Should display default date";
      d6.Show();
      cout << "Should display Feb 29th 2000";
      d7.Show();
      cout <<  "This should display the julian date for 12/31/2011" << endl;
      d5.SetFormat('J');
      d5.Show();
      d1.Increment(400);
      d1.Show();
      d5.Increment(5);
      d5.SetFormat('D');
      d5.Show();
      cout << d5.Compare(d1) << endl;
      */

}