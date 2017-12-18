#ifndef MENUMAIN
#define MENUMAIN

#include "menu.hpp"
#include "stack_menu.hpp"
#include "queue_menu.hpp"


class Main_Menu : public Menu
{
private:
        Menu * sub_menu;
        virtual void set_choice();
        virtual void run_chosen_operation();
public:
        Main_Menu();
        virtual ~Main_Menu();
};

#endif
