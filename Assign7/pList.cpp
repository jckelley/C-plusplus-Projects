#include <iostream>

using namespace std;

struct Node
{
	char name[20];  //Name of up to 20 letters
	int age;		//Age
	float height;	//Height of person
	Node *next;		//Pointer to NEXT node!


};

void add_node_at_end(Node *start_ptr)
{
	Node *temp, *temp2; //Temp Pointers

	//Our Temp node Holder that will be Inserted
	temp = new Node;


	//Ask for input from user
	cout << "Please enter the name of the person: " ;
	cin >> temp->name;
	cout << "Please enter the age of the person: ";
	cin >> temp->age;
	cout << "Please enter the height of the person ";
	cin >> temp->height;
	//Since this is the end, it should point to NULL
	temp->next = NULL;

	//Set up link to this node
	if(start_ptr == NULL)
		start_ptr = temp;
	else
	{
		temp2 = start_ptr; //We know this is NOT null - list not empty!
		while (temp2->next != NULL)
			temp2 = temp2->next; //Move to next link in chain
		temp2->next = temp;
	}



}
void print_all_list(Node *start_ptr)
{
	Node *temp; //will be used to Navigate the list
	temp = start_ptr;

	cout << temp->next << endl;
	while(temp != NULL)
	{
	//Display details for what temp points too
	cout << "Name: " << temp->name << endl;
	cout << "Age: " << temp->age << endl;
	cout << "Height : " << temp->height << endl;
	cout << endl;
	temp = temp->next;
	}
}

int main(void)
{

	Node *start_ptr = NULL;
	add_node_at_end(start_ptr);

	print_all_list(start_ptr);






return 0;
}

