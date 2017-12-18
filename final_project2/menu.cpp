/*********************************************************************
** Program Filename: menu.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: menu implementation
** Input: none
** Output: none
*********************************************************************/

#include "menu.hpp"

/*********************************************************************
** Function: Menu abstract class constructor
** Description: creates menu
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Menu::Menu()
{
        choice = -1;
        done = false;
}

/*********************************************************************
** Function: Menu destructor
** Description: destroys Node
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Menu::~Menu()
{
        // intentionally blank
}

/*********************************************************************
** Function: main menu
** Description: gives user option to learn more about the game or start a new game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: program should end
** Return: none
*********************************************************************/

void Menu::main_menu()
{
        do
        {
                cout << " ** Welcome to the beverage factory ** \n\n";
                cout << "\t:::MENU:::\n\n";
                cout << "1) Learn about the game\n";
                cout << "2) Start the game\n";
                cout << "3) Quit\n";
                int s = facilitateIntInput(1,4);
                switch(s)
                {
                        case 1:
                                learn();
                                break;
                        case 2:
                                start();
                                break;
                        case 3:
                                done = true;
                                break;
                }
        }
        while (done == false);
}

/*********************************************************************
** Function: start
** Description: starts a new game
** Parameters: none
** Pre-Conditions: user selects this from main menu
** Post-Conditions: user be brought back to the main menu
** Return: none
*********************************************************************/

void Menu::start()
{
        cout << "Time to go!\n\n";
        Player me;
        World little;
        me.set_curr_space(little.get_power_plant() [0][0]);
        me.turn();
        if (me.get_won())
                cout << "\n\nPlayer Wins!\n\n";
        else
                cout << "\n\nPlayer ran out of moves. Player lost!\n\n";
}

/*********************************************************************
** Function: learn
** Description: provides details about the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Menu::learn()
{
        cout << "The objective of the game is to find the \'Key\' item and\n";
        cout << "bring it to the truck. You are trying to get out of the factory.\n\n";
        cout << "There are 6 spaces, with 5 types:\n";
        cout << " -> Office\n -> Mess Hall\n -> Floor\n -> Bathroom\n -> Loading Bay\n\n";
        cout << "To make things easier for you, the TA, the key is in the bathroom and\n";
        cout << "the truck is in the loading bay.\n\n";
        cout << "You only get 10 moves to complete this objective. Inspecting objects\n";
        cout << "in an area does not count as a move.\n\n";
}
