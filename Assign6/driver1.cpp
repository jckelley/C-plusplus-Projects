#include <iostream>

using namespace std;

#include "bitarray.h"
#include "sieve.h"

int main(void)
{
  unsigned int i, max,max2, counter = 0;

   cout << "\nEnter a positive integer for the maximum value: ";
   cin >> max;

   BitArray ba(max);

   //Set the index
   ba.Set(2);
   ba.Set(5);
   ba.Set(6);
   ba.Set(7);
   ba.Unset(6);
   ba.Set(11);
   ba.Unset(12);
   ba.Flip(13);

  Sieve(ba);

  cout << ba << endl;




}

0011010100010100010100010000010100000100
