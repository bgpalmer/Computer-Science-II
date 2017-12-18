/*********************************************************************
** Program Filename: player.cpp
** Author: brian palmer
** Date: 12.01.16
** Description: player class definitions
** Input: none
** Output: none
*********************************************************************/

#include "player.hpp"

// Player constructor

Player::Player(string n, Space * c) : Creature(n, c)
{
        backpack = new Stack;
        won = false;
        moved = false;
        game_over = false;
        death_counter = 10;
}

// player destructor
Player::~Player()
{
        delete backpack;
}

// won member accessor
bool Player::get_won()
{
        return won;
}

/*********************************************************************
** Function: move
** Description: creates menu for user of reachable locations. Users choice
is assigned to users curr_space member. User has option to back out with 'X'.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: void
*********************************************************************/
void Player::move()
{
        string v_letters;
        cout << "\n\t:::Move:::\n\n";
        cout << "** Moves left: " << death_counter << "\n\n";
        if (curr_space->get_up() != NULL)
        {
                cout << "[N] " << curr_space->get_up()->get_type() << "\n";
                v_letters += "nN";
        }
        if (curr_space->get_down() != NULL)
        {
                cout << "[S] " << curr_space->get_down()->get_type() << "\n";
                v_letters += "sS";
        }
        if (curr_space->get_left() != NULL)
        {
                cout << "[E] " << curr_space->get_left()->get_type() << "\n";
                v_letters += "eE";
        }
        if (curr_space->get_right() != NULL)
        {
                cout << "[W] " << curr_space->get_right()->get_type() << "\n";
                v_letters += "wW";
        }
        cout << "\n[X] Don't move\n";
        v_letters+="xX";
        string response = facilitateNameInput(v_letters);
        const char * c_str = response.data();
        char choice = c_str[0];
        switch(choice)
        {
                case 'N':
                        curr_space = curr_space->get_up();
                        moved = true;
                        break;
                case 'S':
                        curr_space = curr_space->get_down();
                        moved = true;
                        break;
                case 'E':
                        curr_space = curr_space->get_left();
                        moved = true;
                        break;
                case 'W':
                        curr_space = curr_space->get_right();
                        moved = true;
                        break;
                case 'X':
                        break;

        }
        if (moved == true)
                cout << "\n** " << get_type() << " moved to " << curr_space->get_type() << "**\n\n";
        else
                cout << "\n" << get_type() << " remains in " << curr_space->get_type() << "\n\n";
}

/*********************************************************************
** Function: turn
** Description: User chooses whether to Move, look in their backpack,
or Inspect the area they are currently in. Inspecting their current area
calls the spaces virtual Inspect member, the special attribute for that space
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Player::turn()
{
        do
        {
                cout << "\t:::" << curr_space->get_type() << ":::\n\n";
                cout << "1) Inspect Area\n";
                cout << "2) Open Backpack\n";
                cout << "3) Move\n";


                int i = facilitateIntInput(1,4);
                switch(i)
                {
                        case 1:
                                won = curr_space->inspect(backpack);
                                break;
                        case 2:
                                backpack->open();
                                break;
                        case 3:
                                move();
                                break;
                }
                if (moved == true)
                {
                        death_counter--;
                        moved = false;
                }
                if (death_counter == -1 || won == true)
                {
                        game_over = true;
                }
        } while (game_over == false);
}
