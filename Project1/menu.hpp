/*******************
* Brian Palmer
* 10.3.16
* palmebri@oregonstate.edu
* Header File of the menu class
*********************/

#ifndef _MENU_
#define _MENU_

#include "plane.hpp"


class Menu
{
private:
	Plane * field;
	int numGenerations;
	int xCoord;
	int yCoord;
	int width;
	int height;
	

public:
	Plane * const getField() const;
	int getNumGenerations() const;
	int getXcoord() const;
	int getYcoord() const;
	int getWidth() const;
	int getHeight() const;
	void setField(Plane *);
	void setNumGenerations(int);
	void setXcoord(int);
	void setYcoord(int);
	void setWidth(int);
	void setHeight(int);
	
	void Start();
	void AskUserForNumGenerations();
	void randomAntCoordinates();
	void buildPlane();
	void userDeterminesAntCoordinates();
	void setAntStartPosition(int,int);
	void facilitateSettingStartingPos();			
	int facilitateIntInputWithinRange(int, int);

	~Menu();
	Menu();
};

#endif	
