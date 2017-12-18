/*********************************************************************
** Program Filename: main_menu.cpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Main Menu submenu
** Input: None
** Output: None
*********************************************************************/

#include "main_menu.hpp"

/*********************************************************************
** Function: Run chosn operation
** Description: executes menu option that user chose
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Main_Menu::run_chosen_operation()
{
        switch(choice)
        {
                case 1:
                        sub_menu = new Linear_Menu;
                        sub_menu->start();
                        break;
                case 2:
                        sub_menu = new Sort_Menu;
                        sub_menu->start();
                        break;
                case 3:
                        sub_menu = new Binary_Menu;
                        sub_menu->start();
                        break;
        }
        delete sub_menu;
        sub_menu = NULL;
}

/*********************************************************************
** Function: set choice
** Description: sets choice member with users input
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Main_Menu::set_choice()
{
        cout << "\t:::Main Menu:::\n\n";
        cout << "1) Linear Search (p. 596)\n";
        cout << "2) Selection Sort (p. 611)\n";
        cout << "3) Binary Search (p. 599)\n";
        cout << "4) Exit\n";
        choice = facilitateIntInput(1,5);
}

/*********************************************************************
** Function: start
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Main_Menu::start()
{
        do
        {
                set_choice();
                run_chosen_operation();
        }
        while (choice != 4);
}

/*********************************************************************
** Function: Main_Menu
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Main_Menu::Main_Menu()
{
        sub_menu = NULL;
        choice = -1;
}

/*********************************************************************
** Function: Main Menu Destructor
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Main_Menu::~Main_Menu()
{
        // intentionally empty
}
