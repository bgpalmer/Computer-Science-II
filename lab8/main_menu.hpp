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

#include "menu_functions.hpp"
#include "queue.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Main_Menu
{
private:
        Queue * queue;
        char choice;
        virtual void set_choice();
        virtual void run_chosen_operation();
        bool no_queue();
public:
        Main_Menu();
        virtual ~Main_Menu();
        void start();
};

#endif
