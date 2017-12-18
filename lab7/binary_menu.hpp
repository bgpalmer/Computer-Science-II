/*********************************************************************
** Program Filename: binary_menu.hpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Binary Menu submenu class header
** Input: None
** Output: None
*********************************************************************/

#ifndef BINARY
#define BINARY

#include "main_menu.hpp"

class Binary_Menu : public Menu
{
protected:
        virtual void run_chosen_operation();
        virtual void set_choice();

public:
        virtual void start();
        Binary_Menu();
        virtual ~Binary_Menu();
};

#endif
