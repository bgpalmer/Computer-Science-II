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
        virtual void set_choice() = 0;
        virtual void run_chosen_operation() = 0;
public:
        void start();
        Menu();
        virtual ~Menu();
};

#endif
