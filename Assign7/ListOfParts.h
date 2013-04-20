
//------------------------------------

struct CarPart
{
	long PartNumber;
	char PartName[40];
	double UnitPrice;

	CarPart *Next;
};

//------------------------------------

class ListOfParts
{
public:
	ListOfParts();
	int Count();
	CarPart *Head;

	//List Operations
	int Add(CarPart *Item);
	CarPart *Retrieve(int pos);
	bool Delete();
	bool Delete(int pos);

private:
	int size;
};