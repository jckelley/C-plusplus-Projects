  // * *******************************************************************
  // * * Taken from Deitel & Associates, Inc. and Prentice Hall          *
  // * * Deitel & Deitel How to Probram in C++ 3rd Edition.              *
  // * * Figure 21.13: stack.h                                           *
  // * * Template Stack Class definition derived from class List.        *
  // * *                                                                 *
  // * * Must have the files list.h included in order to function        *
  // * * properly.                                                       *
  // * * Additional comments added by Dr. David A. Gaitros               *
  // * *******************************************************************

#ifndef STACK_H
#define STACK_H

#include "list.h"  // List class definition

  // * *******************************************************************
  // * *  Class definition.                                              *
  // * *******************************************************************

template< class STACKTYPE >
class Stack : private List< STACKTYPE > {

public:
  // * *******************************************************************
  // * * This function "push" actually  calls the List function          *
  // * * insertAtFront to place an item at the front of the list.        *
  // * *******************************************************************
  
   void push( const STACKTYPE &data ) 
   { 
      this->insertAtFront( data ); 
   
   }


  // * *******************************************************************
  // * *  This function "pop" returns an item from the front of the      *
 // * *  stack by simtaneously removing the item from the front of the  *
  // * *  list and returning the value.  This simulates the "pop"        *
  // * *  feature of a stack.                                            *
  // * *******************************************************************


   bool pop( STACKTYPE &data ) 
   { 
      return this->removeFromFront( data ); 
   
   }
  // * *******************************************************************
  // * *  A Boolean function "isStackEmpty" is simply a return value     *
  // * *  from the List class this->isEmpty.  Essentially, does the      *
  // * *  head of the list point to a null pointer.                      *
  // * *******************************************************************


  
   bool isStackEmpty() const 
   { 
      return this->isEmpty(); 
   
   } 
  // * *******************************************************************
  // * *  printStack() simply calls the List class member function       *
  // * *  print() which will print the contents of the list if the       *
  // * *  list is not empty.                                             *
  // * *******************************************************************
  
   void printStack() const 
   { 
      this->print(); 
   
   } 

};
  // * *******************************************************************
  // * *     E N D  S T A C K  C L A S S                                 *
  // * *******************************************************************

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/