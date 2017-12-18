/*********************************************************************
** Program Filename: main_menu.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: main menu implementation
** Input: none
** Output: none
*********************************************************************/

#include "main_menu.hpp"

/*********************************************************************
** Function: Start
** Description: starts menu
** Parameters:  none
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
        while (choice != 3);
}


/*********************************************************************
** Function: set choice
** Description: sets users choice
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Main_Menu::set_choice()
{
	cout <<"\n\t:::Main:::\n\n";

	cout << "1) Stack\n";
	cout << "2) Queue\n";
	cout << "3) Quit\n";

	choice = facilitateIntInput(1,4);
}

/*********************************************************************
** Function: run chosen operation
** Description: runs function that user chose
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Main_Menu::run_chosen_operation()
{
        switch(choice)
        {

                case 1:
                        sub_menu = new Stack;
                        sub_menu->start();
			delete sub_menu;
			sub_menu = NULL;
                        break;
                case 2:
                        sub_menu = new Deque_Menu;
                        sub_menu->start();
			delete sub_menu;
			sub_menu = NULL;
                        break;

        }
}

/*********************************************************************
** Function: Main Menu constructor
** Description: creates Main menu
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Main_Menu::Main_Menu() : Menu()
{
	sub_menu = NULL;
}

/*********************************************************************
** Function: Main Menu  destructor
** Description: destroys main menu
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Main_Menu::~Main_Menu()
{
        // left blank intentionally
}
