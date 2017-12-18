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

#include <iostream>
#include "menu_functions.hpp"

using std::endl;
using std::cout;
using std::cin;

class Menu
{
protected:
        int choice;
public:
        virtual void start() = 0;
        Menu();
        virtual ~Menu();
};

#endif
