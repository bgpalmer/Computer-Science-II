/******************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* game header file
**********************/

#ifndef _GAME_
#define _GAME_
#include <fstream>
#include <cstdlib>
#include "dice.hpp"
#include "loaded_dice.hpp"
#include "person.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using std::setw;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include "menu_functions.hpp"

const int MAX_NUM_SIDES = 25;
const int MIN_NUM_SIDES = 4;
const int MAX_NUM_ROUNDS = 10000;
const int MIN_NUM_ROUNDS = 1;


class Game
{
private:
	Person * player1;
	Person * player2;

	int rounds;

public:

	void file();
	
	Person * createPlayer();

	Person * getPlayer1() const;
	Person * getPlayer2() const;

	void setPlayer1(Person *);
	void setPlayer2(Person *);
	
	string calcWinner() const;
	
	int determineRounds();
	int getRounds() const;
	void setRounds(int);
	
	void setup();
	void play();
	void print() const;

	Game();
	~Game();
};

#endif

