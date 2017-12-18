/***************
* Brian Palmer
* 10.12.16
* palmebri@oregonstate.edu
* main file
*****************/

#include "game.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	Game g;
	const int MAX_NUM_SIDES = 25;
	const int MIN_NUM_SIDES = 4;
	const int MAX_NUM_ROUNDS = 10000;
	const int MIN_NUM_ROUNDS = 1;
	g.setup();
	g.play();
	g.print();
	g.file();
	return 0;
}

