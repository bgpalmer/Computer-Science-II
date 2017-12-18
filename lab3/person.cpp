/****************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* implementation file for the person class
******************/

#include "person.hpp"

/***********
* getDie
* preReq: none
* parameter: none
* post: returns die
* description: returns die
******************/

Dice * Person::getDie() const
{
	return die;
}

/***************
* setDie
* preReq: none
* parameters: Dice *
* post: none
* description: sets the dice member
****************/

void Person::setDie(Dice * d)
{
	die = d;
}

/*****************
* updateWins
* preReq: need to know if this player one
* parameters; none
* post: wins column will be updated
* description: adds 1 to wins
* ******************/

void Person::updateWins() 
{
	setWins(getWins() + 1);
}

/********************
* setLoaded()
* preReq: need to know if the dice is loaded
* parameters: bool
* post: lets us know if dice is loaded
* description: lets us know if dice is loaded
**********************/

void Person::setLoaded(bool d)
{
	loaded = d;
}

/*******************
* getLoaded()
* preReq: member should be set
* parameters: none
* post: returns boolean value
* description: returns boolean value
********************/

bool Person::getLoaded() const
{
	return loaded;
}

/*******************
* getWins
* preReq: none
* parameters: none
* post: returns wins member
* description: returns wins member
*******************/

int Person::getWins() const
{
	return wins;
}

/********************
* setWins
* preReq: need num of wins to set
* parameters: int
* post: none
* description: sets wins member
**********************/

void Person::setWins(int w)
{
	wins = w;
}


/******************
* Person
* prereq: none
* parameters: bool
* post: creates person
* description: creates person
*******************/

Person::Person(bool d)
{
	loaded = d;
	die = NULL;
	setWins(0);
}


/*****************
* ~Person
* prereq: none
* parameters: none
* post: person object will be destroyed
* description: destroys person object
*******************/

Person::~Person()
{
	delete die;
}





