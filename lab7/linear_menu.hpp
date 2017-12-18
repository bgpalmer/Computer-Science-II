/*********************************************************************
** Program Filename: linear_menu.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: linear menu template class
** Input: none
** Output: none
*********************************************************************/


#ifndef LINEARMENU
#define LINEARMENU

#include <iostream>
#include "main_menu.hpp"

using std::endl;
using std::cout;
using std::cin;


class Linear_Menu : public Menu
{
protected:
        virtual void set_choice();
        virtual void run_chosen_operation();

public:
        virtual void start();
        Linear_Menu();
        virtual ~Linear_Menu();
};

#endif
