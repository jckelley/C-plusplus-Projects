
/*
THIS CODE IS NOT THE MOST UP TO DATE CODE: THIS WAS UPLOADED TO BLACKBOARD AS A BACKUP. 

PLEASE SEE BLACKBOARD FOR MOST RECENT, COMPLETE VERSION
*/





#include <iostream>
#include "mixed.h"

using namespace std;

int main()
{

  // demonstrate behavior of the two constructors and the << overload
  
  Mixed  m1(0,-35,10), m2(-1,2,4), m3(4), m4(-11), m5(2,2,3), m6(-2,2,3);
  Mixed  m7(0,2,4), m8(0,12,24); 
  Mixed  m9(1,2,3), m10(1,90,100); 
  Mixed j1(0,1,3), j2(1,1,2);
  Mixed j3(0,0,0), j4(0,9,1);
  Mixed huge(100,8,9), little(1,1,5);



 /**************WORKS WORKS WORKS**************************
  cout << "Adding j3 and j4" << endl;
  cout << j3 << endl;
  cout << (j3 + j4) << endl;


  cout << " Adding 10 to j3 (0)***********************" << endl;


 	cout << " Adding 10 to j3 (0)***********************" << endl;
  cout << (10+j3) <<  endl;



  cout << "Subtracting j1 and j2" << endl;
  cout << (j1-j2) << endl;
  cout << j3 << endl;
  cout << j4 << endl;
  ********************************************************/

  cout << "Please enter in the fraction 5 5/6:";
  cin >> m1;
  cout << endl << "You entered: " << m1 << endl;

  /*
  cout << "Subtracting j3 and j4" << endl;
  cout << (j3 - j4) << endl;

  cout << "Subtracting j1 and j2" << endl;
  cout << j1 - j2 << endl;

  cout << "Attempting to add 10 to j3 (0,0,0)" << endl;
  cout << j3 + 10 << endl;
  cout << "Now the opposite direction" << endl;
  cout << 10 + j3 << endl;
  */
/*
  cout << "Multiplying j1 and j2" << endl;
  cout << j1 * j2 << endl;

  cout << "Multiplying j1 and j2 " << endl;
  cout << j1 / j2 << endl;

  // cout << j1.Evaluate() << endl;
*/

   /*cout << m9 << endl;
   cout << "PLEASE ENTER A NUMBER" << endl;
   cin >> j3;
   cout << "THE NUMBER YOU ENTERED WAS: " << j3.ToFraction() << endl;
   cout << "PLEASE ENTER AN INVALID NUMBER" << endl;
   cin >> j4;
   cout << "YOUR NUMBER SHOULD BE ZERO: " << j4.Evaluate() << endl;
   */





return 0;
}