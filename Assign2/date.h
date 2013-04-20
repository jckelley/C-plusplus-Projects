/* ========================================================================== */
/*	PROGRAM: Date Class
	File: date.h
	Purpose: Class Header File

    AUTHOR: Joseph  Springer
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 2
    DUE DATE: 02/01/2013
    PLATFORM: Unix g++ Compiler

SUMMARY

This file is to act with the 'date.pp' file to construct a date class. This class
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
#include <string>

using namespace std;

/* ========================================================================== */
/*							CONSTANT PROGRAM VARIABLES							*/
/* ========================================================================== */
const int DEFAULT_DAY = 1;
const int DEFAULT_MONTH = 1;
const int DEFAULT_YEAR = 2000;
const int MAX_YEAR = 9999;
const int MIN_YEAR = 0;
const char SLASH = '/';
const int MonthDays [] = {00,31,28,31,30,31,30,31,31,30,31,30,31};
const string MONTHS [] ={" ", "Jan", "Feb", "Mar", "Apr", "May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
const string TWODIGITS [] = {"00","01","02","03","04","05","06","07","08","09","10",
							"11","12","13","14","15","16","17","18","19","20",
							"21","22","23","24","25","26","27","28","29","30",
							"31","32","33","34","35","36","37","38","39","40",
							"41","42","43","44","45","46","47","48","49","50",
							"51","52","53","54","55","56","57","58","59","60",
							"61","62","63","64","65","66","67","68","69","70",
							"71","72","73","74","75","76","77","78","79","80",
							"81","82","83","84","85","86","87","88","89","90",
							"91","92","93","93","94","95","96","97","98","99"};
const string THREEDIGITS [] = {"000","001","002","003","004","005","006","007","008","009","010",
							"011","012","013","014","015","016","017","018","019","020",
							"021","022","023","024","025","026","027","028","029","030",
							"031","032","033","034","035","036","037","038","039","040",
							"041","042","043","044","045","046","047","048","049","050",
							"051","052","053","054","055","056","057","058","059","060",
							"061","062","063","064","065","066","067","068","069","070",
							"071","072","073","074","075","076","077","078","079","080",
							"081","082","083","084","085","086","087","088","089","090",
							"091","092","093","093","094","095","096","097","098","099"};
/* ========================================================================== */
		




/* ========================================================================== */
/*								CLASS DEFINITIONS								*/
/* ========================================================================== */				

class Date
{
	//Public functions
	public: 
		friend istream &operator>>(istream &s, Date &S);
		friend ostream &operator<<(ostream &,Date &);
		//Date();
		//NOTE: We do not need a default constructor because the below constructor will use default values
		Date(int m = DEFAULT_MONTH,  int d = DEFAULT_MONTH, int y = DEFAULT_YEAR); 
		void Input();
		void Show();
		bool Set(int m, int d, int y);
		int GetMonth();
		int GetDay();
		int GetYear();
		bool SetFormat(char f);
		void Increment(int numDays =1);
		int Compare(const Date& d);

		//Private Variables
	private:
		int day, month, year;
		char format;





};