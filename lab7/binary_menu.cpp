/*********************************************************************
** Program Filename: binary_menu.cpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Binary Menu submenu
** Input: None
** Output: None
*********************************************************************/

#include "binary_menu.hpp"

void Binary_Menu::set_choice()
{
        cout << "\t:::Main Menu -> Binary Search:::\n\n";
        cout << "1) Random File\n\nGenerates one-hundred numbers between 0 - 100. User then chooses\nwhat number to search for.\n\n";
        cout << "2) Static File\n\nBinary search of non-random text file, will produce same reults\neach time.\n\n";
        cout << "3) Exit\n";
        choice = facilitateIntInput(1,4);
}


/*********************************************************************
** Function: run chosen operation
** Description: either performs a binary search on a list of randomly generated integers
** Parameters: none
** Pre-Conditions: user decides which function to run
** Post-Conditions: Any data read in should be deallocated
** Return: none
*********************************************************************/
void Binary_Menu::run_chosen_operation()
{
        ifstream in;
        int * data = NULL;
        switch(choice)
        {
                case 1:
                        filename = "random_numbers.txt";
                        generate_random_file(100);
                        set_key(100);
                        data = get_textfile_data(in, filename);
                        selection_sort(data, num_ints_in_file);
                        cout << "\n\n";
                        display_sort(data,num_ints_in_file);
                        cout << "\n\n";
                        cout << "\nPosition: " << binary_search(data, num_ints_in_file, key) << "\n\n\n";
                        break;
                case 2:
                        filename = "static_numbers.txt";
                        create_static_data_textfile();
                        set_key(50);
                        data = get_textfile_data(in, filename);
                        selection_sort(data, num_ints_in_file);
                        cout << "\n\n";
                        display_sort(data,num_ints_in_file);
                        cout << "\n\n";
                        cout << "\nPosition: " << binary_search(data, num_ints_in_file, key) << "\n\n\n";
                        break;
        }
        delete [] data;
        data = NULL;
}

/*********************************************************************
** Function: start
** Description: has user choose function to run, then executes it
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: should not move past loop until user types 3
** Return: none
*********************************************************************/

void Binary_Menu::start()
{
        do
        {
                set_choice();
                run_chosen_operation();
        }
        while (choice != 3);
}

/*********************************************************************
** Function: Binary_Menu constructor
** Description: sub menu for user to run function in different scenarios
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Binary_Menu::Binary_Menu()
{
        choice = -1;
}

/*********************************************************************
** Function: Binary_Menu destructor
** Description: none
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Binary_Menu::~Binary_Menu()
{
        // intentionally blank
}
