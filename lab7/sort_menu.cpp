/*********************************************************************
** Program Filename: sort_menu.cpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Binary Menu submenu
** Input: None
** Output: None
*********************************************************************/

#include "sort_menu.hpp"


/*********************************************************************
** Function: Sort_Menu constructor
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Sort_Menu::Sort_Menu()
{
        // intentionally blank
}

/*********************************************************************
** Function: Sort_Menu destructor
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Sort_Menu::~Sort_Menu()
{
        // intentionally blank
}

/*********************************************************************
** Function: set_choice
** Description: sets user choice
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Sort_Menu::set_choice()
{
        cout << "\t:::Main Menu -> Sort Menu:::\n\n";
        cout << "1) Sort Static File\n";
        cout << "2) Sort Random File\n";
        cout << "3) Quit\n";

        choice = facilitateIntInput(1,4);
}

/*********************************************************************
** Function: start
** Description: starts sort sub menu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Sort_Menu::start()
{
        do
        {
                set_choice();
                run_chosen_operation();
        }
        while (choice != 3);
}

/*********************************************************************
** Function: run_chosen_operation
** Description: runs users chosen menu option
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Sort_Menu::run_chosen_operation()
{
        int * data = NULL;
        ifstream in;
        switch(choice)
        {
                case 1:
                        create_static_data_textfile();
                        data = get_textfile_data(in, "static_numbers.txt");
                        sort(data, num_ints_in_file);
                        display_sort(data, num_ints_in_file);
                        break;
                case 2:
                        generate_random_file(100);
                        data = get_textfile_data(in, "random_numbers.txt");
                        sort(data, num_ints_in_file);
                        display_sort(data, num_ints_in_file);
                        break;
        }
        delete [] data;
        data = NULL;
}
