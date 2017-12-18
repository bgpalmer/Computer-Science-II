/*********************************************************************
** Program Filename: player.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: player class template
** Input: none
** Output: none
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "creature.hpp"
#include "stack.hpp"
class World;
class Player : public Creature
{
private:
        int death_counter;
        bool won;
        bool moved;
        bool game_over;
        friend class World;
        Stack * backpack;
public:
        Player(string n = "Player", Space * c = NULL);
        ~Player();

        bool get_won();
        void move();
        virtual void turn();
        void open_pack();
};

#endif
