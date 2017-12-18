/*********************************************************************
** Program Filename: linear_menu.cpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Linear Menu implementation
** Input: None
** Output: None
*********************************************************************/

#include "linear_menu.hpp"

void Linear_Menu::set_choice()
{
        cout << "\n\n\t:::Main Menu -> Linear Menu:::\n\n";
        cout << "1) front_data.txt\n";
        cout << "2) back_data.txt\n";
        cout << "3) middle_data.txt\n";
        cout << "4) Exit\n";

        choice = facilitateIntInput(1,5);
}

/*********************************************************************
** Function: run_chosen_operation
** Description: has user choose function to run, then executes it
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: any allocated, read-in data should be deallocated before exiting
** Return: none
*********************************************************************/

void Linear_Menu::run_chosen_operation()
{
        int * data = NULL;
        ifstream in;
        switch(choice)
        {
                case 1:
                        filename = "front_data.txt";
                        data = get_textfile_data(in, filename);
                        set_key(100);
                        cout << "Position: " << linear_search(data, num_ints_in_file, key) << "\n";
                        break;
                case 2:
                        filename = "back_data.txt";
                        data = get_textfile_data(in, filename);
                        set_key(100);
                        cout << "Position: " << linear_search(data, num_ints_in_file, key) << "\n";
                        break;
                case 3:
                        filename = "middle_data.txt";
                        data = get_textfile_data(in, filename);
                        set_key(100);
                        cout << "Position: " << linear_search(data, num_ints_in_file, key) << "\n";
                        break;
        }
        delete [] data;
        data = NULL;
}

/*********************************************************************
** Function: Linear_Menu constructor
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Linear_Menu::Linear_Menu()
{
        choice = -1;
        filename = "";
}

/*********************************************************************
** Function: Linear_Menu destructor
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Linear_Menu::~Linear_Menu()
{
        // intentionally blank
}

/*********************************************************************
** Function: start
** Description: provides user with menu option then executes users choice
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: should not exit until users direction
** Return: none
*********************************************************************/

void Linear_Menu::start()
{
        do
        {
                set_choice();
                run_chosen_operation();
        }
        while (choice != 4);
}
