#include <iostream>
#include "ListOfParts.h"

using namespace std;


ListOfParts::ListOfParts()
{
	size = 0;
	Head = NULL;
}
int ListOfParts::Count()
{
	return size;
}
int ListOfParts::Add(CarPart *NewItem)
{
	CarPart *temp = new CarPart;

	temp = NewItem;
	temp->Next = Head;
	Head = temp;
	return size++;
}
CarPart *ListOfParts::Retrieve(int Position)
{
	CarPart *Current = Head;

	for(int i = Count() -1;  ( i > Position && Current != NULL)  ; i--)
	{
		Current = Current->Next;
	}
	return Current;
}
bool ListOfParts::Delete()
{

	if(Head==NULL)
	{
		cout << "The List is empty \n";
		return false;
	}
	else
	{
		CarPart *Current;
		Current = Head;
		Head = Head->Next;
		delete Current;
		size--;
		return true;
	}
}
bool ListOfParts::Delete(int Position)
{
	if(Retrieve(Position) == NULL)
	{
		cout << "Nothing at That Position \n";
		return false;
	}
	else
	{
		CarPart *Current, *BackPart, *ForwardPart;
		Current = Retrieve(Position);


		cout << "We are about to delete " << Current->PartName << endl;
		cout << "The item before us is " << BackPart->PartName << endl;
		cout << "The Item after us is " << ForwardPart->PartName << endl;
		Retrieve(Position-1)->Next = Retrieve(Position+1);
		size--;

		return true;
	}

}