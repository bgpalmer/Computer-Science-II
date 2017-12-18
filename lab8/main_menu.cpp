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

	cout << "(a)  Enter a value to be added to the queue\n";
	cout << "(b)  Display first node (front) value\n";
	cout << "(c)  Remove first node (front) value\n";
	cout << "(d)  Display the queue contents\n";
	cout << "(x)  Exit\n";

	choice = facilitateCharacterInput();
}

bool Main_Menu::no_queue()
{
	if (queue == NULL)
	{
		cout << "Queue has not been created yet, please add a value first\n\n";
		return true;
	}
	else
		return false;
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
	int input;
	switch(choice)
	{
		case 'A':
			if (queue == NULL)
				queue = new Queue;
			input = facilitateIntInput(0,30001);
			queue->add_back(input);
			break;
		case 'B':
			if (no_queue() == false)
				cout << " >>> " << queue->get_front() << endl;
			break;
		case 'C':
			if (no_queue() == false)
				cout << " >>> " << queue->remove_front() << "\n";
			break;
		case 'D':
			if (no_queue() == false)
			{
				cout << " >>> ";
				queue->display();
			}
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

Main_Menu::Main_Menu()
{
	queue = NULL;
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
        delete queue;
}


void Main_Menu::start()
{
	do
	{
		set_choice();
		run_chosen_operation();
	}
	while (choice != 'X');
}
