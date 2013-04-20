// main.cpp -- Bob Myers
//
// Driver program to demonstrate the behavior of the Mixed class
// 
// You can add more tests of your own, or write other drivers to test your
// class -- this is NOT a comprehensive set of tests.  This is just a
// sample, which should help check whether your function declarations are
// appropriate, and can test a few sample cases.

#include <iostream>
#include "mixed.h"

using namespace std;

int main()
{

  // demonstrate behavior of the two constructors and the << overload
  
  Mixed  m1(0,-35,10), m2(-1,2,4), m3(4), m4(-11), m5(2,2,3), m6(-2,2,3);
  Mixed  m7(0,2,4), m8(0,12,24); 
  Mixed  m9(1,2,3), m10(1,90,100); 


  cout << m1 << m2 << m3 << m4 << m5 << m6 << endl;
  cout << "m1 + 10=" << m1+10 << endl;
  cout << "m1 - 10=" << m1-10 << endl;
  cout << "m5 / (-2)=" << m5/(-2) << endl;
  cout << "m5 * 2=" << m5*2 << endl;
  cout << "10 + m1 ="<< 10+m1<< endl; 
 
  /*
  if(m3>3) cout << "M3 "<< m3 <<" is greater than 3" << endl ;

  if(m7==m8) cout << "M7 "<<m7 <<" equal to m8 " << m8 << endl; 
  if(m9<=m10) cout << "M9 "<< m9 <<" is less  than or equal to m10" 
<<m10<< endl ;

  
  char answer;
  cout << "Initial values: \nx = " << x << "\ny = " << y
       << "\nm1 = " << m1 << "\nm2 = " << m2 << "\nm3 = " << m3 
       << "\nm4 = " << m4 << "\nm5 = " << m5 << "\n\n";
  
  // Trying Simplify
  x.Simplify();
  cout<< 'x'<<x << endl;
  
  x++;
  cout<< 'x'<<x<<endl; ;
  
  m1.Simplify();
  cout << "x simplified: " << x << " and m1 simplified " << m1 << "\n\n";

  // Trying ToFraction
  x.ToFraction();
  y.ToFraction();
  m1.ToFraction();
  m1=m1+4; 
  cout << "Values as fractions: \nx = " << x << "\ny = " << y
       << "\nm1 = " << m1 << "\n\n";
  
  // demonstrate >> overload

  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;

  cout << "You entered:\n";
  cout << "  x = " << x << '\n';
  cout << "  y = " << y << '\n';
  
  // demonstrate comparison overloads
  if (x < y)	cout << "(x < y) is TRUE\n";
  if (x > y)	cout << "(x > y) is TRUE\n";
  if (x <= y)	cout << "(x <= y) is TRUE\n";
  if (x >= y)	cout << "(x >= y) is TRUE\n";
  if (x == y)	cout << "(x == y) is TRUE\n";
  if (x != y)	cout << "(x != y) is TRUE\n";
  
  // emonstrating Evaluate
  cout << "\nDecimal equivalent of " << x << " is " << x.Evaluate() << '\n';
  cout << "Decimal equivalent of " << y << " is " << y.Evaluate() << "\n\n";
  
  // demonstrating arithmetic overloads
  cout << "(x + y) = " << (x + y) << '\n';
  cout << "(x - y) = " << (x - y) << '\n';
  cout << "(x * y) = " << (x * y) << '\n';
  cout << "(x / y) = " << (x / y) << '\n';
  
  // demonstrating arithmetic that uses conversion constructor
  //  to convert the integer operand to a Mixed object
  cout << "(x + 10) = " << x + 10 << '\n';
  cout << "(x - 4) = " << x - 4 << '\n';
  cout << "(x * -13) = " << x * -13 << '\n';
  cout << "(x / 7) = " << x / 7 << '\n';
									    */
  
  return 0;
}
