/*********************************************************************
** Program Filename: item.hpp
** Author: brian palmer
** Date: 10.22.16
** Description: Item class declarations
** Input: "validation.hpp", string
** Output: none
*********************************************************************/

#ifndef _ITEM_
#define _ITEM_

#include "validation.hpp"
#include <string>
using std::string;
using std::toupper;

class Item
{
private:
	string name;
	string unit;
	int quantity;
	double unit_price;
	double ext_price;

public:
	string getName() const;
	string getUnit() const;
	int getQuantity() const;
	double getUnitPrice() const;
	double getExtPrice() const;

	void setName(string);
	void setUnit(string);
	void setQuantity(int);
	void setUnitPrice(double);
	void setExtPrice(double);

	bool operator==(const Item & obj) const;
	void calcExtPrice();

	Item(string n = "", int q = 0, double p = 0.00, string u = "CAN");
	~Item();

};

#endif
