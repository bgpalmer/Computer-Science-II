/*******************
* Brian Palmer
* 9.29.16
* Implementation of Plane Class
*******************/

#include "plane.hpp"

/*******************
* getAnt()
* PreReqs: none
* Parameters: none
* Post: none
* Description: Returns pointer to the ant cell
********************/

Cell * Plane::getAnt() const
{
	return ant;
}

/******************
* SetAnt(Cell*)
* preReq: none
* parameters: cell pointer
* post: none
* Description: sets the ant cell
*****************/

void Plane::setAnt(Cell * a)
{
	ant = a;
}

/*****************
* setField()
* preReq: none
* parameters: Pointers to pointers to cell class, int, int
* post: sets the field member
* description: sets the field member
******************/

void Plane::setField(Cell ** f, int r, int c)
{
	field = f;
	setRows(r);
	setColumns(c);
}

/******************
* getField()
* preReq: none
* parameters: none
* post: none
* description: returns pointer to pointer to cell class
**********************/

Cell ** Plane::getField() const
{
	return field;
}

/*******************
* getRows()
* preReq: none
* parameters: none
* post: none
* description: returns number of rows
******************/

const int Plane::getRows() const
{
	return rows;
}

/*******************
* getColumns()
* preReq: none
* parameters: none
* post: none
* description: returns number of columns
*******************/

const int Plane::getColumns() const
{
	return columns;
}

/******************
* setRows
* preReq: need integer
* parameter: int
* post: none
* description: sets the rows member
********************/

void Plane::setRows(const int r)
{
	rows = r;
}

/********************
* setColumns()
* preReq: need integer
* parameter: integer
* post: none
* description: sets the columns member
********************/

void Plane::setColumns(const int c)
{
	columns = c;
}

/*********************
* setVanNeurman()
* preReq: static array with 5 elements
* parameter: statuc array of pointers
* post: none
* description: sets the von neurmann neighborhood
***********************/

void Plane::setVanNeurman(Cell * arg[5])
{
	for (int i = 0; i < 5; i++)
	{
		VanNeurman[i] = arg[i];
	}
}

/*********************
* getVanNeurmann()
* preReq: none
* parameter: none
* description: returns the von neurmann neighborhood
*********************/

Cell * const * Plane::getVanNeurman() const
{
	return VanNeurman;
}


/********************\
* constructors and destructors
\********************/

Plane::Plane()
{
	Cell ** arr = new Cell * [20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = new Cell[20];
	}
	setField(arr, 20, 20);
	arr[10-1][10-1].setInternalColor('W');
	arr[10-1][10-1].setColor('*');
}

Plane::Plane(const int r, const int c)
{
	Cell ** arr = new Cell * [r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new Cell[c];
	}

	setField(arr, r, c);
}


Plane::~Plane()
{

	const int r = getRows();
	const Cell * const * arr = getField();

	for (int i = 0; i < r; i++)
		delete [] arr[i];
	delete [] arr;
}


/***********
* DisplayPlane()
* preReq: none
* parameter: none
* post: none
* description: prints out the field
***********/

void Plane::displayPlane()
{

	Cell ** array = getField();
	const int r = getRows();
	const int c = getColumns();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << array[i][j].getColor() << " ";
		}
		cout << endl;
	}
}

/******************8
* initalizeAntPosition
* preReq: need ant coordinates
* parameters: int, int
* post: none
* description: initializes the ants starting position
*******************/

void Plane::initializeAntPosition(int x, int y)
{
	const int r = getRows();
	const int c = getColumns();
	Cell ** field = getField();
	field[y][x].setColor('*');
	setField(field, r, c);
}

/****************
* updateLastCell
* PreReq: ants new cell should be determined
* parameters: none
* post: none
* description: changes the color of the ants last cell
*****************/

void Plane::updateLastCell(Cell * last)
{
	char c = last->getInternalColor();
	if (c == 'W')
	{
		last->setInternalColor('B');
		last->setColor('#');
	}
	else
	{
		last->setInternalColor('W');
		last->setColor(' ');
	}
}

/**************
* move()
* preReq: the ants facing direction should be updated
* parameter: none
* post: none
* description: updates the color member of the cell the ant is moving to, and updates the color of the last cell 
********************/

void Plane::move()
{
	Cell * nextMove;
	Cell * const * neighborhood = getVanNeurman();
	Cell * ant = neighborhood[2];
	char facing = ant->getFacing();
	

	switch(facing)
	{
		case 'N':
			nextMove = neighborhood[0];
			break;
		case 'E':
			nextMove = neighborhood[1];
			break;
		case 'W':
			nextMove = neighborhood[3];
			break;
		case 'S':
			nextMove = neighborhood[4];
			break;
	}

	nextMove->setColor('*');
	nextMove->setFacing(facing);
	updateLastCell(ant);
	Cell * arg[5] = {NULL};
	setVanNeurman(arg);
	setAnt(NULL);
}

/*****************
* updateFacing()
* preReq: the neighborhood member needs to be set first
* parameters: Cell pointer
* post: none
* description: this function changes the direction the ant is facing based on color of the cell the ant is on and the direction the ant is facing
*******************/

void Plane::updateFacing(Cell * ant)
{
	char newFacing;
	char color = ant->getInternalColor();
	char facing = ant->getFacing();

	switch (color)
	{
		case 'W':
		switch (facing)
		{
			case 'N':
				newFacing = 'W';
				break;
			case 'S':
				newFacing = 'E';
				break;
			case 'E':
				newFacing = 'N';
				break;
			case 'W':
				newFacing = 'S';
				break;
		}
		break;

	 	case 'B':
		switch (facing)
		{
			case 'N':
				newFacing = 'E';
				break;
			case 'S':
				newFacing = 'W';
				break;
			case 'W':
				newFacing = 'N';
				break;
			case 'E':
				newFacing = 'S';
				break;
		}
		break;
	}

	ant->setFacing(newFacing);
}

/***************
* createNeighborhood()
* PreReq: Ant must be on plane
* Parameters: None
* Post: Neighborhood built
* Descritpion: This function finds the ant, builds the neighborhood, and then sets the neighborhood member
*****************/


void Plane::createNeighborhood()
{

	Cell * vanNeurmanHood[5] = {NULL};
	Cell ** field = getField();
	const int r = getRows();
	const int c = getColumns();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (field[i][j].getColor() == '*')
			{
				if (i-1 < 0)
				{
					vanNeurmanHood[0] = &field[r-1][j];
				}
				else
					vanNeurmanHood[0] = &field[i-1][j];
				if (j-1 < 0)
				{
					vanNeurmanHood[1] = &field[i][c-1];
				}
				else
					vanNeurmanHood[1] = &field[i][j-1];
				vanNeurmanHood[2] = &field[i][j];
				if (j + 1 >= c)
				{
					vanNeurmanHood[3] = &field[i][0];
				}
				else
					vanNeurmanHood[3] = &field[i][j+1];
				if (i + 1 >= r)
				{
					vanNeurmanHood[4] = &field[0][j];
				}
				else
					vanNeurmanHood[4] = &field[i+1][j];
			}
		}
	}

	setAnt(vanNeurmanHood[2]);
	setVanNeurman(vanNeurmanHood);
}

/******************
* Update()
* preReqs: Plane should be built
* Parameters: none
* post: none
* Description: this function is the update phase during the program
*******************/

void Plane::update()
{
	createNeighborhood();
	Cell * ant = getAnt();
	updateFacing(ant);
	move();
}
