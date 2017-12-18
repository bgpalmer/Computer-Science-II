#ifndef QUEUEMENU
#define QUEUEMENU

#include "queue.hpp"
#include "menu.hpp"

class Queue_Menu : public Menu
{
private:
        Queue * queue;
protected:
        virtual void run_chosen_operation();
        virtual void set_choice();
public:
        Queue_Menu();
        virtual ~Queue_Menu();
        bool no_queue();
};

#endif
