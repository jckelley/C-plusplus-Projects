#include <iostream>
#include <string.h>
#include "ListOfParts.h"

using namespace std;

int main(void)
{
	ListOfParts *Parts = new ListOfParts();

	CarPart     *Part;



	Part  = new CarPart;

	Part->PartNumber = 9743;

	strcpy(Part->PartName, "Air Filter");

	Part->UnitPrice  = 8.75;

	Parts->Add(Part);

	

	Part  = new CarPart;

	Part->PartNumber = 27487;

	strcpy(Part->PartName, "Clutch Disk");

	Part->UnitPrice  = 47.15;

	Parts->Add(Part);



	Part  = new CarPart;

	Part->PartNumber = 87873;

	strcpy(Part->PartName, "Brake Disk");

	Part->UnitPrice  = 35.15;

	Parts->Add(Part);



	Part  = new CarPart;

	Part->PartNumber = 27644;

	strcpy(Part->PartName, "A/C Filter Drier");

	Part->UnitPrice  = 55.55;

	Parts->Add(Part);




	if(Parts->Delete(2))
	{
		cout <<" We Deleted Item Two!" << endl;
	}

	cout << "Number of Parts: " << Parts->Count() << endl;

		for(int i = 0; i < Parts->Count(); i++)

	{

		CarPart* One = Parts->Retrieve(i);



		cout << "\nCar Part Information";

		cout << "\nPart #:      " << One->PartNumber;

		cout << "\nDescription: " << One->PartName;

		cout << "\nUnit Price: $" << One->UnitPrice << endl;

	}



	cout << endl;

	

	return 0;
}