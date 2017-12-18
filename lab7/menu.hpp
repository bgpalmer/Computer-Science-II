/*********************************************************************
** Program Filename: menu.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: menu template class
** Input: none
** Output: none
*********************************************************************/


#ifndef MENU
#define MENU
#include <fstream>
#include <iostream>
#include "menu_functions.hpp"

using std::ofstream;
using std::ifstream;
using std::endl;
using std::cout;
using std::cin;

class Menu
{
protected:
        string filename;
        int num_ints_in_file;

        void set_key(int);
        int key;

        int choice;
        virtual void set_choice() = 0;
        virtual void run_chosen_operation() = 0;
        void generate_random_file(int);
        void create_static_data_textfile();
        int * get_textfile_data(ifstream &in, string filename);

public:
        virtual void start() = 0;
        Menu();
        virtual ~Menu();
};

#endif
