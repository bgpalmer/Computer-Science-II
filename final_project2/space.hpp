/*********************************************************************
** Program Filename: space.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: space class template
** Input: none
** Output: none
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <iostream>
#include "helper_functions.hpp"
#include "stack.hpp"
#include "machine.hpp"
//#include "battery.hpp"
using std::cout;
using std::string;
class Item;

class Space
{
protected:
        friend class World;
        string type;
        bool power_switch;

        Space * up;
        Space * down;
        Space * left;
        Space * right;

public:
        virtual bool inspect(Stack *) = 0; // special action

        Space(string name);
        virtual ~Space();
        void flip_switch();
        string get_type();

        void inspect_item(Item *);

        Space * get_up();
        Space * get_down();
        Space * get_left();
        Space * get_right();

        void set_up(Space *);
        void set_down(Space *);
        void set_right(Space *);
        void set_left(Space *);

        void set_orthogs(Space ***, int, int);

};

#endif
