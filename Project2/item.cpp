/*********************************************************************
** Program Filename: item.cpp
** Author: brian palmer
** Date: 10.22.16
** Description: item class prototype declarations
** Input: "item.hpp"
** Output: none
*********************************************************************/

#include "item.hpp"

/****************
* getName
* preReq: none
* parameters: none
* post: none
* description: returns name
*****************/

string Item::getName() const
{
	return name;
}

/**************
* getUnit
* preReq: none
* parameters: none
* post: none
* description: gets units
****************/

string Item::getUnit() const
{
	return unit;
}

/***************
* getQuantity()
* preReq: none
* parameters: none
* post: none
* description: gets quantity
**************/

int Item::getQuantity() const
{
	return quantity;
}

/***************
* getUnitPrice()
* preReq: none
* parameters: none
* post: none
* description: returns unit price
*****************/

double Item::getUnitPrice() const
{
	return unit_price;
}

/*****************
* getExtPrice
* preReq: none
* parameters: none
* post: none
* description: returns ext price
*****************/

double Item::getExtPrice() const
{
	return ext_price;
}

/****************
* setName
* preReq: none
* parameters: none
* post: none
* description: sets name
*****************/

void Item::setName(string n)
{
	name = n;
}

/***************
* setUnit
* preReq: none
* paramters: Unit
* post: none
* description: sets unit member
**************/

void Item::setUnit(string u)
{
	unit = u;
}

/*************
* setQuantity
* preReq: none
* parameters: int
* post: none
* description: sets quantity member
*************/

void Item::setQuantity(int q)
{
	quantity = q;
}

/****************
* setUnitPrice
* preReq: none
* parameters: double
* post: none
* description: sets unit price member
****************/

void Item::setUnitPrice(double d)
{
	unit_price = d;
}

/***************
* setExtPrice
* preReq: none
* parameters: double
* post: none
* description: sets ext price
***************/

void Item::setExtPrice(double e)
{
	ext_price = e;
}

/*****************
* calcExtPrice
* preReq: none
* parameters: none
* post: none
* description: calculates external price and sets it
***************/

void Item::calcExtPrice()
{
	setExtPrice(getUnitPrice() * getQuantity());
}

/*******
constructor
********/

Item::Item(string n, int q, double m, string u)
{
	setName(n);
	setQuantity(q);
	setUnitPrice(m);
	setUnit(u);
	calcExtPrice();
}

/***********
* destructor
**********/

Item::~Item() {}

/***************
* operator==
* preReq: none
* parameters: none
* post: none
* description: comparison
***************/

bool Item::operator==(const Item & obj) const
{
        bool checkName = cmpString(this->getName(), obj.getName());

        if (checkName)
        {
                return true;
        }
        else
                return false;
}
