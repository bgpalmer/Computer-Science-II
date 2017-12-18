/*********************************************************************
** Program Filename: sort_menu.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: sort menu template
** Input: none
** Output: none
*********************************************************************/


#ifndef SORTMENU
#define SORTMENU

#include <iostream>
#include "main_menu.hpp"
#include "selection_sort.hpp"

using std::endl;
using std::cout;
using std::cin;

class Sort_Menu : public Menu
{
protected:
        virtual void set_choice();
        virtual void run_chosen_operation();

public:
        void start();
        Sort_Menu();
        virtual ~Sort_Menu();
};

#endif
