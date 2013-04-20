/* ========================================================================== */
/*	PROGRAM: Mixed Class
	File: mixed.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Springer
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 3
    DUE DATE: 02/15/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'mixed.h' file. This class will allow for minipulation of mixed
numbers such as ' 1 3/4' or 'One and Three Fourths'. This class will allow for input and ouput
of mixed numbers as well. 


INPUT

The iostream has been overloaded so the << operator can take in a mixed number object. The object
must be declared ahead of time as a Mixed number type. If the mixed number entered has a 0 denominator
( 1 1/0) or a double negative (-1, -1/1) the mixed number will be converted to the default, 0 0/1

OUTPUT

The class allows for output via an overloaded ostream << operator. The object will be printed as a regular 
fraction ('3/4') if no whole number is present. Otherwise it will output the entire mixed number as
'1 3/4'.

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user. This class does protect
the integrity of the data with some bad data-checking such as with the mixed number, but is not fully debugged
agaisnt all possible bad data entries. The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */



#include <iostream>
#include "mixed.h"

using namespace std;

#define PRINT_F_FRAC cout << w << ' ' << n << ' ' << d << endl;
#define PRINT_1_FRAC cout << w1 << ' ' << n1 << ' ' << d1 << endl;
#define PRINT_2_FRAC cout << w2 << ' ' << n2 << ' ' << d2 << endl; 
#define SP ' '

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//							Manual Function Protypes
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


void SimplifyToImp(int &w,int &n, int &d);
bool IsFactor(const int num, const int fact);
bool IsValidNum(const int w, const int n, const int d);
bool IsBigger( const int w1,const int n1,const int d1,const int w2,const int n2,const int d2);
bool IsEqual(const int w1,const int n1,const int d1,const int w2,const int n2,const int d2);
int Abs(const int n);
int Gcd(const int x, const int y);
void ConvertToWhole(int &w, int &n, int &d);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//								Manual Functions
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ***************************************************************************
// * Function Name: ConvertToWhole
// * Description: This function converts an improper fraction to a 
// * whole/mixed number.
// *
// * Parameter Description: Takes in the address of the whole, num, and dem 
// * variable of the mixed number
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
void ConvertToWhole(int &w, int &n, int &d)
{
	
	int leftover = Abs(n) % d;

	// If it is perfectly divisible, we have a whole number, no fraction
	if(leftover == 0) 
	{
		w = n / d; //Find the whole number
		n = 0; d = 1; //Set fraction to 0
	}
	else //We will have a leftover fraction
	{
		int neW = n - leftover;

		w = neW / d;
		n = leftover;

	}
	if(w < 0 && n < 0) //Do a check we don't have a double negative!
		n *= (-1);
}
// ***************************************************************************
// * Function Name: Gcd (Greatest Common Denominator) 
// * Description: Returns the greatest common denominator of two numbers
// *
// * Parameter Description: Two numbers, most likely denominators of a 
// * fraction
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// * Adapted: This function was inspired by Euclidean's Algorithm. More info on 
// * this Alogirthm can be found at
// * http://en.wikipedia.org/wiki/Euclidean_algorithm 
// ***************************************************************************
int Gcd(const int x, const int y)
{
     if ( y == 0 ) 
          return x; 
 
     else if (y > 0 ) 
          return Gcd(y, x%y);

     else 
         return 1;
}
// ***************************************************************************
// * Function Name: Abs (Absolute Value)
// * Description: Returns the Absolute value of the parameter
// *
// * Parameter Description: A number you wish to have converted to AbsValue
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
int Abs(const int n)
{
	int num = n;
	if(n < 0)
		num = (-1)*n;

	return num;
}
// ***************************************************************************
// * Function Name: IsEqual
// * Description: This function takes in two mixed numbers and determines if 
// * they are equal to each other. It will return a true or false statement.
// *
// * Parameter Description: w1,n1,d1 is the whole, numerator, and denominator 
// * of the first mixed number, respectively. w2,n2,d2 is the whole, numerator
// * and denominator of the second mixed number, resepectivly. 
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool IsEqual(const int w1,const int n1,const int d1,const int w2,const int n2,const int d2)
{
	int w3 = w1, n3 = n1, d3 = d1;
	int w4 = w2, n4 = n2, d4 = d2;
	bool result = false;
	//First, we will convert both numbers to improper fractions using SimplifyToImp
	SimplifyToImp(w3,n3,d3);
	SimplifyToImp(w4,n4,d4);
	//Now, we should multiply each side by the opposing denominator*numerator combos
	int newNum1 = n3 * d4; 
	int newNum2 = n4 * d3;
	
	//Now we have the numerators over a common denominator. We can now compare.
	if(newNum1 == newNum2)
		result = true;

	return result;
}
// ***************************************************************************
// * Function Name: IsBigger
// * Description: This function takes in two mixed numbers and determines if
// * the first is bigger than the second. It returns a boolean statement.
// *
// * Parameter Description: w1,n1,d1 is the whole, numerator, and denominator 
// * of the first mixed number, respectively. w2,n2,d2 is the whole, numerator
// * and denominator of the second mixed number, resepectivly.
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool IsBigger( const int w1,const int n1,const int d1,const int w2,const int n2,const int d2)
{
	int w3 = w1, n3 = n1, d3 = d1;
	int w4 = w2, n4 = n2, d4 = d2;
	bool result = false;
	//First, we will convert both numbers to improper fractions using SimplifyToImp
	SimplifyToImp(w3,n3,d3);
	SimplifyToImp(w4,n4,d4);
	//Now, we should multiply each side by the opposing denominator*numerator combos
	int newNum1 = n3 * d4; 
	int newNum2 = n4 * d3;
	
	//Now we have the numerators over a common denominator. We can now compare.
	if(newNum1 > newNum2)
		result = true;

	return result;

}
// ***************************************************************************
// * Function Name: IsValidNum
// * Description: Checks to see if the passed Mixed number is a valid mixed
// * Mixed number. 
// *
// * Parameter Description: The whole number, numerator, and denomintor of the
// * the mixed number we are checking are passed through. 
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool IsValidNum(const int w, const int n, const int d)
{
	bool result = true;
	if(d == 0)
		result = false;
	else if((w < 0 || w != 0) && n < 0)
		result =false;
	
	return result;

}
// ***************************************************************************
// * Function Name: IsFactor
// * Description: Two numbers are passed through. This function returns a 
// * boolean statement if the 2nd parameter (fact) is a factor of num (the 1st)
// *
// * Parameter Description: Two numbers are passed, num and fact. Num is the
// * main number, fact is the what we are checking if it is a factor of num
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool IsFactor(const int num, const int fact)
{
	bool result = false;
	if((num % fact) == 0)
		result = true;

	return result;
}
// ***************************************************************************
// * Function Name: SimplifyToImp
// * Description: This function simplifies a mixed number to improper fraction,
// * and also to simplified form (2/4 becomes 1/2). 
// *
// * Parameter Description: It takes in the address of the mixed number we are
// * to Simplify and converts it directly.
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
void SimplifyToImp( int &w, int &n, int &d)
{
	bool neg = false;
	int g;
	//First, let us find out our whole number
	
	if(w != 0)
	{
		if(w < 0)
			neg = true;
			if(n > 0) //If n != 0, we have a fraction attached!
			{
				///First, we should convert the entire number to improper form (fraction)
				n = (n + (d*Abs(w))); 
				w = 0; 

				//Now, simplify the fraction
				 g = Gcd(n,d);
				n = n/g;
				d = d/g;

				
			}
			else //We just have a whole number! 
			{
				//Return 1/1
				if(neg)
					w *= (-1);
			
				n = w;
				w = 0;
				d = 1;
			}
	}		
	else //We JUST have a fraction, but it could still be a zero fraction!
	{
			//Find out if we are dealing with a negative or not
			if (n < 0)
				neg = true;

			if(n != 0)
			{
		
			g = Gcd(Abs(n),d);
			//cout << "our g value is: " << g << endl;

	
			n = Abs(n)/g;
			
			d = d/g;
	

			//But wait, was the fraction negative?
			if(neg)
				n *= (-1);
			}
			else
				{n=0;w=0;d=1;}

	}
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//									CLASS FUNCTIONS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




// ***************************************************************************
// * Function Name: Mixed
// * Description: The Default mixed number constructor 
// *
// * Parameter Description: A single number that is our whole number
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
Mixed::Mixed(const int VAL)
{
	whole = VAL;
	num = 0;
	 dem = 0;
}
// ***************************************************************************
// * Function Name: Mixed
// * Description: This is the Mixed number constructor for a whole Mixed num
// *
// * Parameter Description: The whole num (VAL), Numerator (NUM), and 
// * denominator (DEM) are passed. 
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
Mixed::Mixed(const int VAL,int NUM,int DEM)
{
	if(IsValidNum(VAL,NUM,DEM))
	{
		whole = VAL;
		dem = DEM;
		num = NUM;
	}
	else
	{
		whole = DEFAULT_VALUE;
		num = DEFAULT_VALUE;
		dem = DEFAULT_D;
	}
}
// ***************************************************************************
// * Function Name: Evaluate
// * Description: Converts the mixed number to decimal form
// *
// * Parameter Description: None
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
double Mixed::Evaluate()
{
	double result = 0;
	double d = dem, n = num;
	result = whole + ((double)n/(double)d);
	double bo = Gcd(17,6);
		return result;
}
// ***************************************************************************
// * Function Name: Simplify 
// * Description: Converts the mixed number to simpliest form
// *
// * Parameter Description: None
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
void Mixed::Simplify()
{
	whole = whole % num;
	SimplifyToImp(whole,num,dem);
}
// ***************************************************************************
// * Function Name: ToFraction
// * Description: Converts the Mixed number to a fraction
// *
// * Parameter Description: None
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
void Mixed::ToFraction()
{
	int w1 =0,n1=0,d1=0;

	n1 = num + (dem*whole);
	whole = 0;
	num = n1;
}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//						COMPARISON OVERLOADING OPERATORS 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// ***************************************************************************
// * Function Name: >> Overload Operator
// * Description: Overload's '>>' operator to allow for input of Mixed number
// * via '<<' operator.
// *
// * Parameter Description: istream object, and Mixed number. 
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
istream &operator>>(istream &S, Mixed &M)
{	char fill;
	int w,n,d;
	S >> w >> n >> fill >> d;

	if(IsValidNum(w,n,d))
	{
		
		M.whole = w;
		M.num = n;
		M.dem = d;
	}
	else
	{
		
		M.whole = DEFAULT_VALUE;
		M.num = DEFAULT_VALUE;
		M.dem = DEFAULT_D;
	}
	return S;
}
// ***************************************************************************
// * Function Name: Overload '<<' operator
// * Description: Overload's '<<' operator to allow for input of Mixed number
// * via '<<' operator.
// *
// * Parameter Description: ostream object, Mixed number.
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
ostream &operator<<(ostream &S, const Mixed &M)
{
	if(M.whole != 0)
		S << M.whole << ' ' << M.num << '/' << M.dem << endl;
	else
		S << M.num << '/' << M.dem << endl;

	return S;
}
// ***************************************************************************
// * Function Name: Operator<
// * Description: Deteremines if the 1st Mixed number is less than the second
// *
// * Parameter Description: The two mixed numbers being compared
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool operator<(const Mixed &M,const Mixed &MM)
{
	bool result = false;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;

	if(IsBigger(w2,n2,d2,w1,n1,d1))
		result =true;
	

	return result;
}
// ***************************************************************************
// * Function Name: <= Overloader
// * Description: Deteremines if the 1st Mixed number is less or equal than the second
// *
// * Parameter Description: The two mixed numbers being compared
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool operator<=(const Mixed &M, const Mixed &MM)
{
	bool result =false;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;

	if(IsBigger(w2,n2,d2,w1,n1,d1) || IsEqual(w2,n2,d2,w1,n1,d1))
		result = true;

	return result;
}
// ***************************************************************************
// * Function Name: > Overloader
// * Description: Deteremines if the 1st Mixed number is greater than the second
// *
// * Parameter Description: The two mixed numbers being compared
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool operator>(const Mixed &M, const Mixed &MM)
{
	bool result =false;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;

	if(IsBigger(w1,n1,d1,w2,n2,d2))
		result = true;


	return result;

}
// ***************************************************************************
// * Function Name: >= Overloader
// * Description: Deteremines if the 1st Mixed number is greater than or equal the second
// *
// * Parameter Description: The two mixed numbers being compared
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool operator>=(const Mixed &M, const Mixed &MM)
{
	bool result =false;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;
	if(IsBigger(w1,n1,d1,w2,n2,d2) || IsEqual(w1,n1,d1,w2,n2,d2))
		result = true;

	return result;

}
// ***************************************************************************
// * Function Name: == Overloader
// * Description: Deteremines if the 1st Mixed number is equal to the second
// *
// * Parameter Description: The two mixed numbers being compared
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool operator==(const Mixed &M, const Mixed &MM)
{
	bool result = false;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;
	if(IsEqual(w1,n1,d1,w2,n2,d2))
		result = true;
	
	return result;
}
// ***************************************************************************
// * Function Name: != Overloader
// * Description: Deteremines if the 1st Mixed number is not equal to the second
// *
// * Parameter Description: The two mixed numbers being compared
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
bool operator!=(const Mixed &M, const Mixed &MM)
{
	bool result = true;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;
	if(!(IsEqual(w1,n1,d1,w2,n2,d2)))
		result = false;

	return result;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//							OVERLOAD OF UNARY OPERATORS 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// ***************************************************************************
// * Function Name: + operator Overloader
// * Description: Overloads the + operator to add two Mixed numbers together
// *
// * Parameter Description: The two mixed numbers being added
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
 Mixed operator+(const Mixed &M, const Mixed &MM)
{
	
	int w = 0, n = 0, d = 1;
	int n_1, n_2;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;

	
	//First, let us convert the mixed number to a fraction

	//Converts to improper fraction of numerator
	SimplifyToImp(w1,n1,d1);
	SimplifyToImp(w2,n2,d2);

	//If the Denominators are not equal, we will need to set them equal to each other.
	if(d1 != d2)
	{
		
		//Let us find the common denominator
		d = d1 * d2;
		
		//Now, let us set the denominators equal to the numerators
		n_1 = d2 * n1;
		
		n_2 = d * n2;
		n = n_1 + n_2; // Final numerator
	}
	else
		n = n1 + n2;
	SimplifyToImp(w,n,d);
	ConvertToWhole(w,n,d);

return Mixed(w,n,d);
}
// ***************************************************************************
// * Function Name: The - operator Overloader
// * Description: Subtracts the second Mixed number from the first
// *
// * Parameter Description: The two mixed numbers being subtracted
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
 Mixed operator-(const Mixed &M, const Mixed &MM)
{


	int w = 0, n = 0, d ;
	int nf1, nf2;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;

	
	//First, let us convert the mixed numbers to a improper fraction form
	SimplifyToImp(w1,n1,d1);
	SimplifyToImp(w2,n2,d2);
	d = d1;
	//If the Denominators are not equal, we will need to set them equal to each other.
	if(d1 != d2)
	{
		
		//Let us find the common denominator
		d = d1* d2;
		
		//Now, let us set the denominators equal to the numerators
		nf1 = n1 * d2;
		
		nf2 = n2 * d1;
		
		n = nf1 - nf2; // Final numerator
	
	}
	else
		n = n1 - n2; 

	ConvertToWhole(w,n,d);
return Mixed(w,n,d);
}
// ***************************************************************************
// * Function Name: The * operator Overloader
// * Description: Multiplies two mixed numbers together
// *
// * Parameter Description: the two mixed numbers being multiplied.
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
 Mixed operator*( const Mixed &M, const Mixed &MM)
{
	int w,n,d;
	int w1 = M.whole, n1 = M.num, d1 = M.dem;
	int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;
	

	//Simplfy our fractions to improper form
	SimplifyToImp(w1,n1,d1);
	SimplifyToImp(w2,n2,d2);

	n = (n1 * n2);
	d = (d1 * d2);

	ConvertToWhole(w,n,d);

return Mixed(w,n,d);
}
// ***************************************************************************
// * Function Name: The / Operator Overloader
// * Description: Divides the 1st Mixed Num by the 2nd Mixed num
// *
// * Parameter Description: the 1st Mixed num (M) and the second (MM)
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
 Mixed operator/(const Mixed &M,const Mixed &MM) 
{
		int w,n,d;
		int w1 = M.whole, n1 = M.num, d1 = M.dem;
		int w2 = MM.whole, n2 = MM.num, d2 = MM.dem;

	SimplifyToImp(w1,n1,d1);
	SimplifyToImp(w2,n2,d2);

	n = (n1 * d2);
	d = (d1 * n2);

	ConvertToWhole(w,n,d);




return Mixed(w,n,d);
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//					OVERLOAD OF INCREMENT/DECREMENT OPERATORS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ***************************************************************************
// * Function Name: ++ Overloader
// * Description: Adds 1 to the mixed number
// *
// * Parameter Description: none
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
Mixed Mixed::operator++()
{
	 whole++;
	 return( Mixed(whole,num,dem));
}
// ***************************************************************************
// * Function Name: ++ Overloader
// * Description: Adds 1 to the mixed number
// *
// * Parameter Description: Mixed number we are incrementing
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
Mixed Mixed::operator++(int inc)
{
	whole++;
	 return( Mixed(whole,num,dem));
}
// ***************************************************************************
// * Function Name: -- Overloader
// * Description: Subtracts 1 from mixed number
// *
// * Parameter Description: none
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
Mixed Mixed::operator--()
{
	whole--;
	 return( Mixed(whole,num,dem));
}
// ***************************************************************************
// * Function Name: -- Overloader
// * Description: Subtracts 1 from Mixed number.
// *
// * Parameter Description: Mixed number we are incrementing
// *
// * Date: 02/12/2013
// * Author: Joseph Springer
// ***************************************************************************
Mixed Mixed::operator--(int dec)
{
	whole--;
	 return( Mixed(whole,num,dem));
}







