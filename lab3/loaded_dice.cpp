/***************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* loaded dice implementation file
******************/

#include "loaded_dice.hpp"

/**************
* roll
* preReq: none
* parameters: none
* post: returns int
* description: loaded die will roll higher numbers more often
******************/

int Loaded_Dice::roll()
{
	const int s = getSides();
	int roll = getRandomPosInt(s+s) + 1;
	if (roll > s)
	{
		return s;
	}
	else
	{
		return roll;
	}

}


/****************
* loaded_dice constructor
* prereq: none
* parameters: none
* post: none
* description: creates loaded die
********************/

Loaded_Dice::Loaded_Dice(int s) : Dice(s) {}

