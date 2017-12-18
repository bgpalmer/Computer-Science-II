/*********************
* Brian Palmer
* 9.29.16
* Definition of Cell Class
*********************/

#ifndef _CELL_
#define _CELL_

#include "validation.hpp"

class Cell
{
private:
	char facing;
	char color;
	char intColor;
public:
	char getFacing() const;
	char getColor() const;
	void setFacing(char);
	void setColor(char);
	char getInternalColor() const;
	void setInternalColor(char);


	Cell * findAnt(); // may not be necessary

	Cell();
	Cell& operator=(const Cell &);
	~Cell();
};

#endif

