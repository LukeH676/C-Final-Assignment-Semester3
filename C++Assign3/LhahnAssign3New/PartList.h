
/*

********** Lucas Hahn Assignment #3 2016 Semester 3 ********************

creating nodes on a list for Part of a ... dating service?

*/
#include <iostream>
#include <string>

using namespace std;



struct Part
{
public:
	string partNo;
	string description;
	int qty;
	Part *link;

};

class PartList
{
private:
	Part *firstPtr;
	string productName;
	int noParts;

public:
	PartList(string /*product name*/);
	//PartList();
	~PartList();
	void showParts(ostream &)const;
	void addPart();
	void removePart(string/*part number*/);
	int getNoParts()const { return noParts; }
	string getProductName() { return productName; }

};