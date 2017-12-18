#include "player.hpp"

Player::Player(string n, int a, int d, int h, Space * c) : Creature(n,a,d,h,c)
{
        hand = NULL;
        backpack = NULL;
        health = 100;
}

Player::~Player()
{
        curr_space = NULL;
        if (backpack != NULL)
                delete backpack;
}

void Player::pick_up(Item * i)
{
        hand = i;
}

void Player::turn()
{
        curr_space->menu();
        maybe_move();
}

void Player::maybe_move()
{
        cout << "\t:::Move?:::\n\n";
        cout << "1) " << curr_space->get_clockwise()->get_type() << "\n";
        cout << "2) " << curr_space->get_counter_clockwise()->get_type() << "\n";
        cout << "3) " << curr_space->get_town()->get_type() << "\n";
        cout << "4) Do not move\n";
        int choice = facilitateIntInput(1,5);
        switch(choice)
        {
                case 1:
                        curr_space = curr_space->get_clockwise();
                        cout << "Moved to " << curr_space->get_type() << "\n";
                        break;
                case 2:
                        curr_space = curr_space->get_counter_clockwise();
                        cout << "Moved to " << curr_space->get_type() << "\n";
                        break;
                case 3:
                        curr_space = curr_space->get_town();
                        cout << "Moved to " << curr_space->get_type() << "\n";
                        break;
                case 4:
                        cout << "Staying Put.\n";
                        break;
        }
}
