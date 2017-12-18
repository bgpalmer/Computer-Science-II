/*******************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* header file for dice class
******************/

#ifndef _DICE_
#define _DICE_
#include "validation.hpp"

class Dice
{
private:
	int sides;
public:
	int getSides() const;
	void setSides(int);
	virtual	int roll();
	Dice(int s = 6);
};

#endif
