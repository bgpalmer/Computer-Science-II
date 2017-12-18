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
#include "world.hpp"

using std::endl;
using std::cout;
using std::cin;

class Menu
{
protected:
        int choice;
        bool done;

        void learn();
        void start();
public:
        void main_menu();
        Menu();
        ~Menu();
};

#endif
