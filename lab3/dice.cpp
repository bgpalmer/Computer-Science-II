/*******************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* imp file for dice class
*********************/

#include "dice.hpp"

/******************
* roll
* preReq: none
* parameters: none
* post: returns integer
* description: returns random pos integer between 1 - # of sides
******************/

int Dice::roll()
{	
	return (getRandomPosInt(getSides()) + 1);
}
	
/*****************
* getSides()
* preReq: none
* parameters: none
* post: returns sides
* description: returns sides
*******************/

int Dice::getSides() const
{
	return sides;
}

/**********************
* setSides()
* preReq: none
* parameters: int
* post: sets sides member
* description: sets sides member
************************/

void Dice::setSides(int s)
{
	sides = s;
}

/********************
* Dice constructor
* preReq: none
* parameters: int
* post: creates object
* description: creates dice object
***********************/

Dice::Dice(int sides)
{
	setSides(sides);
}
