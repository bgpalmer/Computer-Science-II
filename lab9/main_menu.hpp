/*********************************************************************
** Program Filename: Main_Menu.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: main menu class
** Input: none
** Output: none
*********************************************************************/


#ifndef MENUMAIN
#define MENUMAIN

#include "menu.hpp"
#include "queue.hpp"
#include "stack.hpp"

class Main_Menu : public Menu
{
private:
        Menu * sub_menu;
        void set_choice();
        void run_chosen_operation();
public:
        virtual void start();
        Main_Menu();
        ~Main_Menu();
};

#endif
