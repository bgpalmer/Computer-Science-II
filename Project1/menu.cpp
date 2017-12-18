/********************
* Brian palmer
* 10.3.16
* palmebri@oregonstate.edu
* Implementation file of the menu class
************************/

#include "menu.hpp"

/***************
* plane * getField
* This function returns the plane class
****************/

Plane * const Menu::getField() const
{
	return field;
}

/******************
* setField(Plane *)
* This function sets the created plane class
****************/

void Menu::setField(Plane *f)
{
	field = f;
}

/*****************
* setNumGenerations(int)
* sets the number of generations
****************/

void Menu::setNumGenerations(int g)
{
	numGenerations = g;
}

/******************
* getNumGenerations()
* returns the numberof generations
****************/

int Menu::getNumGenerations() const
{
	return numGenerations;
}

/*******************
* getXcoord()
* returns the desired coordinate for the starting ant position
*********************/

int Menu::getXcoord() const
{
	return xCoord;
}

/*******************
* getYcoord()
* returns the desired y coordinate for the starting ant position
******************/

int Menu::getYcoord() const
{
	return yCoord;
}

/******************8
* setXcoord
* sets the desired x coordinated of the desired ant starting location
******************/

void Menu::setXcoord(int x)
{
	xCoord = x;
}

/******************
* setYcoord
* sets the desired y coordinate of the desired ant starting location
******************/

void Menu::setYcoord(int y)
{
	yCoord = y;
}

/*********************
* getWidth()
* returns the desired width of the plane
*********************/

int Menu::getWidth() const
{
	return width;
}

/*****************
* setWidth()
* sets the desired width of the plane
******************/

void Menu::setWidth(int w)
{
	width = w;
}

/********************
* setHeight()
* sets the desired height of the plane
********************/

void Menu::setHeight(int h)
{
	height = h;
}

/*********************
* getHeight()
* returns the desired height of the plane
********************/

int Menu::getHeight() const
{
	return height;
}

/*********************
* checkInputAgainstRange(string)
* This functions asks user for integer, confirms type, and returns the integer 
*******************/

int Menu::facilitateIntInputWithinRange(int start, int end)
{
	int value;
	string input;
	bool checkInt = false;
	bool checkRange = false;
	do
	{
		cout << " >> ";
		cin >> input;

		checkInt = checkIfInt(input);
		while(!checkInt)
		{
			cout << "Input needs to be an integer, please try again." << endl;
			cout << " >> ";
			cin >> input;
			checkInt = checkIfInt(input);
		}
		value = atoi(input.c_str());
		checkRange = checkIfIntInRange(value, start, end);
		if (!checkRange)
		{
			cout << "The value you entered is out of the specified range [" << start << "," << end-1 <<"). Please enter a different value." << endl;
		}	
	}
	while (!checkRange);
	return value;	
}

/**************************
* FacilitateSettingStartingPosition
* PreReqs: None
* Post: Menu xCoord and yCoord will be set with integers
* Description: this function will set the xCoord or yCoord members with user input integers or randomly selected integers 

* -> setAntStartingPosition
* -> userDeterminesAntCoordinates
* -> randomAntCoordinates

*************************/

void Menu::facilitateSettingStartingPos()
{
	string input;
	bool validResp;
	char response;
	cout << "Would you like to choose where the ant begins (Y or N)? If N, a random position will be chosen for you." << endl;
	do
	{
		cout << "Y or N: ";
		cin >> input;
		validResp = validateYNresponse(input);
		if (!validResp)
		{
			cout << "Can only accept a Y or N answer, please try again" << endl;
		}
	} while (!validResp);
	
	response = convertYNtoUpper(input);
	
	switch(response)
	{
		case 'Y': 
			userDeterminesAntCoordinates();
			break;
		case 'N':
			randomAntCoordinates();
			break;
	}
	int x = getXcoord();
	int y = getYcoord();
	setAntStartPosition(x,y);
}

void Menu::setAntStartPosition(int x, int y)
{

	Plane * const temp = getField();
	temp->initializeAntPosition(x,y);		
	setField(temp);
}
		

void Menu::userDeterminesAntCoordinates()
{
	int w = getWidth();
	int h = getHeight();

	cout << "What should the X coordinate be? (0 - " << w-1 << ")" << endl;
	int response = facilitateIntInputWithinRange(0, w);
	setXcoord(response);

	cout << "What should the Y coordinate be? (0 - " << h-1 << ")" << endl;
	response = facilitateIntInputWithinRange(0, h);
	setYcoord(response);
}

void Menu::randomAntCoordinates()
{
	int w = getWidth();
	int h = getHeight();
	int r1 = getRandomPosInt(w);
	int r2 = getRandomPosInt(h);
	setXcoord(r1);
	setYcoord(r2);	
}
	
/*****************************
* buildPlane()
* Asks user for width and height and builds plane as user desires.
****************************/

void Menu::buildPlane()
{
	string input;
	cout << "What would you like the height to be (1 - 1000)? " << endl;
	int h = facilitateIntInputWithinRange(1, 1001);
	cout << "What would you like the width to be? (1 - 1000)? " << endl;
	int w = facilitateIntInputWithinRange(1, 1001);
	setWidth(w);
	setHeight(h);
	Plane p(w,h);
	Plane * temp = &p;	
	setField(temp);
}

/***************************
* AskUserForNumGenerations
* Prereqs: NONE
* Post: Number of generations will be set
***********************/

void Menu::AskUserForNumGenerations()
{
	cout << "How many generations would you like? (1 - 30000)" << endl;
	int response = facilitateIntInputWithinRange(1, 30001);	
	setNumGenerations(response);
}

/**********************
* Start()
* PreReqs: The number of generations should be recorded, 

* Starts the loop 
********************/

void Menu::Start()
{
	Plane * const field = getField();
	cout << " --> Rows: " << field->getRows() << endl;
	cout << " --> Columns: " << field->getColumns() << endl;

	int generations = getNumGenerations();
	int iterator = 0;
	field->update();
	iterator++;
	cout << iterator;
}


/********************
* Menu Constructor
* PreReq: None
* Parameters: None
* Post: Will create Menu Object
* Description: This creates the menu object
********************/

Menu::Menu()
{
	setField(NULL);
	setNumGenerations(0);
	setXcoord(0);
	setYcoord(0);
	setWidth(0);
	setHeight(0);
}

/********************
* Menu Destructor
* PreReq: None
* Parameters: None
* Post: Deletes Menu Object
* Description: Destructor for class
*********************/

Menu::~Menu() {field = NULL; }
