/*

********** Lucas Hahn Assignment #3 2016 Semester 3 ********************

creating nodes on a list for Part Numbers of a ... dating service?

*/
#include <iostream>
#include <string>
#include "Partlist.h"
#include <iomanip>
#include "assert.h"


using namespace std;



PartList::PartList(string newName)
{
	productName = newName;
	noParts = 0;
	firstPtr = NULL;

}

PartList::~PartList()
{
	delete firstPtr;
}

void PartList::showParts(ostream &out)const
{
	Part *walker = firstPtr;
	if (firstPtr == NULL)
		out << "there are no Parts" << endl << endl;
	else
	{
		out << left << setw(20) << "Product Name: " << productName << endl;
		out << left << setw(20) << "Part Number"
			<< right << setw(10) << "Description "
			<< right << setw(10) << "quantity " << endl;
		while (walker != NULL)
		{


			out << left << setw(20) << walker->partNo
				<< right << setw(10) << walker->description <<
				right << setw(10) << walker->qty << endl;

			walker = walker->link;
		}
	}

}

void PartList::addPart()
{
	string newPartNo;
	string newDesc;
	int newQty;

	/* if numbers are used for PartNo, not sure how to make 10 be after 7
	(I am assuming the compiler is only reading first digit) */

	cout << "Enter Part Number: ";
	getline(cin, newPartNo);
	while (newPartNo.length() == 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Please enter a partNo: ";
		getline(cin, newPartNo);
	}
	cout << "Enter Description: ";
	getline(cin, newDesc);
	while (newDesc.length() == 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << " Please enter a description: ";
		getline(cin, newDesc);
	}
	cout << "Enter quantity: ";
	cin >> newQty;
	while (newQty <= 0 || newQty > 50 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Must be a number larger than 0 less than 50, re-enter: ";
		cin >> newQty;
	}

	cin.ignore(80, '\n');

	Part *stalker = NULL, *walker = firstPtr;

	while (walker != NULL)
	{
		if (walker->partNo >= newPartNo)
			break;
		stalker = walker;
		walker = walker->link;
	}
	if (walker != NULL && walker->partNo == newPartNo)
	{

		cout << endl << newPartNo << " Already Exists" << endl;
	}
	else
	{
		Part *builder = new Part;
		assert(builder != 0);
		builder->partNo = newPartNo;
		builder->description = newDesc;
		builder->qty = newQty;
		builder->link = walker;
		noParts++;
		if (walker == firstPtr)
		{
			firstPtr = builder;
			cout << "Node was created for - " << builder->partNo << endl;
		}
		else
		{
			cout << "Node was created for - " << builder->partNo << endl;
			stalker->link = builder;
		}
	}

}

void PartList::removePart(string partNum)
{
	Part *stalker = NULL, *walker = firstPtr;

	while (walker != NULL)
	{

		if (walker->partNo == partNum)
			break;
		stalker = walker;
		walker = walker->link;

	}
	if (walker == NULL)

		cout << "Part Not Found try a different Part number" << endl;
	else
	{
		if (stalker == NULL)
			firstPtr = walker->link;
		else
			stalker->link = walker->link;
		delete walker;
		cout << "Part deleted";
	}
}