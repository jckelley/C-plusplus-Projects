/* ========================================================================== */
/*	PROGRAM: Assignment 7
	File: list.h,palindrome.cpp
	Purpose: Class Constructor File

    AUTHOR: Joseph  Springer
    FSU MAIL NAME: jcs11n@my.fsu.edu
    RECITATION SECTION NUMBER: 01
    
    COP 3330- SPR 13
    ASSIGNMENT NUMBER: 7
    DUE DATE: 04/19/2013
    PLATFORM: Unix g++ Compiler

*/

/* ========================================================================== */

#include <iostream>
#include "stack.h"

#include <string>
#include <cctype>

using namespace std;
const int MAX_CHAR_LIMIT = 100;
// ***************************************************************************
// * Function Name: IsPalinDrome
// * Description: Recieves a strine and returns true or false depending on if 
// * 				the string is a palindrome or not
// *
// *
// * Parameter Description: a string "x"
// *
// * Date: 03/04/2013
// * Author: Joseph Springer
// **************************************************************************
bool isPalinDrome(const string x)
{


	bool result;
	char value;
	string str = x;
	int length = str.length();
	string final = "";
	string cur;
	char find;
	int index = 0;

	Stack <char> MyStack;


	while(str[index] != '\0' && index < MAX_CHAR_LIMIT)
	{
		find = str[index];
		
		//If it is a alpha char
		if(isalpha(find))
		{
			find = (toupper(find));
			cur = find;
			//Append our final string that will be in forward order
			final.append(cur);
			//push it to the stack, which will place it in backward order
			MyStack.push(find);
		}
		index++;
	}

	
	//Now that we have it on the STACK in full uppercase, let us check if it is a palidnrome
	int i = 0;
	while(!MyStack.isStackEmpty())
	{
		char value;
		MyStack.pop(value);
	
		if(value == final[i])
			result = true;
		else
		{
			result = false;
			break;
		}
		index--;
		i++;

		
	}
	return result;

}

int main(void)
{
	string input = "x";

	cout << "Please Enter A String: ";
		getline(cin,input);

	do
	{
		

		//Now check and see if it is a palindrome:

		if(isPalinDrome(input))
		{
			cout << "\"" << input << "\"" << " Is a palindrome."<< endl;
		}
		else
		{
			cout << "\"" << input << "\"" << " Is NOT a palindrome."<< endl;
		}

		cout << "Please Enter A String: ";
				getline(cin,input);

	}while(input != "");






	return 0;
}











