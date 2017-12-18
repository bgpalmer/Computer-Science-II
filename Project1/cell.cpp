/*********************
* Brian Palmer
* 9.29.16
* Implementation of Cell Class
*********************/

#include "cell.hpp"

/******************
* Setters and Getters for members
******************/

char Cell::getFacing() const
{
	return facing;
}

char Cell::getColor() const
{
	return color;
}

char Cell::getInternalColor() const
{
	return intColor;
}

void Cell::setInternalColor(char c)
{
	intColor = c;;
}

void Cell::setFacing(char f)
{
	facing = f;
}

void Cell::setColor(char c)
{
	color = c;
}

/***************
* constructors and destructors
*****************/

Cell::Cell()
{
	setFacing('N');
	setColor(' ');
	setInternalColor('W');
}


Cell& Cell::operator=(const Cell &obj)
{
	setFacing(obj.getFacing());
	setColor(obj.getColor());
	setInternalColor(obj.getInternalColor());	

	return *this;
}

Cell::~Cell() {};
