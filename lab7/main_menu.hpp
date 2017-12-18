/*********************************************************************
** Program Filename: main_menu.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: menu template class
** Input: none
** Output: none
*********************************************************************/


#ifndef MAINMENU
#define MAINMENU

#include <iostream>
#include "menu.hpp"
#include "linear_menu.hpp"
#include "binary_menu.hpp"
#include "sort_menu.hpp"
#include "search.hpp"
#include "selection_sort.hpp"

using std::endl;
using std::cout;
using std::cin;

class Main_Menu : public Menu
{
protected:
        Menu * sub_menu;
        virtual void set_choice();
        virtual void run_chosen_operation();
public:
        virtual void start();
        Main_Menu();
        virtual ~Main_Menu();
};

#endif
