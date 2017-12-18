/***************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* loaded dice definitions file
********************/

#ifndef _LOADED_
#define _LOADED_

#include "validation.hpp"
#include "dice.hpp"

class Loaded_Dice : public Dice
{
public:
	virtual int roll();
	Loaded_Dice(int i = 6);
};

#endif


