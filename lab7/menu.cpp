/*********************************************************************
** Program Filename: menu.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: menu implementation
** Input: none
** Output: none
*********************************************************************/

#include "menu.hpp"

void Menu::set_key(int k)
{
        cout << "What number do you want to look for? (i.e. 0)" << endl;
        key = facilitateIntInput(0,k);
}

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
** Function: get_textfile_data
** Description: reads integers from a text file
** Parameters: ifstream object reference, string
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

int * Menu::get_textfile_data(ifstream &in, string filename)
{
        int * ptr = NULL;
        in.open(filename.c_str());

        if (in.is_open())
        {
                int count = 0;
                while (!in.eof())
                {
                        int test;
                        in >> test;
                        count++;
                }

                in.clear();

                // http://www.cplusplus.com/reference/istream/istream/seekg/
                // starts the stream to the beginning of the file again
                in.seekg(0,std::ios::beg);

                num_ints_in_file = count - 1;
                // second pass reads in the integers
                ptr = new int[num_ints_in_file];
                for (int i = 0; i < num_ints_in_file; i++)
                        in >> ptr[i];

                in.close();
                return ptr;
        }
        else
        {
                cout << "ERROR ERROR ERROR" << endl;
                return ptr;
        }
}

/*********************************************************************
** Function: generate_random_file
** Description: creates text file with list of random integers between 0 - 100
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Menu::generate_random_file(int num)
{
        ofstream out;
        string filename = "random_numbers.txt";
        out.open(filename.c_str());

        if (out.is_open())
        {
                for (int i = 0; i < num; i++)
                        out << getRandomPosInt(101) << " ";

                out.close();
        }
        else
                cout << "ERROR: CREATING RANDOM NUMBER TEXTFILE\n";
}

/*********************************************************************
** Function: create static data textfile
** Description: creates textfile with list of 50 integers in descending order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Menu::create_static_data_textfile()
{
        ofstream out;
        string filename = "static_numbers.txt";
        out.open(filename.c_str());
        if (out.is_open())
        {
                for (int i = 50; i >= 0; i--)
                        out << i << " ";

                out.close();
        }
        else
        {
                cout << "ERROR: COULD NOT OPEN STATIC DATA TEXTFILE";
        }
}
