#ifndef SPACE
#define SPACE
#include <iostream>
#include <string>
#include "helper_functions.hpp"
#include "item.hpp"
#include "campfire.hpp"
#include "pack.hpp"
using std::string;
using std::cout;
// enum type {FIELD, TOWN, FOREST, RIVER, CAVE};

class World;
class Space
{
protected:
        friend class World;
        string name;
        int choice;
        Campfire * campfire;

        Space * town;
        Space * clockwise;
        Space * counter_clockwise;
        Space * out;

        Pack * backpack;

        // virtual void set_choice() = 0;
        // virtual Item * run_operation() = 0;

public:
        Space(string t, Space * cw, Space * c_cw, Space * out, Space * town);
        Space(string t);
        ~Space();

        void menu();
        string get_type();
        bool light_campfire();
        bool campfire_is_lit();

        Space * get_clockwise();
        Space * get_counter_clockwise();
        Space * get_town();
};

#endif
