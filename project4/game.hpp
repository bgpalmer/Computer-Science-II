/*********************************************************************
** Program Filename: game.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: game class template
** Input: none
** Output: none
*********************************************************************/

#ifndef GAME
#define GAME

#include "player.hpp"
#include "helper_functions.hpp"
#include <iostream>
#include <fstream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

class Game
{
private:
        Player * player1;
        Player * player2;
        string winning;

        void set_lineups();
        Creature * battle(Creature *, Creature *);
        void simulate_battles();
        void print_stats();

        void add_creature_to_lineup(Creature *);
        Creature * get_users_creature_choice();
        void setup_computer_player();
        void update_winning();

        // http://www.cplusplus.com/forum/articles/7312/
        void press_enter_to_continue();

public:
        void start();

        Game();
        ~Game();
};

#endif
