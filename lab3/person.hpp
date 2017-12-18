/*****************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* header file for the person class
*******************/

#ifndef _PERSON_
#define _PERSON_
#include "dice.hpp"
#include <string>

using std::string;

class Person
{
private:
	int wins;
	char loaded;
	Dice * die;	
public:
	void setDie(Dice *);
	Dice * getDie() const;


	int getWins() const;
	void setWins(int);
	void updateWins();
	void setLoaded(bool);
	bool getLoaded() const;
	Person(bool);
	~Person();
};

#endif
