/*******************
* Brian Palmer
* 9.29.16
* Definition of plane class
*******************/

#ifndef _PLANE_
#define _PLANE_
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#include "cell.hpp"

class Plane
{
private:
	Cell ** field;
	int rows;
	int columns;
	Cell * VanNeurman[5];
	Cell * ant;
public:
	void setVanNeurman(Cell * arg [5]);
	void setField(Cell ** f, int rows, int cols);
	void setRows(const int);
	void setColumns(const int);
	void setAnt(Cell *);
	const int getRows() const;
	const int getColumns() const;
	Cell ** getField() const;
	Cell * const * getVanNeurman() const;
	Cell * getAnt() const;

	Plane();
	Plane(int rows, int col);
	~Plane();
	void displayPlane();

	void initializeAntPosition(int x, int y);
	Cell * findAnt(); // can likely delete due to createNeighborhood
	void updateFacing(Cell *);
	void createNeighborhood();
	void move();
	void updateLastCell(Cell * last);
	void update();
};


#endif
