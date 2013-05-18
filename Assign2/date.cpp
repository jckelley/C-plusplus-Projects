/* ========================================================================== */
/*	PROGRAM: Date Class
	File: date.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Kelley
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 2
    DUE DATE: 02/01/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'date.h' file to construct a date class. This class
will be able to take in a date (month, day, year) and be able to minipulate
and display it in several different manners. 

INPUT

The input in this program is generally limitted to the hard-code of the program. There
are instances where the user can enter in a date from a terminal prompt, but such prompt must be
hard-coded and intialized into the program. It is possible to supply a driver class that would
allow it to take in other inputs, but such instance is not provided in this class.

OUTPUT

The class allows for the printing of the date under different formats (Long, Two-Digit, Default, and Julian)
Otherwise, this class preforms no other output. All output must be supplied directly from the driver file

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user. This class does protect
the integrity of the data with some bad data-checking such as with the date, but is not fully debugged
agaisnt all possible bad data entries. The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */

#include <iostream>
#include "date.h"
#include <string>

using namespace std;



//FUNCTION PROTOTYPES 
bool checkDate(const int d, const int m, const int y);
bool checkDay(const int d,const int m,const int y);
bool checkMonth(const int m);
bool checkYear(const int y);
int returnDays(const int m);
void printDefault(const int d, const int m, const int y);
void printTwoDigit(const int d, const int m, const int y);
void printLong(const int d, const int m, const int y);
bool isLeapYear(const int y);
int convertJulian(const int d,const int m,const int y);
int DaysInYear(const int y);
int reverseJulianMonths(const int d,const int y);
int reverseJulianDays(const int d,const int y);
int YearsForward(const int x);


/*
==========================================================
		NON-CLASS FUNCTIONS OR LOCAL FUNCTIONS
==========================================================
*/



/************************
YearsForward Function:
This function takes in the Julian amount of days we are incrementing by,
and the current year. It then divides that number by DaysInYear (365) and
outputs how many years forward the increment will put us. For example, if you
incremented by 1000, it would return '2' because we are going 2 years into the future.

*************************/
int YearsForward(const int x,const int cur)
{
	int value = x / DaysInYear(cur);
	return value;
}
/************************
reverseJulianDays Function:
This function takes in the amount of days in a year in Julian form (so direct count). It then
finds out how many months fit into those days, and subtracts the total days in all those months.
We are then left with the amount of days in the last month. For example, say we had are given 32 
days. It would see that the 1st month, Janurary (31 days) fits, and would thus subtract 31 days.
It would then see that with 1 day left, and we do not have enough to subtract Feburary (28 days),
thus we have 1 in whatever month we are. This value is returned.

*************************/
int reverseJulianDays(const int d,const int y)
{
	
	int m = reverseJulianMonths(d,y);//Number of months it takes to get to that day.
	

	int finalDays = d;
	for(int i = 0; i < m; i++)
	{
			if(isLeapYear(y) && i == 2)
				finalDays -= 29;
			else
				finalDays -= MonthDays[i];
	}

	return finalDays;


}
/************************
reverseJulianMonths Function:
This function takes in the current year and  and number of days we have in that year, in Julian form.
It then finds out how many months we are by subtracting each month until the days are negative. If we 
have 60 days, it would subtract 31 (Jan), then 28 (Feb), then would have 1 day left. It would then 
subtract 31 (Mar) and have a negative number (-30). Thus, it would return 2 months (the integer 2).

*************************/
int reverseJulianMonths(const int d,const int y) //You need to pass the year in to find out if it's a leap year, because that will change the the # of days
{
	int totalDays = DaysInYear(y);
	int finalMonth = 0;
	int passDays = d; //Because we can't change 'd'
	if(isLeapYear(y))
	{
		for(int i = 0; passDays > 0;i++)
		{
			if(i == 2)  		//This serves as our leap year checker. 
			passDays = passDays - 29;
			else
			passDays = passDays - MonthDays[i];

			finalMonth++;
		}
	}
	else
	{
		
		int i = 0;
		while(passDays > 0 && i < 13)
		{
			
			passDays -= MonthDays[i];
			finalMonth++;
	
			i++;
		}
		
	}
	finalMonth--;
	if(finalMonth==12)
		finalMonth = 1;
	return finalMonth;

}
/************************
DaysInYear Function:
This function takes in the current year and finds out if it is leap year or not. If it is, it will
return 366 (because of the extra day in Feb). Otherwise, it will return 365.

*************************/
int DaysInYear(const int y)
{
	int days;
	if(isLeapYear(y))
		days = 366;
	else
		days = 365;

	return days;
}
/************************
convertJulian Function:
This function operates on the simple mathamatical process of adding up all of the months and 
then the days in the date. Since it takes in the date, month, and year, it has access to the entire date.
For every month, it will add that month's days to the final count. Once it has added all the months, it
will then add the additional days. It returns a finite, number.

*************************/
int convertJulian(const int d,const int m,const int y)
{
	int finalDays = 0;
	for(int i = 1; i < (m); i++)
	{
		if(i == 2 && isLeapYear(y))
		{
				finalDays += 29;
		}
		else
		{
		finalDays += MonthDays[i];

		}
	}
	finalDays += d;

	return finalDays;
}
/************************
isLeapYear Function:
This function takes in the year and returns true or false if that year is a leap year or not.
It follows the simple guidelines that a year is a leap year if it is divisible by 4, but not if divisible 
by 1000, unless also divisible by 400.

Returns True for Leapyear, False for Non-Leapyear

*************************/
bool isLeapYear(const int y)
{
	bool isLeap = false;
		if(y % 4 == 0)
		{
			isLeap = true;
			if(y % 1000 != 0)
			{
				isLeap = false;
				if(y % 400 == 0)
					isLeap == true;
			}
		}
		return isLeap;
}
/************************
printDefault Function:
This function prints the date in Default format
M/D/Y

*************************/
void printDefault(const int d, const int m, const int y)
{
		cout << m << SLASH << d << SLASH << y << endl;
}
/************************
printTwoDigit Function:
This function prints the date in Two-Digit format
mm/dd/yy
*************************/
void printTwoDigit(const int d, const int m, const int y)
{
	cout << TWODIGITS[m] << SLASH << TWODIGITS[d] << SLASH << TWODIGITS[y%100] << endl;
}
/************************
printLong Function:
This function prints the date in Long format
month, D, Y
where month is the abbreviated month name, and the full year.

*************************/
void printLong(const int d, const int m, const int y)
{
	cout << MONTHS[m] << " " << d << ", " << y << endl;
}
/************************
checkDate Function:
Takes in the date and does a bad-data check to make sure it is valid.
Returns true if good date, false if the date is not a real date.

*************************/
bool checkDate(const int d, const int m, const int y)
{
	bool GoodDate;
	
	if(checkDay(d,m,y) && checkMonth(m) && checkYear(y))
		GoodDate = true;
	else
		GoodDate = false;
	return GoodDate;
	

}
/************************
checkDay Function:
Takes in the date and checks if that date actually exists. Calls upon the array
of days in the month. Also does a leap year check to allow for Feb 29th.
Returns true if day exists, false if day does not exist.

*************************/
bool checkDay(const int d,const int m,const int y)
{
	bool GoodDay;
	if((MonthDays[m] >=d && d > 0) || (isLeapYear(y) && m ==2 && d == 29))
		GoodDay = true;
	else
		GoodDay = false;
	return GoodDay;
}
/************************
checkMonth Function:
Takes in the month. We only have 12 months in a year, so is a simple bool function
to check if month is 1 thru 12. Returns true if it is, false if it isn't.

*************************/
bool checkMonth(const int m)
{
	bool GoodMonth;
	if(m > 0 && m <=12)
		GoodMonth = true;
	else
		GoodMonth = false;
	return GoodMonth;
}
/************************
checkYear Function:
Takes in the year. Checks if it is between the MIN_YEAR constant and MAX_YEAR constant
that our class will handle.

*************************/
bool checkYear(const int y)
{
	bool GoodYear;
	if(y>MIN_YEAR && y <= MAX_YEAR)
		GoodYear = true;
	else
		GoodYear = false;
	return GoodYear;

}
/*
========================================================
					CLASS FUNCTIONS
========================================================
*/




/************************
Date Function:
Constructs a date. Notice that in the header file, we provide constants. If not all of the variables
are entered, or if no variables are entered at all, the date will still be constructed witht he default
variables. The function proceeds to do a data-check on the date, and make sure the date is valid. If it
is valid, the passed date is then entered into the private class date variables. If it is an invalid date,
then the default date is entered into the private class date variables.

*************************/

Date::Date(const int m, const int d, const int y)
{
	if(checkDate(d,m,y))
	{
		day = d;
		month = m;
		year = y;
	}
	//If any of the values are incorrect, set the date to the fault standard
	else
	{
		day = DEFAULT_DAY;
		month = DEFAULT_MONTH;
		year = DEFAULT_YEAR;

	}
}
/************************
Input Function:
Allows user to input from terminal a date in the format:
mm/dd/yy
It will then proceed to do a data check on the date, making sure it is valid.
If the date is invalid, the program will prompt the user to enter another date
until the date is valid.
Once the date is valid, it replaces the private class variables as the date of 
the object.

*************************/
void Date::Input()
{
	int dd,mm,yy;
	char cc;
	do{
	cin >> mm >> cc >> dd >> cc >> yy;
	if(checkDate(dd,mm,yy))
	{
		day = dd;
		month = mm;
		year = yy;
	}
	else
		cout << "Incorrect Date. Please Try Again" << endl;
	}while(!checkDate(dd,mm,yy));
}
/************************
Show Function:
This functions prints out the date in the format that the date object currently holds.

*************************/
void Date::Show()
{

	if(format == 'L')
		printLong(day, month, year);
	else if(format == 'T')
		printTwoDigit(day, month, year);
	else if(format == 'J')
		{
		int num = convertJulian(day,month,year);

		cout << TWODIGITS[year%100] << "-";
		if(num < 100)
			cout << THREEDIGITS[num] << endl;
		else
			cout << num << endl;
}
	else 
		printDefault(day, month, year);
}
/************************
Date:Set Function:
This is a function similar to the input function, except it changes the date
without asking anything from the user. It is instead hard-coded into the program.
It will take in a date, bad-data check it using the GoodDate function. If it is
a valid date, it will replace the private class variables. If it is an invalid 
date, the data object is not minipulated in anyway. 

*************************/
bool Date::Set(const int m, const int d,const int y)
{
	bool GoodDate;
	if(checkDate(d,m,y))
	{
		day = d;
		month = m;
		year = y;
		GoodDate = true;
	}
	else
		GoodDate = false;

	return GoodDate;
}
/************************
GetMonth Function:
Returns the month of the date object

*************************/
int Date::GetMonth()
{
	return month;
}
/************************
GetDay Function:
Returns the day of the date object

*************************/
int Date::GetDay()
{
	return day;
}
/************************
GetYear Function:
Returns the year of the date object

*************************/
int Date::GetYear()
{
	return year;
}
/************************
SetFormat Function:
This function passes a char variable that is assigned to the format in which
the date object is printed. The conversion process is
T = Two-Digits
L = Long
J = Julian
D = Default

When the program is asked to 'Show' or print the date, it will use the current format
type in order to choose how it is displayed.

*************************/
bool Date::SetFormat(char f)
{
	switch(f)
	{
		case 'T':
			format = 'T';
			break;
		case 'L':
			format = 'L';
			break;
		case 'J':
			format = 'J';
			break;
		default:
			format = 'D';
	}
}
/************************
Increment Function:
This function increments the date by a certain number of days.
First, it converts the date object's date to Julian days, then adds the increment number of days.
It then goes through a series of if statements, finding out if we need to skip into the next year, 
multiple years, or staying in the same year. Once it has found the new date, it enters that date into 
the private class variables, and changes the date object.

*************************/
void Date::Increment(int numDays)
{
	
	int days;
		days = convertJulian(day,month,year); //How many days we currently have in our date.
	
		if((days + numDays) > DaysInYear(year)) //If we do  go over into the next year
		{
			if(YearsForward(days,year) > 1)//If we go further than 365 days in the future
			{
					int yFW = YearsForward(days,year), daySubtract = 0;
					for(int i = 1; i < yFW; i++)
					{
						daySubtract += DaysInYear(year+i);
					}
					year += yFW;
					days -= daySubtract;
					month = reverseJulianMonths(days,year);
					
					day = reverseJulianDays(days,year);



			}
			else //We're only going to the next year! Yea! It's simple now!
			{
				year++;
				days += numDays;
				
				days -= DaysInYear(year);
			
				day = reverseJulianDays(days,year);
				month = reverseJulianMonths(days,year);
			}


		}
		//Else,we are still in the same year
		else
		{
			days += numDays;

			//Set the values to their respective variables. 
			month = reverseJulianMonths(days,year);
			
			day = reverseJulianDays(days,year);

		}

}
/************************
Compare Function:
This function compares the passed date object with the calling date object.
It outputs a -1, 1, or 0 depending on if one is bigger then the other, or if they
are the same date.

*************************/
int Date::Compare(const Date& d)
{

	if((d.year > year))
		return 1;
	else if(year > d.year)
		return -1;
	else
	{
		if(d.month > month)
			return 1;
		else if(d.month < month)
			return (-1);
		else
		{
			if(d.day > day)
				return 1;
			else if(d.day < day)
				return -1;
			else
				return 0;
		}





	}
}
/************************
Operator Overload for << .. Pass in an 
ostream object to return the string of char


*************************/
ostream &operator << (ostream &S, Date &D)
{

	S<<D.month << '/' << D.day << '/' << D.year << endl;
	return S;
}
