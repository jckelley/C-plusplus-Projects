  // * *******************************************************************
  // * * Taken from Deitel & Associates, Inc. and Prentice Hall          *
  // * * Deitel & Deitel How to Probram in C++ 3rd Edition.              *
  // * * Figure 21.3: listnode.h                                         *
  // * * Template ListNOde Class definition.                             *
  // * *                                                                 *
  // * * This class is usually never used by itself but is almost always *
  // * * inherited by other classes.                                     *
  // * *                                                                 *
  // * * Additional comments and modifications added by                  *
  // * *   Dr. David A. Gaitros                                          *
  // * *******************************************************************


#ifndef LISTNODE_H
#define LISTNODE_H
  // * *******************************************************************
  // * *  This is a forward declaration of the class List and is needed  *
  // * *  to provide the definition for a single node within the list.   *
  // * *  This is a templace class where the data type place holder      *
  // * *  is called NODETYPE.  Eventually this will be replaced by the   *
  // * *  actual date when the template is istantiated.                  *
  // * *******************************************************************

template< class NODETYPE > class List;  

template< class NODETYPE >
// * *******************************************************************
// * *  Make the List Class a friend so it can access private data.    *
// * *******************************************************************
class ListNode {
  friend class List< NODETYPE >;

  // * *******************************************************************
  // * *  This is a simple class and only needs two public items.        *
  // * *  The constructor "ListNode" and a member function which         *
  // * *  will return the data to the calling routine.                   *
  // * *******************************************************************
public:
   ListNode( const NODETYPE & );  // constructor
   NODETYPE getData() const;      // return data in node

  // * *******************************************************************
  // * *  Only two private items.  One is the actual data itself and     *
  // * *  the other is a pointer to an object of the same type. Note     *
  // * *  here we are setting up the class to be used as a Single        *
  // * *  link list.                                                     *
  // * *  At this point we don't know what the "data" is and as a result *
  // * *  the rest of the code must be developed in such a way as to     *
  // * *  not prohibit the use of any type (simple or complex) in the    *
  // * *  classes that inherit listnode.h.                               *
  // * *******************************************************************
private:
   NODETYPE data;                 // data
   ListNode< NODETYPE > *nextPtr; // next node in list

};

// * *******************************************************************
// * *    E N D   C L A S S  L I S T N O D E                           *
// * *******************************************************************


// * *******************************************************************
// * *  Here we have the implementation of the ListNode class.  Recall *
// * *  that in templates both the definition and implementation have  *
// * *  to be placed in the same file so the compiler can resolve      *
// * *  refernces.                                                     *
// * *******************************************************************

// constructor
// * *******************************************************************
// * *  ListNode Constructor.  Sets the data to Info and sets the      *
// * *  nextPtr to null.                                               *
// * *******************************************************************

template< class NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
   : data( info ), 
     nextPtr( 0 ) 
{ 
  

} 
// * *******************************************************************
// * *  getData() returns a copy of the information.                   *
// * *******************************************************************

template< class NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
   
} 

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