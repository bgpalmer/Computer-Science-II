#ifndef STACKMENU
#define STACKMENU

#include "stack.hpp"
#include "menu.hpp"

class Stack_Menu : public Menu
{
private:
        Stack * stack;
protected:
        virtual void run_chosen_operation();
        virtual void set_choice();
public:
        Stack_Menu();
        virtual ~Stack_Menu();
        bool no_stack();
};

#endif
