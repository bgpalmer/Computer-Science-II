/*********************************************************************
** Program Filename: player.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Player function implementation
** Input: none
** Output: none
*********************************************************************/

#include "player.hpp"

/*********************************************************************
** Function: Player
** Description: Player Constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Player::Player()
{
        losses = 0;
        wins = 0;
        points = 0;
        lineup = NULL;
        fainted = NULL;

        lineup = new Queue;
        fainted = new Stack;
}

/*********************************************************************
** Function: Player destructor
** Description: Player destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Player::~Player()
{
        delete lineup;
        delete fainted;
}

/*********************************************************************
** Function: get_lineup()
** Description: returns players lineup
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Queue *
*********************************************************************/

Queue * Player::get_lineup()
{
        return lineup;
}

/*********************************************************************
** Function: get_fainted
** Description: returns stack of players fainted creatures
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Stack *
*********************************************************************/

Stack * Player::get_fainted()
{
        return fainted;
}

/*********************************************************************
** Function: won
** Description: update win count and points
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Player::won()
{
        wins++;
        update_points();
}

/*********************************************************************
** Function: lost
** Description: update loss count and points
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Player::lost()
{
        losses++;
        update_points();
}

/*********************************************************************
** Function: get_points
** Description: returns points
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

int Player::get_points()
{
        return points;
}

/*********************************************************************
** Function: update points
** Description: calculates points based on number of wins and losses
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Player::update_points()
{
        points = (wins * 2) - losses;
}

/*********************************************************************
** Function: display_stats
** Description: display wins, losses, and points
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Player::display_stats()
{
        cout << "wins = " << wins << " || losses = " << losses << " || points = " << points;
}
